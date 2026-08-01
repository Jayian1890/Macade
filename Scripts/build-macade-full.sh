#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
FBNEO_DIR="$ROOT_DIR/Sources/FightcadeFBNeo"
FBNEO_OUTPUT="$FBNEO_DIR/fbneosdlarm64"
RUNTIME_BINARY="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/fbneo/macfbneo"
SNES9X_DIR="$ROOT_DIR/Sources/FightcadeSnes9x"
SNES9X_OUTPUT="$SNES9X_DIR/build/snes9x"
SNES9X_RUNTIME_BINARY="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/snes9x/snes9x"
DERIVED_DATA_DIR="$ROOT_DIR/.build/xcode"
BUILT_APP_PATH="$DERIVED_DATA_DIR/Build/Products/Debug/Macade.app"
APP_PATH="$SCRIPT_DIR/Macade.app"

cd "$FBNEO_DIR"
make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl

install -m 755 "$FBNEO_OUTPUT" "$RUNTIME_BINARY"

if [ -x "$SNES9X_DIR/build-macade.sh" ]; then
  cd "$SNES9X_DIR"
  ./build-macade.sh
  install -m 755 "$SNES9X_OUTPUT" "$SNES9X_RUNTIME_BINARY"
else
  printf 'Snes9x native runtime source is not present; skipping Snes9x build.\n'
fi

cd "$ROOT_DIR"
xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' -derivedDataPath "$DERIVED_DATA_DIR" build

rm -rf "$APP_PATH"
cp -R "$BUILT_APP_PATH" "$APP_PATH"

printf '\nMacade app: %s\n' "$APP_PATH"
printf 'Open with: open %q\n' "$APP_PATH"
