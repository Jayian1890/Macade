#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
FBNEO_DIR="$ROOT_DIR/Sources/FightcadeFBNeo"
FBNEO_OUTPUT="$FBNEO_DIR/fbneosdlarm64"
RUNTIME_BINARY="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/fbneo/macfbneo"

cd "$FBNEO_DIR"
make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl

install -m 755 "$FBNEO_OUTPUT" "$RUNTIME_BINARY"

cd "$ROOT_DIR"
xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build
