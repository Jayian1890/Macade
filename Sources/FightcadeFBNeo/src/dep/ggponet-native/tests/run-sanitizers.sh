#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)
FBNEO_SRC=$(CDPATH= cd -- "$ROOT/../.." && pwd)
BUILD_DIR=$(mktemp -d "${TMPDIR:-/tmp}/macade-ggponet-tests.XXXXXX")
trap 'rm -rf "$BUILD_DIR"' EXIT
CXX=${CXX:-clang++}

"$CXX" \
  -std=c++17 \
  -O1 \
  -g \
  -fsanitize=address,undefined \
  -fno-omit-frame-pointer \
  -I"$ROOT/include" \
  -I"$ROOT/src" \
  "$ROOT/tests/packet_hardening_tests.cpp" \
  "$ROOT/src/tcp_framing.cpp" \
  "$ROOT/src/udp_protocol.cpp" \
  "$ROOT/src/udp_protocol_compressed.cpp" \
  "$ROOT/src/udp_socket.cpp" \
  "$ROOT/src/poll_backend.cpp" \
  "$ROOT/src/game_input.cpp" \
  "$ROOT/src/logging.cpp" \
  -o "$BUILD_DIR/packet-hardening-tests"

ASAN_OPTIONS=detect_leaks=0 "$BUILD_DIR/packet-hardening-tests"

"$CXX" \
  -std=c++17 \
  -O1 \
  -g \
  -fsanitize=address,undefined \
  -fno-omit-frame-pointer \
  -I"$FBNEO_SRC/burner/sdl" \
  "$ROOT/tests/quark_command_tests.cpp" \
  "$FBNEO_SRC/burner/sdl/fbn_quark_command.cpp" \
  -o "$BUILD_DIR/quark-command-tests"

ASAN_OPTIONS=detect_leaks=0 "$BUILD_DIR/quark-command-tests"
