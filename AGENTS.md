# Agent instructions — Salt Shack DayZ

## DayZ modding skill (required)

When editing DayZ content in this repo — Enforce Script (`.c`), `config.cpp`, `mod.cpp`, `.layout`, CE XML (`types.xml`, `events.xml`, `cfgspawnabletypes.xml`, etc.), or discussing DayZ/Enfusion modding — **read and follow** the vendored skill:

- Primary: `skills/dayz-modding/SKILL.md`
- References: `skills/dayz-modding/references/`

Cursor also discovers it via `.cursor/skills/dayz-modding` (symlink) and the plugin manifests (`.claude-plugin/marketplace.json`, `.cursor-plugin/plugin.json`, root `plugin.json`).

### Skill coverage (quick map)

| Topic | Reference |
| --- | --- |
| Enforce Script language + gotchas | `references/enforce-script-reference.md` |
| Engine API (entity, RPC, I/O, player, actions) | `references/api-patterns.md` |
| Layers, singletons, CF modules | `references/architecture.md` |
| Central Economy / types / events | `references/central-economy.md` |
| GUI (COT, VPP, widgets) | `references/gui-patterns.md` |
| Perf, debug, input | `references/advanced-patterns.md` |
| Build / PBO / Workbench | `references/build-and-deploy.md` |
| Models / assets | `references/model-asset-pipeline.md` |
| Plan → code → verify | `references/development-workflow.md` |

### Repo content

This repository holds Salt Shack / hardcore-style DayZ mission and CE files (custom types, spawn rates, timers). Prefer editing existing CE XML patterns in-tree over inventing new engine APIs.

### Attribution

The `dayz-modding` skill is MIT-licensed content from [StarDZ-Team/Dayz-Modding-Skills](https://github.com/StarDZ-Team/Dayz-Modding-Skills). See `skills/dayz-modding/LICENSE`.
