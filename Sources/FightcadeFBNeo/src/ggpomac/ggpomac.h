#pragma once

/*
 * Native macOS facade for Fightcade's ggponet.dll exports.
 *
 * Keep this header limited to the public DLL-compatible API surface. The
 * implementation is native C++ and currently lives under src/macade.
 */

#ifndef __declspec
#if defined(__GNUC__) || defined(__clang__)
#define __declspec(x) __attribute__((visibility("default")))
#else
#define __declspec(x)
#endif
#endif

#ifndef __cdecl
#define __cdecl
#endif

#include "ggpoclient.h"

#define GGPOMAC_EXPORT_SURFACE_VERSION 1
