// Run module
#include "burner.h"
#include "macade_embedded.h"

#include <sys/time.h>

static unsigned int nDoFPS = 0;
bool bAltPause = 0;

int bAlwaysDrawFrames = 0;

int counter;                                // General purpose variable used when debugging

static unsigned int nNormalLast = 0;        // Last value of GetTime()
static int          nNormalFrac = 0;        // Extra fraction we did

static bool bAppDoStep = 0;
bool        bAppDoFast = 0;
bool        bAppShowFPS = 0;
static int  nFastSpeed = 6;
static int  macadeRunFrameCount = 0;
static int  macadeRunGetSoundLogCount = 0;
static int  macadeRunIdleAudioLogCount = 0;
static const int kMacadeRunFrameOK = 0;
static const int kMacadeRunFrameQuit = 1;
static const int kMacadeRunFrameWait = 2;
static void MacadeSilenceNextSound()
{
	if (nAudNextSound != NULL && nAudSegLen > 0) memset(nAudNextSound, 0, nAudSegLen << 2);
}

UINT32 messageFrames = 0;
char lastMessage[MESSAGE_MAX_LENGTH];

/// Ingame gui
#ifdef BUILD_SDL2
extern SDL_Renderer* sdlRenderer;
extern void ingame_gui_start(SDL_Renderer* renderer);
#endif
extern int kNetGame;
extern int kNetSpectator;
extern void MacadeQuarkRunIdle(int ms);
extern bool MacadeQuarkIncrementFrame();
extern void MacadeDetectorUpdate();
extern int MacadeNetworkGetInput();
extern int MacadeSDLSoundCommitFrame();
struct GGPOSession;
extern GGPOSession* ggpo;
extern "C" bool ggpo_client_chat(GGPOSession*, char*);
extern void MacadeOverlaySetChatInput(const char* text, int active);
static const int kMacadeChatInputMax = 128;
static bool gMacadeChatActive = false;
static char gMacadeChatText[kMacadeChatInputMax + 1] = { 0 };

bool MacadeChatInputIsActive()
{
	return gMacadeChatActive;
}

#ifdef BUILD_SDL2
static void MacadeChatRefreshOverlay()
{
	MacadeOverlaySetChatInput(gMacadeChatText, gMacadeChatActive ? 1 : 0);
}

static void MacadeChatStart()
{
	gMacadeChatActive = true;
	gMacadeChatText[0] = 0;
	if (!MacadeEmbeddedEnabled()) SDL_StartTextInput();
	MacadeChatRefreshOverlay();
}

static void MacadeChatCancel()
{
	gMacadeChatActive = false;
	gMacadeChatText[0] = 0;
	if (!MacadeEmbeddedEnabled()) SDL_StopTextInput();
	MacadeChatRefreshOverlay();
}

static bool MacadeChatHasText()
{
	for (const char* cursor = gMacadeChatText; *cursor; cursor++) {
		if (*cursor != ' ' && *cursor != '\t') return true;
	}
	return false;
}

static void MacadeChatSubmit()
{
	if (MacadeChatHasText() && kNetGame && ggpo != NULL) {
		ggpo_client_chat(ggpo, gMacadeChatText);
	}
	MacadeChatCancel();
}

static void MacadeChatBackspace()
{
	size_t length = strlen(gMacadeChatText);
	if (length == 0) return;
	length--;
	while (length > 0 && ((unsigned char)gMacadeChatText[length] & 0xc0) == 0x80) length--;
	gMacadeChatText[length] = 0;
	MacadeChatRefreshOverlay();
}

static void MacadeChatAppend(const char* text)
{
	if (text == NULL || text[0] == 0) return;
	size_t length = strlen(gMacadeChatText);
	for (const char* cursor = text; *cursor && length < kMacadeChatInputMax; cursor++) {
		if (*cursor == '\r' || *cursor == '\n') continue;
		gMacadeChatText[length++] = *cursor;
	}
	gMacadeChatText[length] = 0;
	MacadeChatRefreshOverlay();
}

static void MacadeChatReplace(const char* text)
{
	gMacadeChatText[0] = 0;
	if (text != NULL && text[0] != 0) MacadeChatAppend(text);
	else MacadeChatRefreshOverlay();
}

extern "C" void MacadeChatBeginExternal()
{
	MacadeChatStart();
}

extern "C" void MacadeChatUpdateExternal(const char* text)
{
	gMacadeChatActive = true;
	MacadeChatReplace(text);
}

