#include "burner.h"

#include <stdio.h>

extern int kNetGame;
extern int kNetSpectator;
extern int usejoy;
extern bool bSaveconfig;

INT32 Init_Joysticks(int p1_use_joystick);
int MacadeQuarkLoadStateIfAvailable();
bool MacadeQuarkSessionActive();
bool MacadeQuarkSessionRunning();
bool MacadeQuarkStreamInitialStateLoaded();
void MacadeQuarkRestoreNetworkFlags();
void MacadeQuarkRunIdle(int ms);
int MacadeNetworkInitInput();
int RunInit();
int RunIdle();
int RunExit();

static void MacadeRunEmbeddedSpectatorLoop()
{
	printf("Macade diagnostic: entering embedded spectator idle loop\n");
	fflush(stdout);
	RunInit();
	int waitCount = 0;
	while (MacadeQuarkSessionRunning() && !MacadeQuarkStreamInitialStateLoaded()) {
		MacadeQuarkRunIdle(10);
		int stateStatus = MacadeQuarkLoadStateIfAvailable();
		if (waitCount < 20 || waitCount % 100 == 0 || stateStatus == 0) {
			printf("Macade diagnostic: spectator idle wait=%d state=%d loaded=%d\n", waitCount, stateStatus, MacadeQuarkStreamInitialStateLoaded() ? 1 : 0);
			fflush(stdout);
		}
		waitCount++;
	}
	while (MacadeQuarkSessionRunning() && !RunIdle()) { }
	RunExit();
	printf("Macade diagnostic: returned from embedded spectator idle loop\n");
	fflush(stdout);
}

void DoGame(int gameToRun)
{
	printf("Macade diagnostic: DoGame enter index=%d net=%d\n", gameToRun, kNetGame);
	fflush(stdout);
	if (!DrvInit(gameToRun, 0)) {
		bool macadeQuarkActive = MacadeQuarkSessionActive();
		if (macadeQuarkActive) MacadeQuarkRestoreNetworkFlags();
		printf("Macade diagnostic: DoGame post-DrvInit net=%d spectator=%d quark=%d\n", kNetGame, kNetSpectator, macadeQuarkActive ? 1 : 0);
		fflush(stdout);

		bool macadeRunLoopAllowed = true;
		if (kNetGame || macadeQuarkActive) {
			int stateStatus = MacadeQuarkLoadStateIfAvailable();
			printf("Macade diagnostic: DoGame state load status=%d\n", stateStatus);
			fflush(stdout);
			if (macadeQuarkActive && kNetSpectator && stateStatus != 0) {
				printf("Macade diagnostic: spectator stream state unavailable before loop; continuing to poll\n");
				fflush(stdout);
			}
		}

		printf("Macade diagnostic: DoGame DrvInit ok index=%d net=%d\n", gameToRun, kNetGame);
		fflush(stdout);
		if (macadeRunLoopAllowed) {
			MediaInit();
			Init_Joysticks(usejoy);
			if (kNetGame || macadeQuarkActive) {
				int inputStatus = MacadeNetworkInitInput();
				printf("Macade diagnostic: DoGame net-input status=%d\n", inputStatus);
				fflush(stdout);
			}
			printf("Macade diagnostic: DoGame entering RunMessageLoop\n");
			fflush(stdout);
			if (macadeQuarkActive && kNetSpectator) MacadeRunEmbeddedSpectatorLoop();
			else RunMessageLoop();
			printf("Macade diagnostic: DoGame returned from RunMessageLoop\n");
			fflush(stdout);
		} else {
			printf("Macade diagnostic: spectator stream state unavailable; aborting run loop\n");
			fflush(stdout);
		}
	} else {
		printf("There was an error loading your selected game.\n");
		fflush(stdout);
	}

	if (bSaveconfig) ConfigAppSave();
	DrvExit();
	MediaExit();
}
