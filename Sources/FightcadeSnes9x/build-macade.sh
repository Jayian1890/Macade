#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
UPSTREAM_DIR="$ROOT_DIR/upstream/src"
LIBRETRO_DIR="$UPSTREAM_DIR/libretro"
BUILD_DIR="$ROOT_DIR/build"
FBNEO_SRC_DIR="$ROOT_DIR/../FightcadeFBNeo/src"
GGPO_NATIVE_SRC_DIR="$FBNEO_SRC_DIR/dep/ggponet-native/src"
ARCHIVE_PATH="$BUILD_DIR/libsnes9x_libretro.a"
OUTPUT_PATH="$BUILD_DIR/snes9x"

CXX_BIN="${CXX:-c++}"
NCPU="$(sysctl -n hw.ncpu 2>/dev/null || echo 4)"

mkdir -p "$BUILD_DIR"

cleanup_libretro() {
  make -C "$LIBRETRO_DIR" platform=osx STATIC_LINKING=1 LTO= GIT_VERSION='" d56c95d"' clean >/dev/null
}

cleanup_libretro
make -C "$LIBRETRO_DIR" platform=osx STATIC_LINKING=1 LTO= GIT_VERSION='" d56c95d"' -j"$NCPU"
cp "$LIBRETRO_DIR/snes9x_libretro.dylib" "$ARCHIVE_PATH"
cleanup_libretro

COMMON_FLAGS=(
  -std=c++17
  -O2
  -DNDEBUG
  -Wall
  -Wextra
  -Wno-unused-parameter
  -I"$UPSTREAM_DIR/libretro"
  -I"$UPSTREAM_DIR"
  -I"$FBNEO_SRC_DIR/macade"
  -I"$FBNEO_SRC_DIR/dep/ggponet-native/include"
)

mkdir -p "$BUILD_DIR/ggponet-native"

GGPO_OBJECTS=()
for source in "$GGPO_NATIVE_SRC_DIR"/*.cpp; do
  object="$BUILD_DIR/ggponet-native/$(basename "${source%.cpp}.o")"
  "$CXX_BIN" "${COMMON_FLAGS[@]}" -c "$source" -o "$object"
  GGPO_OBJECTS+=("$object")
done

"$CXX_BIN" "${COMMON_FLAGS[@]}" -c "$ROOT_DIR/macade_runner.cpp" -o "$BUILD_DIR/macade_runner.o"
"$CXX_BIN" "${COMMON_FLAGS[@]}" -c "$ROOT_DIR/macade_audio.cpp" -o "$BUILD_DIR/macade_audio.o"
"$CXX_BIN" "${COMMON_FLAGS[@]}" -c "$ROOT_DIR/macade_quark.cpp" -o "$BUILD_DIR/macade_quark.o"
"$CXX_BIN" "${COMMON_FLAGS[@]}" -c "$FBNEO_SRC_DIR/macade/macade_embedded.cpp" -o "$BUILD_DIR/macade_embedded.o"
"$CXX_BIN" "$BUILD_DIR/macade_runner.o" "$BUILD_DIR/macade_audio.o" "$BUILD_DIR/macade_quark.o" "$BUILD_DIR/macade_embedded.o" "${GGPO_OBJECTS[@]}" "$ARCHIVE_PATH" -o "$OUTPUT_PATH" -lm -lz -framework AudioToolbox

printf 'Built Snes9x runner: %s\n' "$OUTPUT_PATH"
