#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
FBNEO_DIR="$ROOT_DIR/Sources/FightcadeFBNeo"
FBNEO_OUTPUT="$FBNEO_DIR/fbneosdlarm64"
RUNTIME_BINARY="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/fbneo/macfbneo"
FBNEO_SDL_NAME="libSDL2-2.0.0.dylib"
FBNEO_SDL_RUNTIME="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/fbneo/$FBNEO_SDL_NAME"
FBNEO_SDL3_NAME="libSDL3.dylib"
FBNEO_SDL3_RUNTIME="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/fbneo/$FBNEO_SDL3_NAME"
SNES9X_DIR="$ROOT_DIR/Sources/FightcadeSnes9x"
SNES9X_OUTPUT="$SNES9X_DIR/build/snes9x"
SNES9X_RUNTIME_BINARY="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/snes9x/snes9x"
DERIVED_DATA_DIR="$ROOT_DIR/.build/xcode"
BUILT_APP_PATH="$DERIVED_DATA_DIR/Build/Products/Debug/Macade.app"
APP_PATH="$SCRIPT_DIR/Macade.app"
FLYCAST_RUNTIME_APP="$ROOT_DIR/Sources/MacadeApp/Resources/FightcadeRuntime/emulators/flycast/Flycast Dojo.app"
FLYCAST_RUNTIME_BINARY="$FLYCAST_RUNTIME_APP/Contents/MacOS/Flycast Dojo"

verify_arm64_file() {
  local binary="$1"
  local label="$2"
  if [ ! -f "$binary" ]; then
    printf 'Missing Mach-O file %s: %s\n' "$label" "$binary" >&2
    exit 1
  fi

  local architectures
  architectures="$(lipo -archs "$binary")"
  if [ "$architectures" != "arm64" ]; then
    printf '%s must be a thin arm64 binary, found: %s\n' "$label" "$architectures" >&2
    exit 1
  fi

  local uuid
  uuid="$(dwarfdump --uuid "$binary" | awk 'NR == 1 { print $2 }')"
  if [ -z "$uuid" ] || [ "$uuid" = "00000000-0000-0000-0000-000000000000" ]; then
    printf '%s must contain a nonzero LC_UUID load command.\n' "$label" >&2
    exit 1
  fi
}

verify_arm64_binary() {
  local binary="$1"
  local label="$2"
  if [ ! -x "$binary" ]; then
    printf 'Missing executable %s: %s\n' "$label" "$binary" >&2
    exit 1
  fi
  verify_arm64_file "$binary" "$label"
}

verify_portable_dependencies() {
  local binary="$1"
  local label="$2"
  local unexpected
  unexpected="$(otool -L "$binary" | awk 'NR > 1 {
    path = $1
    if (path !~ /^@/ && path !~ /^\/usr\/lib\// && path !~ /^\/System\/Library\//) print path
  }')"
  if [ -n "$unexpected" ]; then
    printf '%s has non-portable dynamic dependencies:\n%s\n' "$label" "$unexpected" >&2
    exit 1
  fi
}

verify_code_signature() {
  local path="$1"
  local label="$2"
  if ! codesign --verify --strict --verbose=2 "$path"; then
    printf '%s has an invalid code signature: %s\n' "$label" "$path" >&2
    exit 1
  fi
}

install_fbneo_library() {
  local source="$1"
  local destination="$2"
  local install_name="$3"
  local identifier="$4"
  local label="$5"
  local old_rpath="${6:-}"
  local temporary="${destination}.tmp.$$"

  verify_arm64_file "$source" "$label build dependency"
  rm -f "$temporary"
  install -m 755 "$source" "$temporary"
  if ! cmp -s "$source" "$temporary"; then
    rm -f "$temporary"
    printf '%s changed while staging.\n' "$label" >&2
    exit 1
  fi

  install_name_tool -id "@loader_path/$install_name" "$temporary"
  if [ -n "$old_rpath" ]; then
    install_name_tool -rpath "$old_rpath" "@loader_path" "$temporary"
  fi
  codesign --force --sign - --identifier "$identifier" --timestamp=none "$temporary"
  verify_arm64_file "$temporary" "staged $label"
  verify_portable_dependencies "$temporary" "staged $label"
  verify_code_signature "$temporary" "staged $label"
  mv -f "$temporary" "$destination"
  printf '%s SHA256: %s\n' "$label" "$(shasum -a 256 "$destination" | awk '{print $1}')"
}

prepare_fbneo_output() {
  local linked_sdl
  local sdl_source
  local sdl3_source
  linked_sdl="$(otool -L "$FBNEO_OUTPUT" | awk 'NR > 1 && $1 ~ /libSDL2.*\.dylib$/ { print $1; exit }')"
  if [ -z "$linked_sdl" ]; then
    printf 'Could not locate FBNeo SDL dependency: %s\n' "$linked_sdl" >&2
    exit 1
  fi
  sdl_source="$linked_sdl"
  if [ ! -f "$sdl_source" ]; then
    sdl_source="$(pkg-config --variable=libdir sdl2)/$FBNEO_SDL_NAME"
  fi
  if [ ! -f "$sdl_source" ]; then
    printf 'Could not locate FBNeo SDL dependency source: %s\n' "$sdl_source" >&2
    exit 1
  fi
  sdl3_source="$(pkg-config --variable=libdir sdl3)/libSDL3.0.dylib"
  if [ ! -f "$sdl3_source" ]; then
    printf 'Could not locate FBNeo SDL3 dependency source: %s\n' "$sdl3_source" >&2
    exit 1
  fi

  install_fbneo_library \
    "$sdl3_source" "$FBNEO_SDL3_RUNTIME" "$FBNEO_SDL3_NAME" org.libsdl.SDL3 "FBNeo SDL3"
  install_fbneo_library \
    "$sdl_source" "$FBNEO_SDL_RUNTIME" "$FBNEO_SDL_NAME" org.libsdl.SDL2 "FBNeo SDL2" \
    "@loader_path/../../../../opt/sdl3/lib"
  install_name_tool -change "$linked_sdl" "@loader_path/$FBNEO_SDL_NAME" "$FBNEO_OUTPUT"
  codesign --force --sign - --timestamp=none "$FBNEO_OUTPUT"
  verify_portable_dependencies "$FBNEO_OUTPUT" "FBNeo build output"
  verify_code_signature "$FBNEO_OUTPUT" "FBNeo build output"
}