extern "C" void MacadeChatSubmitExternal(const char* text)
{
	gMacadeChatActive = true;
	MacadeChatReplace(text);
	MacadeChatSubmit();
}

extern "C" void MacadeChatCancelExternal()
{
	MacadeChatCancel();
}

static bool MacadeChatHandleKeyDown(const SDL_KeyboardEvent& key)
{
	if (gMacadeChatActive) {
		switch (key.keysym.sym) {
		case SDLK_RETURN:
		case SDLK_KP_ENTER:
			MacadeChatSubmit();
			break;
		case SDLK_ESCAPE:
			MacadeChatCancel();
			break;
		case SDLK_BACKSPACE:
			MacadeChatBackspace();
			break;
		default:
			break;
		}
		return true;
	}

	if (!kNetGame || key.repeat) return false;
	if ((key.keysym.mod & (KMOD_CTRL | KMOD_ALT | KMOD_GUI)) != 0) return false;
	if (key.keysym.sym == SDLK_t) {
		MacadeChatStart();
		return true;
	}
	return false;
}
#endif

#ifdef BUILD_SDL2
static void MacadeLockWindowAspect(const SDL_WindowEvent& windowEvent)
{
	static bool adjusting = false;
	if (adjusting || sdlRenderer == NULL) {
		return;
	}

	int logicalWidth = 0;
	int logicalHeight = 0;
	SDL_RenderGetLogicalSize(sdlRenderer, &logicalWidth, &logicalHeight);
	if (logicalWidth <= 0 || logicalHeight <= 0) {
		return;
	}

	int width = windowEvent.data1;
	int height = windowEvent.data2;
	if (width <= 0 || height <= 0) {
		return;
	}

	int expectedWidth = (height * logicalWidth) / logicalHeight;
	int expectedHeight = (width * logicalHeight) / logicalWidth;
	int adjustedWidth = width;
	int adjustedHeight = height;

	if (abs(expectedWidth - width) < abs(expectedHeight - height)) {
		adjustedWidth = expectedWidth;
	} else {
		adjustedHeight = expectedHeight;
	}

	if (adjustedWidth == width && adjustedHeight == height) {
		return;
	}

	SDL_Window* window = SDL_GetWindowFromID(windowEvent.windowID);
	if (window == NULL) {
		return;
	}

	adjusting = true;
	SDL_SetWindowSize(window, adjustedWidth, adjustedHeight);
	adjusting = false;
}
#endif

/// Save States
#ifdef BUILD_SDL2
static char* szSDLSavePath = NULL;
#endif

int bDrvSaveAll = 0;

// The automatic save
int StatedAuto(int bSave)
{
	static TCHAR szName[MAX_PATH] = _T("");
	int nRet;

#if defined(BUILD_SDL2) && !defined(SDL_WINDOWS)	
	if (szSDLSavePath == NULL)
	{
		szSDLSavePath = SDL_GetPrefPath("fbneo", "states");
	}

	snprintf(szName, MAX_PATH, "%s%s.fs", szSDLSavePath, BurnDrvGetText(DRV_NAME));

#else

	_stprintf(szName, _T("config/games/%s.fs"), BurnDrvGetText(DRV_NAME));

#endif

	if (bSave == 0)
	{
		printf("loading state %i %s\n", bDrvSaveAll, szName);
		nRet = BurnStateLoad(szName, bDrvSaveAll, NULL);		// Load ram
		if (nRet && bDrvSaveAll)
		{
			nRet = BurnStateLoad(szName, 0, NULL);				// Couldn't get all - okay just try the nvram
		}
	}
	else
	{
		printf("saving state %i %s\n", bDrvSaveAll, szName);
		nRet = BurnStateSave(szName, bDrvSaveAll);				// Save ram
	}

	return nRet;
}


/// End Save States

char fpsstring[20];

static time_t fpstimer;
static unsigned int nPreviousFrames;

static void DisplayFPSInit()
{
	nDoFPS = 0;
	fpstimer = 0;
	nPreviousFrames = nFramesRendered;
}

static void DisplayFPS()
{
	time_t temptime = clock();
	double fps = (double)(nFramesRendered - nPreviousFrames) * CLOCKS_PER_SEC / (temptime - fpstimer);
	if (bAppDoFast) {
		fps *= nFastSpeed + 1;
	}
	if (fpstimer && temptime - fpstimer > 0) { // avoid strange fps values
		sprintf(fpsstring, "%2.2lf", fps);
	}

	fpstimer = temptime;
	nPreviousFrames = nFramesRendered;
}


