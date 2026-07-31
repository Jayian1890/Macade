
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046f780(void)

{
  FILE *_File;
  char local_110 [268];
  uint local_4;
  
  local_4 = DAT_00871720 ^ (uint)local_110;
  if (DAT_00ad735c == '\0') {
    _sprintf(local_110,"config\\%s.ini");
    _File = _fopen(local_110,"wt");
    if (_File != (FILE *)0x0) {
      _fprintf(_File,"// FB Alpha v%s --- Main Config File\n\n");
      _fprintf(_File,"// Don\'t edit this file manually unless you know what you\'re doing\n");
      _fprintf(_File,"// FB Alpha will restore default settings when this file is deleted\n");
      _fprintf(_File,"\n// The application version this file was saved from\n");
      _fprintf(_File,"nIniVersion 0x%06X",DAT_008761ec);
      _fprintf(_File,"\n\n\n");
      _fprintf(_File,
               "// --- emulation --------------------------------------------------------------\n");
      _fprintf(_File,"\n// If non-zero, use A68K for MC68000 emulation\n");
      _fprintf(_File,"bBurnUseASMCPUEmulation %d\n",(uint)DAT_00874f76);
      _fprintf(_File,"\n\n\n");
      _fprintf(_File,
               "// --- Video ------------------------------------------------------------------\n");
      _fprintf(_File,"\n// The display mode to use for fullscreen\n");
      _fprintf(_File,"nVidWidth %d\n",DAT_0087581c);
      _fprintf(_File,"nVidHeight %d\n",DAT_008758a8);
      _fprintf(_File,"nVidDepth %d\n");
      _fprintf(_File,
               "\n// Specify the refresh rate, 0 = default (changing this will not work with many video cards)\n"
              );
      _fprintf(_File,"nVidRefresh %d\n",DAT_00b1980c);
      _fprintf(_File,
               "\n// If non-zero, use the same fullscreen resolution as the original arcade game\n")
      ;
      _fprintf(_File,"bVidArcaderes %d\n",DAT_00b19830);
      _fprintf(_File,"\n// If non-zero, do not rotate the graphics for vertical games\n");
      _fprintf(_File,"nVidRotationAdjust %d\n",DAT_00b19834);
      _fprintf(_File,"\n// The preset resolutions appearing in the menu\n");
      _fprintf(_File,"VidPreset[0].nWidth %d\n",DAT_009965b0);
      _fprintf(_File,"VidPreset[0].nHeight %d\n",DAT_009965b4);
      _fprintf(_File,"VidPreset[1].nWidth %d\n",DAT_009965b8);
      _fprintf(_File,"VidPreset[1].nHeight %d\n",DAT_009965bc);
      _fprintf(_File,"VidPreset[2].nWidth %d\n",DAT_009965c0);
      _fprintf(_File,"VidPreset[2].nHeight %d\n");
      _fprintf(_File,"VidPreset[3].nWidth %d\n",DAT_009965c8);
      _fprintf(_File,"VidPreset[3].nHeight %d\n",DAT_009965cc);
      _fprintf(_File,"\n// Full-screen size (0 = use display mode variables)\n");
      _fprintf(_File,"nScreenSize %d\n",DAT_00ad7550);
      _fprintf(_File,"\n// Initial window size (0 = autosize)\n");
      _fprintf(_File,"nWindowSize %d\n");
      _fprintf(_File,"\n// Window position\n");
      _fprintf(_File,"nWindowPosX %d\n",DAT_008999dc);
      _fprintf(_File,"nWindowPosY %d\n",DAT_00899d34);
      _fprintf(_File,"\n// If non-zero, perform gamma correction\n");
      _fprintf(_File,"bDoGamma %d\n",DAT_00b18330);
      _fprintf(_File,"\n// If non-zero, use the video hardware to correct gamma\n");
      _fprintf(_File,"bVidUseHardwareGamma %d\n",DAT_008758cc);
      _fprintf(_File,"\n// If non-zero, don\'t fall back on software gamma correction\n");
      _fprintf(_File,"bHardwareGammaOnly %d\n",DAT_00898794);
      _fprintf(_File,"\n// Gamma to correct with\n");
      _fprintf(_File,"nGamma %lf\n",_DAT_009965a8);
      _fprintf(_File,"\n// If non-zero, allow stretching of the image to any size\n");
      _fprintf(_File,"bVidFullStretch %d\n",DAT_00b19818);
      _fprintf(_File,
               "\n// If non-zero, stretch the image to the largest size preserving aspect ratio\n");
      _fprintf(_File,"bVidCorrectAspect %d\n",DAT_008758b0);
      _fprintf(_File,"\n// If non-zero, try to use a triple buffer in fullscreen\n");
      _fprintf(_File,"bVidTripleBuffer %d\n");
      _fprintf(_File,"\n// If non-zero, try to synchronise blits with the display\n");
      _fprintf(_File,"bVidVSync %d\n",DAT_00b1981c);
      _fprintf(_File,
               "\n// Transfer method:  0 = blit from system memory / use driver/DirectX texture management;\n"
              );
      _fprintf(_File,
               "//                   1 = copy to a video memory surface, then use bltfast();\n");
      _fprintf(_File,"//                  -1 = autodetect for DirectDraw, equals 1 for Direct3D\n");
      _fprintf(_File,"nVidTransferMethod %d\n",DAT_008758d4);
      _fprintf(_File,"\n// If non-zero, draw scanlines to simulate a low-res monitor\n");
      _fprintf(_File,"bVidScanlines %d\n",DAT_00b19824);
      _fprintf(_File,"\n// Maximum scanline intensity\n");
      _fprintf(_File,"nVidScanIntensity %d\n",PTR_DAT_008758c0);
      _fprintf(_File,"\n// If non-zero, rotate scanlines and RGB effects for rotated games\n");
      _fprintf(_File,"bVidScanRotate %d\n",DAT_008758b8);
      _fprintf(_File,"\n// The selected blitter module\n");
      _fprintf(_File,"nVidSelect %d\n");
      _fprintf(_File,"\n// Options for the blitter modules\n");
      _fprintf(_File,"nVidBlitterOpt[0] %d\n",DAT_00b197e8);
      _fprintf(_File,"nVidBlitterOpt[1] %d\n",DAT_00b197ec);
      _fprintf(_File,"nVidBlitterOpt[2] %d\n",DAT_00b197f0);
      _fprintf(_File,"nVidBlitterOpt[3] %d\n",DAT_00b197f4);
      _fprintf(_File,"\n// The aspect ratio of the monitor\n");
      _fprintf(_File,"nVidScrnAspectX %d\n",DAT_008758e8);
      _fprintf(_File,"nVidScrnAspectY %d\n",DAT_008758ec);
      _fprintf(_File,"\n// If non-zero, force all games to use a 60Hz refresh rate\n");
      _fprintf(_File,"bForce60Hz %d\n",(uint)DAT_00b189ca);
      _fprintf(_File,
               "\n// If non-zero, skip frames when needed to keep the emulation running at full speed\n"
              );
      _fprintf(_File,"bAlwaysDrawFrames %d\n",DAT_00ad74d4);
      _fprintf(_File,"\n// If non-zero, use a placeholder image when no game is loaded\n");
      _fprintf(_File,"bVidUsePlaceholder %d\n",(uint)DAT_0087399e);
      _fprintf(_File,
               "\n// The filename of the placeholder image to use (empty filename = use built-in)\n"
              );
      _fprintf(_File,"szPlaceHolder %s\n",&DAT_00b19870);
      _fprintf(_File,"\n");
      _fprintf(_File,
               "// --- DirectDraw blitter module settings -------------------------------------\n");
      _fprintf(_File,"\n// If non-zero, draw scanlines at 50%% intensity\n");
      _fprintf(_File,"bVidScanHalf %d\n");
      _fprintf(_File,"\n");
      _fprintf(_File,
               "// --- Direct3D 7 blitter module settings -------------------------------------\n");
      _fprintf(_File,"\n// If non-zero, use bi-linear filtering to display the image\n");
      _fprintf(_File,"bVidBilinear %d\n",DAT_008758b4);
      _fprintf(_File,"\n// If non-zero, simulate slow phosphors (feedback)\n");
      _fprintf(_File,"bVidScanDelay %d\n",DAT_00b19828);
      _fprintf(_File,"\n// If non-zero, use bi-linear filtering for the scanlines\n");
      _fprintf(_File,"bVidScanBilinear %d\n",DAT_008758bc);
      _fprintf(_File,"\n// Feedback amount for slow phosphor simulation\n");
      _fprintf(_File,"nVidFeedbackIntensity %d\n",DAT_008758c8);
      _fprintf(_File,"\n// Oversaturation amount for slow phosphor simulation\n");
      _fprintf(_File,"nVidFeedbackOverSaturation %d\n",DAT_00b1982c);
      _fprintf(_File,"\n// Angle at wich the emulated screen is tilted (in radians)\n");
      _fprintf(_File,"fVidScreenAngle %lf\n",(double)_DAT_008758d8);
      _fprintf(_File,"\n// Angle of the sphere segment used for the 3D screen (in radians)\n");
      _fprintf(_File,"fVidScreenCurvature %lf\n",(double)_DAT_008758dc);
      _fprintf(_File,"\n// If non-zero, force 16 bit emulation even in 32-bit screenmodes\n");
      _fprintf(_File,"bVidForce16bit %d\n",DAT_008758d0);
      _fprintf(_File,"\n");
      _fprintf(_File,
               "// --- DirectX Graphics 9 blitter module settings -----------------------------\n");
      _fprintf(_File,"\n// The filter parameters for the cubic filter\n");
      _fprintf(_File,"dVidCubicB %lf\n",_DAT_00b19838);
      _fprintf(_File,"dVidCubicC %lf\n",_DAT_008758e0);
      _fprintf(_File,"\n\n\n");
      _fprintf(_File,
               "// --- Sound ------------------------------------------------------------------\n");
      _fprintf(_File,"\n// Sample rate\n");
      _fprintf(_File,"nAudSampleRate %d\n",DAT_00875704);
      _fprintf(_File,"\n// Number of frames in sound buffer (= sound lag)\n");
      _fprintf(_File,"nAudSegCount %d\n",DAT_0087570c);
      _fprintf(_File,"\n// DSP module to use for sound enhancement: 0 = none, 1 = low-pass filter\n"
              );
      _fprintf(_File,"nAudDSPModule %d\n",DAT_00b19fa4);
      _fprintf(_File,"\n// The order of PCM/ADPCM interpolation\n");
      _fprintf(_File,"nInterpolation %d\n",DAT_00877264);
      _fprintf(_File,"\n// The order of FM interpolation\n");
      _fprintf(_File,"nFMInterpolation %d\n",DAT_00b19710);
      _fprintf(_File,"\n\n\n");
      _fprintf(_File,
               "// --- UI ---------------------------------------------------------------------\n");
      _fprintf(_File,"\n// Filename of the active UI translation template\n");
      _fprintf(_File,"szLocalisationTemplate %s\n",&DAT_00b18210);
      _fprintf(_File,
               "\n// 1 = display pause/record/replay/kaillera icons in the upper right corner of the display\n"
              );
      _fprintf(_File,"nVidSDisplayStatus %d\n",DAT_00875810);
      _fprintf(_File,
               "\n// Minimum height (in pixels) of the font used for the Kaillera chat function (used for arcade resolution)\n"
              );
      _fprintf(_File,"nMinChatFontSize %d\n",DAT_00875818);
      _fprintf(_File,
               "\n// Maximum height (in pixels) of the font used for the Kaillera chat function (used for 1280x960 or higher).\n"
              );
      _fprintf(_File,"nMaxChatFontSize %d\n",DAT_00875814);
      _fprintf(_File,"\n// Make the menu modeless\n");
      _fprintf(_File,"bModelessMenu %d\n",(uint)DAT_00ad7517);
      _fprintf(_File,"\n// Minimum length of time to display the splash screen (in milliseconds)\n")
      ;
      _fprintf(_File,"nSplashTime %d\n",DAT_0089e21c);
      _fprintf(_File,"\n// If non-zero, load and save all ram (the state)\n");
      _fprintf(_File,"bDrvSaveAll %d\n");
      _fprintf(_File,"\n// The thread priority for the application. Do *NOT* edit this manually\n");
      _fprintf(_File,"nAppThreadPriority %d\n",DAT_00ad6f44);
      _fprintf(_File,
               "\n// If non-zero, process keyboard input even when the application loses focus\n");
      _fprintf(_File,"bAlwaysProcessKeyboardInput %d\n",(uint)DAT_00ad735d);
      _fprintf(_File,"\n// If non-zero, pause when the application loses focus\n");
      _fprintf(_File,"bAutoPause %d\n",DAT_0089aba4);
      _fprintf(_File,"\n// If non-zero, save the inputs for each game\n");
      _fprintf(_File,"bSaveInputs %d\n",(uint)DAT_0087726a);
      _fprintf(_File,"\n");
      _fprintf(_File,
               "// --- Load Game Dialog -------------------------------------------------------\n");
      _fprintf(_File,"\n// Load game dialog options\n");
      _fprintf(_File,"nLoadMenuShowX %d\n",DAT_00ad74bc);
      _fprintf(_File,"\n// The paths to search for rom zips (include trailing backslash)\n");
      _fprintf(_File,"szAppRomPaths[0] %s\n");
      _fprintf(_File,"szAppRomPaths[1] %s\n",&DAT_009966e4);
      _fprintf(_File,"szAppRomPaths[2] %s\n",&DAT_009967e8);
      _fprintf(_File,"szAppRomPaths[3] %s\n",&DAT_009968ec);
      _fprintf(_File,"szAppRomPaths[4] %s\n",&DAT_009969f0);
      _fprintf(_File,"szAppRomPaths[5] %s\n",&DAT_00996af4);
      _fprintf(_File,"szAppRomPaths[6] %s\n");
      _fprintf(_File,"szAppRomPaths[7] %s\n",s_roms__00996cfc);
      _fprintf(_File,"\n");
      _fprintf(_File,
               "// --- ggpo settings ---------------------------------------------------------\n");
      _fprintf(_File,"\n");
      _fprintf(_File,"nLatencySmoothing %d\n",DAT_00873998);
      _fprintf(_File,"\n\n\n");
      _fprintf(_File,
               "// --- miscellaneous ---------------------------------------------------------\n");
      _fprintf(_File,
               "\n// Player default controls, number is the index of the configuration in the input dialog\n"
              );
      _fprintf(_File,"nPlayerDefaultControls[0] %d\n",DAT_00996100);
      _fprintf(_File,"szPlayerDefaultIni[0] %s\n",&DAT_00b18398);
      _fprintf(_File,"nPlayerDefaultControls[1] %d\n",DAT_00996104);
      _fprintf(_File,"szPlayerDefaultIni[1] %s\n",&DAT_00b1849c);
      _fprintf(_File,"nPlayerDefaultControls[2] %d\n");
      _fprintf(_File,"szPlayerDefaultIni[2] %s\n",&DAT_00b185a0);
      _fprintf(_File,"nPlayerDefaultControls[3] %d\n",DAT_0099610c);
      _fprintf(_File,"szPlayerDefaultIni[3] %s\n",&DAT_00b186a4);
      _fprintf(_File,"\n\n\n");
      _fclose(_File);
      __security_check_cookie(local_4 ^ (uint)local_110);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_110);
  return;
}
