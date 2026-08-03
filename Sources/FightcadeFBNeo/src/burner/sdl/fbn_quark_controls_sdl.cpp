#include "burner.h"
#include "ggponet.h"
#include "macade_embedded.h"

extern GGPOSession *ggpo;

namespace {
int gReplayPaused = 0;
int gReplayFastForward = 0;
int gReplaySeekFrame = -1;

bool ReplayControlActive()
{
   return ggpo != NULL && kNetGame && kNetSpectator;
}

int ClampReplayFrame(int frame, int total)
{
   if (frame < 0) return 0;
   if (total > 0 && frame > total) return total;
   return frame;
}
}

void QuarkReplayPublishStatus()
{
   GGPOReplayStatus status{};
   if (!ReplayControlActive() || !ggpo_replay_get_status(ggpo, &status)) {
      MacadeEmbeddedSetReplayStatus(0, 0, 0, 0, 0, 0);
      return;
   }

   MacadeEmbeddedSetReplayStatus(
      status.current_frame,
      status.total_frames,
      status.buffered_frames,
      status.seekable,
      gReplayPaused,
      gReplayFastForward
   );
}

void QuarkReplayResetControls()
{
   gReplayPaused = 0;
   gReplayFastForward = 0;
   gReplaySeekFrame = -1;
   MacadeEmbeddedSetReplayStatus(0, 0, 0, 0, 0, 0);
}

void QuarkReplayApplyControls()
{
   if (!ReplayControlActive()) return;
   if (gReplaySeekFrame >= 0) {
      ggpo_replay_seek(ggpo, gReplaySeekFrame);
      gReplaySeekFrame = -1;
      gReplayPaused = 1;
      gReplayFastForward = 0;
   }
   bRunPause = gReplayPaused != 0;
   bAppDoFast = gReplayFastForward != 0;
   QuarkReplayPublishStatus();
}

void QuarkReplaySetPaused(int paused)
{
   if (!ReplayControlActive()) return;
   gReplayPaused = paused ? 1 : 0;
   if (gReplayPaused) gReplayFastForward = 0;
   QuarkReplayApplyControls();
}

void QuarkReplaySetFastForward(int enabled)
{
   if (!ReplayControlActive()) return;
   gReplayFastForward = enabled ? 1 : 0;
   if (gReplayFastForward) gReplayPaused = 0;
   QuarkReplayApplyControls();
}

void QuarkReplaySeek(int frame)
{
   if (!ReplayControlActive()) return;
   GGPOReplayStatus status{};
   if (!ggpo_replay_get_status(ggpo, &status) || !status.seekable) return;
   gReplaySeekFrame = ClampReplayFrame(frame, status.total_frames);
   gReplayPaused = 1;
   gReplayFastForward = 0;
}

void QuarkReplayStep(int delta)
{
   if (!ReplayControlActive()) return;
   GGPOReplayStatus status{};
   if (!ggpo_replay_get_status(ggpo, &status) || !status.seekable) return;
   gReplaySeekFrame = ClampReplayFrame(status.current_frame + delta, status.total_frames);
   gReplayPaused = 1;
   gReplayFastForward = 0;
}