//crappy message system
void UpdateMessage(char* message)
{
	snprintf(lastMessage, MESSAGE_MAX_LENGTH, "%s", message);
	messageFrames = MESSAGE_MAX_FRAMES;
}

// define this function somewhere above RunMessageLoop()
void ToggleLayer(unsigned char thisLayer)
{
	nBurnLayer ^= thisLayer;                         // xor with thisLayer
	VidRedraw();
	VidPaint(0);
}


struct timeval start;

unsigned int GetTime(void)
{
	unsigned int ticks;
	struct timeval now;
	gettimeofday(&now, NULL);
	ticks = (now.tv_sec - start.tv_sec) * 1000 + (now.tv_usec - start.tv_usec) / 1000;
	return ticks;
}

// With or without sound, run one frame.
// If bDraw is true, it's the last frame before we are up to date, and so we should draw the screen
static int RunFrame(int bDraw, int bPause)
{
	if (!bDrvOkay)
	{
		return 1;
	}
	bool commitEmbeddedSpectatorAudio = MacadeEmbeddedEnabled() && kNetSpectator && bAudPlaying && !bPause && nAudNextSound != NULL;
	if (commitEmbeddedSpectatorAudio) pBurnSoundOut = nAudNextSound;

	if (bPause)
	{
		InputMake(false);
		VidPaint(0);
	}
	else
	{
		nFramesEmulated++;
		nCurrentFrame++;
		InputMake(true);
		if (kNetGame) {
			if (macadeRunFrameCount < 20 || macadeRunFrameCount % 120 == 0) {
				printf("Macade diagnostic: RunFrame=%d before-net bDraw=%d pause=%d emulated=%u rendered=%u\n", macadeRunFrameCount, bDraw, bPause, nFramesEmulated, nFramesRendered);
				fflush(stdout);
			}
			MacadeQuarkRunIdle(0);
			int networkStatus = MacadeNetworkGetInput();
			if (macadeRunFrameCount < 20 || macadeRunFrameCount % 120 == 0 || networkStatus != 0) {
				printf("Macade diagnostic: RunFrame=%d net-status=%d\n", macadeRunFrameCount, networkStatus);
				fflush(stdout);
			}
			if (networkStatus == 2) {
				return kMacadeRunFrameWait;
			}
			if (networkStatus != 0) {
				return kMacadeRunFrameQuit;
			}
		}
	}

	if (bDraw)
	{
		nFramesRendered++;
		int frameResult = VidFrame();
		if (macadeRunFrameCount < 20 || macadeRunFrameCount % 120 == 0) {
			printf("Macade diagnostic: RunFrame=%d bDraw=%d pause=%d VidFrame=%d\n", macadeRunFrameCount, bDraw, bPause, frameResult);
			fflush(stdout);
		}
		if (frameResult)
		{
		 	AudBlankSound();
		}
		int paintResult = VidPaint(0);                                              // paint the screen (no need to validate)
		if (macadeRunFrameCount < 20 || macadeRunFrameCount % 120 == 0) {
			printf("Macade diagnostic: RunFrame=%d VidPaint=%d\n", macadeRunFrameCount, paintResult);
			fflush(stdout);
		}
	}
	else
	{                                       // frame skipping
		pBurnDraw = NULL;                    // Make sure no image is drawn
		BurnDrvFrame();
		if (macadeRunFrameCount < 20 || macadeRunFrameCount % 120 == 0) {
			printf("Macade diagnostic: RunFrame=%d bDraw=%d pause=%d skipped paint\n", macadeRunFrameCount, bDraw, bPause);
			fflush(stdout);
		}
	}
	if (!bPause && kNetGame && !MacadeQuarkIncrementFrame()) {
		return kMacadeRunFrameQuit;
	}
	if (!bPause && kNetGame) {
		MacadeDetectorUpdate();
	}
	if (commitEmbeddedSpectatorAudio) MacadeSDLSoundCommitFrame();
	macadeRunFrameCount++;

	if (bAppShowFPS) {
		if (nDoFPS < nFramesRendered) {
			DisplayFPS();
			nDoFPS = nFramesRendered + 30;
		}
	}

	return kMacadeRunFrameOK;
}

