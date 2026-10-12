# Salt Shack Loading Screen

Client mod that replaces the scripted DayZ loading screen, the login queue background, and the login timer background with the Salt Shack artwork. The title, tagline, rules, and "LOADING..." are part of that image. The layout does not draw them again. Vanilla logo widgets stay hidden.

The engine splash that appears before scripts start is unchanged. The mission file `load.paa` (a file sitting in the mission folder) is also a separate splash and is not part of this mod.

## Load it on a server

1. Copy the `@SaltShackLoadingScreen` folder next to `DayZServer_x64.exe` (the folder name stays the same).
2. Append it to the server `-mod=` list, separated with a semicolon:

```bat
-mod=@ExistingMod;@SaltShackLoadingScreen
```

3. Players need the same folder on the client. This is a normal mod (`type = "mod"`), not a server-only mod, because the loading screen runs on the client. Publishing the folder to the Workshop, or giving players the same `@SaltShackLoadingScreen` directory, is what makes the screen show for them.
4. If `serverDZ.cfg` has `verifySignatures = 2`, sign the PBO before going live. Unsigned PBOs are rejected.

```bat
DSCreateKey.exe SaltShack
DSSignFile.exe SaltShack.biprivatekey @SaltShackLoadingScreen\Addons\SaltShackLoadingScreen.pbo
```

Put `SaltShack.bikey` in `@SaltShackLoadingScreen\Keys\` and in the server `keys\` folder. Keep `SaltShack.biprivatekey` private. Re-sign after every rebuild.

## What is in this folder

| Path | Role |
| --- | --- |
| `mod.cpp` | Launcher name and logo. Not packed into the PBO. |
| `Addons/SaltShackLoadingScreen.pbo` | Packed addon. `config.cpp` inside is not binarized. |
| `SaltShackLoadingScreen/` | Source. `$PBOPREFIX$` is `SaltShackLoadingScreen`. |

`data/salt_shack_loading.png` is the loading artwork, packed as `data/salt_shack_loading.paa`. The same texture is the login queue and login timer background. `data/mod_logo.png` is only the launcher icon. The game reads the `.paa` files.

## Pack it again

DayZ Tools were not available in the environment that produced the checked-in PBO, so that PBO was packed without Addon Builder and without a signature. Prefer a binarized, signed build from DayZ Tools before a public server.

From a `P:\` drive that contains this source folder:

```bat
AddonBuilder.exe P:\SaltShackLoadingScreen P:\@SaltShackLoadingScreen\Addons -prefix=SaltShackLoadingScreen -temp=P:\temp\SaltShackLoadingScreen -clear
```

Script-only alternative (no binarize), which matches the checked-in PBO:

```bat
FileBank.exe -property prefix=SaltShackLoadingScreen -property "product=dayz ugc" P:\SaltShackLoadingScreen_staging
```

Stage `config.cpp`, `gui\`, `data\*.paa`, and `scripts\` into that folder. Do not pack `mod.cpp`, the PNG artwork, or `$PBOPREFIX$`. `config.cpp` changes are not picked up by file patching; rebuild the PBO after editing it. Script, layout, and `.paa` edits can be tried with `-filePatching` on the diag exe, with `allowFilePatching = 1` in `serverDZ.cfg`.

After launch, read the profile `.RPT` for addon load errors, then `script_*.log` for script compile errors.
