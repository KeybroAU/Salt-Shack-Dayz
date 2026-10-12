class CfgPatches
{
	class SaltShackLoadingScreen
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class SaltShackLoadingScreen
	{
		dir = "SaltShackLoadingScreen";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "Salt Shack Loading Screen";
		credits = "Salt Shack";
		author = "Salt Shack";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] =
		{
			"Game"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"SaltShackLoadingScreen/scripts/3_Game"
				};
			};
		};
	};
};
