class SaltShackLoadingScreenPaths
{
	const string BACKGROUND = "SaltShackLoadingScreen/data/salt_shack_loading.paa";
	const string MASK = "SaltShackLoadingScreen/data/salt_shack_mask.paa";
	const string LAYOUT = "SaltShackLoadingScreen/gui/layouts/salt_shack_loading.layout";

	static void PaintBackground(ImageWidget background)
	{
		if (!background)
			return;

		background.LoadMaskTexture(MASK);
		background.LoadImageFile(0, BACKGROUND);
		background.SetMaskProgress(1.0);
	}
};

modded class LoadingScreen
{
	void LoadingScreen(DayZGame game)
	{
		Widget replacement;
		ImageWidget logoMid;
		ImageWidget logoCorner;
		TextWidget title;
		TextWidget status;
		ImageWidget background;
		ImageWidget loadingIcon;
		TextWidget moddedWarning;
		ProgressBarWidget loadingBar;
		TextWidget progressText;
		Widget notificationRoot;

		replacement = game.GetLoadingWorkspace().CreateWidgets(SaltShackLoadingScreenPaths.LAYOUT);
		if (!replacement)
			return;

		if (!Class.CastTo(logoMid, replacement.FindAnyWidget("ImageLogoMid")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(logoCorner, replacement.FindAnyWidget("ImageLogoCorner")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(title, replacement.FindAnyWidget("TextWidget")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(status, replacement.FindAnyWidget("StatusText")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(background, replacement.FindAnyWidget("ImageBackground")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(loadingIcon, replacement.FindAnyWidget("ImageLoadingIcon")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(moddedWarning, replacement.FindAnyWidget("ModdedWarning")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(loadingBar, replacement.FindAnyWidget("LoadingBar")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(progressText, replacement.FindAnyWidget("ProgressText")))
		{
			replacement.Unlink();
			return;
		}

		if (!Class.CastTo(notificationRoot, replacement.FindAnyWidget("notification_root")))
		{
			replacement.Unlink();
			return;
		}

		if (!replacement.FindAnyWidget("hint_frame"))
		{
			replacement.Unlink();
			return;
		}

		if (m_WidgetRoot)
			m_WidgetRoot.Unlink();

		m_WidgetRoot = replacement;
		m_ImageLogoMid = logoMid;
		m_ImageLogoCorner = logoCorner;
		m_TextWidgetTitle = title;
		m_TextWidgetStatus = status;
		m_ImageWidgetBackground = background;
		m_ImageBackground = background;
		m_ImageLoadingIcon = loadingIcon;
		m_ModdedWarning = moddedWarning;
		m_ProgressLoading = loadingBar;
		m_ProgressText = progressText;
		notificationRoot.Show(false);

		SaltShackLoadingScreenPaths.PaintBackground(m_ImageWidgetBackground);
		m_ImageWidgetBackground.SetPos(0, 0);
		m_ImageWidgetBackground.SetSize(1, 1);
		m_ImageLogoMid.Show(false);
		m_ImageLogoCorner.Show(false);
		m_ModdedWarning.Show(false);
		m_ProgressLoading.SetColor(0xFFE6E2D6);
		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
	}

	override void Show()
	{
		super.Show();

		SaltShackLoadingScreenPaths.PaintBackground(m_ImageWidgetBackground);

		if (m_ImageWidgetBackground)
		{
			m_ImageWidgetBackground.SetPos(0, 0);
			m_ImageWidgetBackground.SetSize(1, 1);
		}

		if (m_ImageLogoMid)
			m_ImageLogoMid.Show(false);

		if (m_ImageLogoCorner)
			m_ImageLogoCorner.Show(false);

		if (m_ModdedWarning)
			m_ModdedWarning.Show(false);

		if (m_ProgressLoading)
			m_ProgressLoading.SetColor(0xFFE6E2D6);
	}
};

modded class LoginTimeBase
{
	override void Show()
	{
		ImageWidget background;

		super.Show();

		if (!layoutRoot)
			return;

		if (!Class.CastTo(background, layoutRoot.FindAnyWidget("Background")))
			return;

		SaltShackLoadingScreenPaths.PaintBackground(background);
	}
};

modded class LoginQueueBase
{
	override void Show()
	{
		ImageWidget background;

		super.Show();

		if (!layoutRoot)
			return;

		if (!Class.CastTo(background, layoutRoot.FindAnyWidget("Background")))
			return;

		SaltShackLoadingScreenPaths.PaintBackground(background);
	}
};