// Callback used when DSound needs more sound
static int RunGetNextSound(int bDraw)
{
	if (macadeRunGetSoundLogCount < 20 || macadeRunGetSoundLogCount % 120 == 0) {
		printf("Macade diagnostic: RunGetNextSound=%d bDraw=%d audPlaying=%d next=%p segLen=%d\n", macadeRunGetSoundLogCount, bDraw, bAudPlaying, nAudNextSound, nAudSegLen);
		fflush(stdout);
	}
	macadeRunGetSoundLogCount++;

	if (nAudNextSound == NULL)
	{
		return 1;
	}

	if (bRunPause)
	{
		if (bAppDoStep)
		{
			int frameStatus = RunFrame(bDraw, 0);
			if (frameStatus == kMacadeRunFrameQuit) return 1;
			if (frameStatus == kMacadeRunFrameWait) { MacadeSilenceNextSound(); return 0; }
			memset(nAudNextSound, 0, nAudSegLen << 2);                                        // Write silence into the buffer
		}
		else
		{
			int frameStatus = RunFrame(bDraw, 1);
			if (frameStatus == kMacadeRunFrameQuit) return 1;
			if (frameStatus == kMacadeRunFrameWait) { MacadeSilenceNextSound(); return 0; }
		}

		bAppDoStep = 0;                                                   // done one step
		return 0;
	}

	if (bAppDoFast)
	{                                            // do more frames
		for (int i = 0; i < nFastSpeed; i++)
		{
			int frameStatus = RunFrame(0, 0);
			if (frameStatus == kMacadeRunFrameQuit) return 1;
			if (frameStatus == kMacadeRunFrameWait) { MacadeSilenceNextSound(); return 0; }
		}
	}

	// Render frame with sound
	pBurnSoundOut = nAudNextSound;
	int frameStatus = RunFrame(bDraw, 0);
	if (frameStatus == kMacadeRunFrameQuit) return 1;
	if (frameStatus == kMacadeRunFrameWait) { MacadeSilenceNextSound(); return 0; }
	if (bAppDoStep)
	{
		memset(nAudNextSound, 0, nAudSegLen << 2);                // Write silence into the buffer
	}
	bAppDoStep = 0;                                              // done one step

	return 0;
}

int delay_ticks(int ticks)
{
//sdl_delay can take up to 10 - 15 ticks it doesnt guarentee below this
   int startTicks = 0;
   int endTicks = 0;
   int checkTicks = 0;

   startTicks=SDL_GetTicks();

   while (checkTicks <= ticks)
   {
      endTicks=SDL_GetTicks();
      checkTicks = endTicks - startTicks;
   }

   return ticks;
}
int RunIdle()
{
	int nTime, nCount;
	bool didNetIdle = false;

	bool useTimerDrivenEmbeddedSpectator = MacadeEmbeddedEnabled() && kNetSpectator;
	if (bAudPlaying && !useTimerDrivenEmbeddedSpectator)
	{
		// Run with sound
		int framesBeforeAudio = macadeRunFrameCount;
		int soundStatus = AudSoundCheck();
		if (macadeRunIdleAudioLogCount < 20 || macadeRunIdleAudioLogCount % 120 == 0 || soundStatus != 0) {
			printf("Macade diagnostic: RunIdle audio=%d status=%d fillFrames=%d rendered=%u\n", macadeRunIdleAudioLogCount, soundStatus, macadeRunFrameCount, nFramesRendered);
			fflush(stdout);
		}
		macadeRunIdleAudioLogCount++;
		if (soundStatus) return 1;
		if (!kNetGame) return 0;
		MacadeQuarkRunIdle(1);
		didNetIdle = true;
		if (macadeRunFrameCount != framesBeforeAudio) {
			nNormalLast = GetTime();
			nNormalFrac = 0;
			return 0;
		}
	}

	// Run without sound
	nTime = GetTime() - nNormalLast;
	nCount = (nTime * nAppVirtualFps - nNormalFrac) / 100000;
	if (nCount <= 0) {						// No need to do anything for a bit
		//delay_ticks(2);
		if (kNetGame && !didNetIdle) MacadeQuarkRunIdle(1);
		return 0;
	}

	nNormalFrac += nCount * 100000;
	nNormalLast += nNormalFrac / nAppVirtualFps;
	nNormalFrac %= nAppVirtualFps;

	if (nCount > 100) {						// Limit frame skipping
		nCount = 100;
	}
	if (bRunPause) {
		if (bAppDoStep) {					// Step one frame
			nCount = 10;
		}
		else {
			int frameStatus = RunFrame(1, 1);
			if (frameStatus == kMacadeRunFrameQuit) return 1;
			if (frameStatus == kMacadeRunFrameWait) return 0;					// Paused
			return 0;
		}
	}
	bAppDoStep = 0;


	if (bAppDoFast)
	{									// do more frames
		for (int i = 0; i < nFastSpeed; i++)
		{
			int frameStatus = RunFrame(0, 0);
			if (frameStatus == kMacadeRunFrameQuit) return 1;
			if (frameStatus == kMacadeRunFrameWait) return 0;
		}
	}

	if (!bAlwaysDrawFrames)
	{
		for (int i = nCount / 10; i > 0; i--)
		{              // Mid-frames
			int frameStatus = RunFrame(0, 0);
			if (frameStatus == kMacadeRunFrameQuit) return 1;
			if (frameStatus == kMacadeRunFrameWait) return 0;
		}
	}
	int frameStatus = RunFrame(1, 0);
	if (frameStatus == kMacadeRunFrameQuit) return 1;
	if (frameStatus == kMacadeRunFrameWait) return 0;                                  // End-frame
	// temp added for SDLFBA
	//VidPaint(0);
	return 0;
}

