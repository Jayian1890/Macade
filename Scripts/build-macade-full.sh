#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
FBNEO_DIR="$ROOT_DIR/Sources/FightcadeFBNeo"
FBNEO_OUTPUT="$FBNEO_DIR/fbneosdlarm64"
RUNTIME_BINARY="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/fbneo/macfbneo"
DERIVED_DATA_DIR="$ROOT_DIR/.build/xcode"
BUILT_APP_PATH="$DERIVED_DATA_DIR/Build/Products/Debug/Macade.app"
APP_PATH="$SCRIPT_DIR/Macade.app"

cd "$FBNEO_DIR"
make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl

install -m 755 "$FBNEO_OUTPUT" "$RUNTIME_BINARY"

cd "$ROOT_DIR"
xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' -derivedDataPath "$DERIVED_DATA_DIR" build

rm -rf "$APP_PATH"
cp -R "$BUILT_APP_PATH" "$APP_PATH"

printf '\nMacade app: %s\n' "$APP_PATH"
printf 'Open with: open %q\n' "$APP_PATH"
