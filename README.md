# Salt Shack DayZ

All My DayZ files — custom types with modified spawn rates / respawn timers, split custom types files, harder-style DayZ servers.

## DayZ modding skill for AI agents

This repo vendors the [StarDZ DayZ Modding Skills](https://github.com/StarDZ-Team/Dayz-Modding-Skills) Agent Skill (MIT) so Cursor / Claude Code / other agents load Enforce Script, CE, and modding expertise when editing these files.

| Path | Role |
| --- | --- |
| `skills/dayz-modding/` | Canonical skill + references |
| `.cursor/skills/dayz-modding` | Symlink for Cursor project skill discovery |
| `.claude-plugin/marketplace.json` | Claude Code marketplace manifest |
| `.cursor-plugin/plugin.json` / `plugin.json` | Cursor / Agent Plugins manifests |
| `AGENTS.md` | When agents must load the skill |

Upstream install (optional): `npx skills add StarDZ-Team/Dayz-Modding-Skills`