int RunReset()
{
	// Reset the speed throttling code
	nNormalLast = 0; nNormalFrac = 0;
	nNormalLast = GetTime();
	return 0;
}

int RunInit()
{
	printf("Macade diagnostic: RunInit start audOkay=%d audPlaying=%d segLen=%d\n", bAudOkay, bAudPlaying, nAudSegLen);
	fflush(stdout);
	gettimeofday(&start, NULL);
	DisplayFPSInit();
	// Try to run with sound
	AudSetCallback(RunGetNextSound);
	int soundPlayStatus = AudSoundPlay();
	printf("Macade diagnostic: RunInit sound-play status=%d audOkay=%d audPlaying=%d segLen=%d\n", soundPlayStatus, bAudOkay, bAudPlaying, nAudSegLen);
	fflush(stdout);

	RunReset();
	int autoStateStatus = StatedAuto(0);
	printf("Macade diagnostic: RunInit auto-state status=%d\n", autoStateStatus);
	fflush(stdout);
	return 0;
}

int RunExit()
{
	nNormalLast = 0;
	StatedAuto(1);
	return 0;
}

#ifndef BUILD_MACOS
// The main message loop
int RunMessageLoop()
{
	int quit = 0;

	RunInit();
	GameInpCheckMouse();                                                                     // Hide the cursor
	Uint32 macadeLoopStartTicks = SDL_GetTicks();
	int macadeIgnoredStartupQuits = 0;

	while (!quit)
	{
		MacadeEmbeddedPumpInput();
		SDL_Event event;
		Uint32 macadeElapsedTicks;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:                                        /* Windows was closed */
				macadeElapsedTicks = SDL_GetTicks() - macadeLoopStartTicks;
				printf("Macade diagnostic: SDL_QUIT received kNetGame=%d frames=%u elapsed=%u ignored=%d\n", kNetGame, nFramesRendered, macadeElapsedTicks, macadeIgnoredStartupQuits);
				fflush(stdout);
				if (kNetGame && macadeElapsedTicks < 5000 && macadeIgnoredStartupQuits < 4) {
					macadeIgnoredStartupQuits++;
					printf("Macade diagnostic: ignoring startup SDL_QUIT before first render\n");
					fflush(stdout);
					break;
				}
				quit = 1;
				break;

#ifdef BUILD_SDL2
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_RESIZED || event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
					MacadeLockWindowAspect(event.window);
				}
				break;

			case SDL_TEXTINPUT:
				if (gMacadeChatActive) MacadeChatAppend(event.text.text);
				break;
#endif

			case SDL_KEYDOWN:                                                // need to find a nicer way of doing this...
#ifdef BUILD_SDL2
				if (MacadeChatHandleKeyDown(event.key)) break;
#endif
				switch (event.key.keysym.sym)
				{
				case SDLK_F1:
					bAppDoFast = 1;
					break;
				case SDLK_F9:
					QuickState(0);
					break;
				case SDLK_F10:
					QuickState(1);
					break;
				case SDLK_F11:
					bAppShowFPS = !bAppShowFPS;
					break;
#ifdef BUILD_SDL2
				case SDLK_TAB:
					ingame_gui_start(sdlRenderer);
					break;
#endif
				default:
					break;
				}
				break;

			case SDL_KEYUP:                                                // need to find a nicer way of doing this...
#ifdef BUILD_SDL2
				if (gMacadeChatActive) break;
#endif
				switch (event.key.keysym.sym)
				{
				case SDLK_F1:
					bAppDoFast = 0;
					break;

				case SDLK_F12:
					quit = 1;
					break;

				default:
					break;
				}
				break;
			}
		}
		if (RunIdle()) quit = 1;
	}

	RunExit();

	return 0;
}

#endif
