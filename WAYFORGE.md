# Wayforge

Wayforge is a hard fork of [Godot Engine](https://godotengine.org) 4.7, made for worlds: big
procedural planets, landscapes with caves and overhangs, real skies and seas, and the speed to put
them on screen. It's MIT-licensed like Godot, and Godot's copyright and the notices of everything it
bundles are kept (`LICENSE.txt`, `COPYRIGHT.txt`, `editor/gui/editor_about.cpp`).

What's different from upstream, in the order it was added (each item on its own branch, merged into
`aige/4.7`):

| Change | Where |
|---|---|
| The name: Wayforge in the window titles, the about box, the console header, the binaries (`wayforge.<platform>.<target>...`); its own logo and app icon | `version.py`, `SConstruct` (`binary_name`), `platform/*/SCsub`, `editor/icons/Logo.svg`, `TitleBarLogo.svg`, `main/app_icon.png` |
| User data stays in Godot's folder (`~/.local/share/godot/`, `%APPDATA%/Godot/`), so games' saves and settings don't move | `core/os/os.cpp`, `platform/windows/os_windows.cpp` (`get_godot_dir_name`) |

The game that drives it (AIGE) keeps the roadmap: `docs/engine/ROADMAP.md` there.

## Taking upstream fixes

Wayforge follows Godot's 4.7 maintenance releases. To bring one in (4.7.3, say):

```bash
git remote add upstream https://github.com/godotengine/godot.git   # once
git fetch upstream --tags
git merge 4.7.3-stable          # on aige/4.7; conflicts are usually version.py (keep ours,
                                # take their version numbers)
```

Then build (the game's `scripts/11-build-engine.sh`) and run its tests.

Godot is a trademark of the Godot Foundation; Wayforge isn't affiliated with or endorsed by it.