install_runtime_binary() {
  local source="$1"
  local destination="$2"
  local label="$3"
  local temporary="${destination}.tmp.$$"

  verify_arm64_binary "$source" "$label build output"
  rm -f "$temporary"
  install -m 755 "$source" "$temporary"
  if ! cmp -s "$source" "$temporary"; then
    rm -f "$temporary"
    printf '%s changed while staging the bundled runtime.\n' "$label" >&2
    exit 1
  fi
  mv -f "$temporary" "$destination"
  if ! cmp -s "$source" "$destination"; then
    printf 'Bundled %s does not match its build output.\n' "$label" >&2
    exit 1
  fi

  verify_arm64_binary "$destination" "bundled $label"
  verify_portable_dependencies "$destination" "bundled $label"
  verify_code_signature "$destination" "bundled $label"
  printf '%s SHA256: %s\n' "$label" "$(shasum -a 256 "$destination" | awk '{print $1}')"
}

cd "$FBNEO_DIR"
make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl

prepare_fbneo_output
install_runtime_binary "$FBNEO_OUTPUT" "$RUNTIME_BINARY" "FBNeo"

if [ -x "$SNES9X_DIR/build-macade.sh" ]; then
  cd "$SNES9X_DIR"
  ./build-macade.sh
  install_runtime_binary "$SNES9X_OUTPUT" "$SNES9X_RUNTIME_BINARY" "Snes9x"
else
  printf 'Snes9x native runtime source is not present; skipping Snes9x build.\n'
fi

codesign --force --sign - --timestamp=none "$FLYCAST_RUNTIME_BINARY"
codesign --force --sign - --timestamp=none "$FLYCAST_RUNTIME_APP"
verify_arm64_binary "$FLYCAST_RUNTIME_BINARY" "bundled Flycast Dojo"
verify_portable_dependencies "$FLYCAST_RUNTIME_BINARY" "bundled Flycast Dojo"
if ! codesign --verify --deep --strict --verbose=2 "$FLYCAST_RUNTIME_APP"; then
  printf 'Bundled Flycast Dojo has an invalid code signature.\n' >&2
  exit 1
fi
printf 'Flycast Dojo SHA256: %s\n' "$(shasum -a 256 "$FLYCAST_RUNTIME_BINARY" | awk '{print $1}')"

cd "$ROOT_DIR"
xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' -derivedDataPath "$DERIVED_DATA_DIR" build

rm -rf "$APP_PATH"
cp -R "$BUILT_APP_PATH" "$APP_PATH"

PACKAGED_RUNTIME_ROOT="$APP_PATH/Contents/Resources/FightcadeRuntime/emulators"
verify_arm64_binary "$APP_PATH/Contents/MacOS/Macade" "packaged Macade"
cmp "$RUNTIME_BINARY" "$PACKAGED_RUNTIME_ROOT/fbneo/macfbneo"
cmp "$FBNEO_SDL_RUNTIME" "$PACKAGED_RUNTIME_ROOT/fbneo/$FBNEO_SDL_NAME"
cmp "$FBNEO_SDL3_RUNTIME" "$PACKAGED_RUNTIME_ROOT/fbneo/$FBNEO_SDL3_NAME"
cmp "$SNES9X_RUNTIME_BINARY" "$PACKAGED_RUNTIME_ROOT/snes9x/snes9x"
cmp "$FLYCAST_RUNTIME_BINARY" "$PACKAGED_RUNTIME_ROOT/flycast/Flycast Dojo.app/Contents/MacOS/Flycast Dojo"
verify_portable_dependencies "$PACKAGED_RUNTIME_ROOT/fbneo/macfbneo" "packaged FBNeo"
verify_portable_dependencies "$PACKAGED_RUNTIME_ROOT/fbneo/$FBNEO_SDL_NAME" "packaged FBNeo SDL2"
verify_portable_dependencies "$PACKAGED_RUNTIME_ROOT/fbneo/$FBNEO_SDL3_NAME" "packaged FBNeo SDL3"
verify_portable_dependencies "$PACKAGED_RUNTIME_ROOT/snes9x/snes9x" "packaged Snes9x"
verify_portable_dependencies "$PACKAGED_RUNTIME_ROOT/flycast/Flycast Dojo.app/Contents/MacOS/Flycast Dojo" "packaged Flycast Dojo"
if ! codesign --verify --deep --strict --verbose=2 "$APP_PATH"; then
  printf 'Packaged Macade app has an invalid code signature.\n' >&2
  exit 1
fi

printf '\nMacade app: %s\n' "$APP_PATH"
printf 'Open with: open %q\n' "$APP_PATH"
