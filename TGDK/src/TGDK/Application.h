#pragma once

#include "Core.h"

namespace tgdk
{
	class TGDK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	};

	// to be defined in CLIENT
	Application* CreateApplication();
}


