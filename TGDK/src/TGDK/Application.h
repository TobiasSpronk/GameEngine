#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

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


