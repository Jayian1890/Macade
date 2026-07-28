// SDL_Sound module

#include <SDL.h>
#include "burner.h"
#include "aud_dsp.h"
#include <math.h>

static unsigned int nSoundFps;

extern int delay_ticks(int ticks);

int nSDLVolume = SDL_MIX_MAXVOLUME;
int (*GetNextSound)(int);               // Callback used to request more sound

static SDL_AudioSpec audiospec;

static short* SDLAudBuffer;
static int nSDLPlayPos;
static int nSDLFillSeg;
static int nAudLoopLen;

void audiospec_callback(void* /* data */, Uint8* stream, int len)
{
#ifdef BUILD_SDL2
	SDL_memset(stream, 0, len);
#endif
	int end = nSDLPlayPos + len;
	if (end > nAudLoopLen)
	{
		SDL_MixAudio(stream, (Uint8*)SDLAudBuffer + nSDLPlayPos, nAudLoopLen - nSDLPlayPos, nSDLVolume);
		end -= nAudLoopLen;
		SDL_MixAudio(stream + nAudLoopLen - nSDLPlayPos, (Uint8*)SDLAudBuffer, end, nSDLVolume);
		nSDLPlayPos = end;
	}
	else
	{
		SDL_MixAudio(stream, (Uint8*)SDLAudBuffer + nSDLPlayPos, len, nSDLVolume);
		nSDLPlayPos = end;

		if (nSDLPlayPos == nAudLoopLen)
		{
			nSDLPlayPos = 0;
		}
	}
}

static int SDLSoundGetNextSoundFiller(int)                          // int bDraw
{
	if (nAudNextSound == NULL)
	{
		return 1;
	}
	memset(nAudNextSound, 0, nAudSegLen << 2);                  // Write silence into the buffer

	return 0;
}

static int SDLSoundBlankSound()
{
	if (nAudNextSound)
	{
		memset(nAudNextSound, 0, nAudSegLen << 2);
	}
	return 0;
}

#define WRAP_INC(x) { x++; if (x >= nAudSegCount[0]) x = 0; }

static int SDLSoundCheck()
{
	int nPlaySeg, nFollowingSeg;

	if (!bAudPlaying)
		return 1;

	// Since the SDL buffer is smaller than a segment, only fill the buffer up to the start of the currently playing segment
	nPlaySeg = nSDLPlayPos / (nAudSegLen << 2) - 1;

	if (nPlaySeg >= nAudSegCount[0])
	{
		nPlaySeg -= nAudSegCount[0];
	}
	if (nPlaySeg < 0)
	{
		nPlaySeg = nAudSegCount[0] - 1;
	}

	if (nSDLFillSeg == nPlaySeg) {
		//	delay_ticks(1);
			return 0;
		}

	// work out which seg we will fill next
	nFollowingSeg = nSDLFillSeg;
	WRAP_INC(nFollowingSeg);

	while (nSDLFillSeg != nPlaySeg)
	{
		int bDraw;

		bDraw = 1;	// Macade: the SDL2 audio loop otherwise advances frames without painting video.
		if (GetNextSound(bDraw)) return 1;                  // get more sound into nAudNextSound

		if (nAudDSPModule[0])
		{
			DspDo(nAudNextSound, nAudSegLen);
		}

		memcpy((char*)SDLAudBuffer + nSDLFillSeg * (nAudSegLen << 2), nAudNextSound, nAudSegLen << 2);

		nSDLFillSeg = nFollowingSeg;
		WRAP_INC(nFollowingSeg);
	}

	return 0;
}

static int SDLSoundExit()
{
	DspExit();
	SDL_CloseAudio();

	free(SDLAudBuffer);
	SDLAudBuffer = NULL;

	free(nAudNextSound);
	nAudNextSound = NULL;

	return 0;
}

INT32 AudSetCallback(INT32 (*pCallback)(INT32))
{
	if (pCallback == NULL)
	{
		GetNextSound = SDLSoundGetNextSoundFiller;
	}
	else
	{
		GetNextSound = pCallback;
	}
	return 0;
}

static int SDLSoundFrame()
{
	return SDLSoundCheck();
}

static int SDLSoundSetVolume();

static int SDLSoundInit()
{
	SDL_AudioSpec audiospec_req;
	int nSDLBufferSize;

	printf("SDLSoundInit (%dHz) (%dFPS)\n", nAudSampleRate[0], nAppVirtualFps);

	if (nAudSampleRate[0] <= 0)
	{
		return 1;
	}

	nSoundFps = nAppVirtualFps;
	nAudSegLen = (nAudSampleRate[0] * 100 + (nSoundFps >> 1)) / nSoundFps;
	nAudLoopLen = (nAudSegLen * nAudSegCount[0]) << 2;
	for (nSDLBufferSize = 64; nSDLBufferSize < (nAudSegLen >> 1); nSDLBufferSize <<= 1)
	{

	}

	audiospec_req.freq = nAudSampleRate[0];
	audiospec_req.format = AUDIO_S16;
	audiospec_req.channels = 2;
	audiospec_req.samples = nSDLBufferSize;
	audiospec_req.callback = audiospec_callback;

	SDLAudBuffer = (short*)malloc(nAudLoopLen);
	if (SDLAudBuffer == NULL)
	{
		printf("Couldn't malloc SDLAudBuffer\n");
		SDLSoundExit();
		return 1;
	}
	memset(SDLAudBuffer, 0, nAudLoopLen);

	nAudNextSound = (short*)malloc(nAudSegLen << 2);
	if (nAudNextSound == NULL)
	{
		SDLSoundExit();
		return 1;
	}

	nSDLPlayPos = 0;
	nSDLFillSeg = nAudSegCount[0] - 1;

	if (SDL_OpenAudio(&audiospec_req, &audiospec))
	{
		fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
		return 1;
	}
	DspInit();
	AudSetCallback(NULL);
	SDLSoundSetVolume();

	return 0;
}

static int SDLSoundPlay()
{
	SDL_PauseAudio(0);
	bAudPlaying = 1;

	return 0;
}

static int SDLSoundStop()
{
	SDL_PauseAudio(1);
	bAudPlaying = 0;

	return 0;
}

static int SDLSoundSetVolume()
{
	if (nAudVolume <= 0)
	{
		nSDLVolume = 0;
	}
	else if (nAudVolume >= 10000)
	{
		nSDLVolume = SDL_MIX_MAXVOLUME;
	}
	else
	{
		nSDLVolume = (SDL_MIX_MAXVOLUME * nAudVolume) / 10000;
	}

	return 0;
}

static int SDLGetSettings(InterfaceInfo* /* pInfo */)
{
	return 0;
}

struct AudOut AudOutSDL = { SDLSoundBlankSound, SDLSoundInit, SDLSoundExit, SDLSoundCheck, SDLSoundFrame, SDLSoundPlay, SDLSoundStop, SDLSoundSetVolume, SDLGetSettings, _T("SDL audio output") };
