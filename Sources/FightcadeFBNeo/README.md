# Macade Fightcade FBNeo

This is the trimmed, modified Fightcade FBNeo runtime source used by Macade.

The tree keeps only the source and build inputs needed for the native macOS SDL2 runtime. Windows project files, help files, packaged binaries, and generated build outputs are intentionally not tracked.

## Layout

| Path | Purpose |
| --- | --- |
| `makefile.sdl` | Native SDL2 FBNeo build entry point. |
| `src/burn`, `src/cpu`, `src/intf`, `src/dep` | FBNeo emulator source and compile-time dependencies. |
| `src/burner/sdl` | SDL frontend source. |
| `src/macade` | Macade-specific runtime bridge, embedded video/input, and Fightcade-compatible GGPO work. |

## Build

Requirements: `make`, `perl`, `pkg-config`, and SDL2 development files discoverable through `pkg-config --cflags --libs sdl2`.

```sh
cd Sources/FightcadeFBNeo
make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl
```

Generated outputs such as `obj/`, `fbneosdl*`, `gamelist.txt`, and `src/dep/generated/` are ignored.
