#pragma once
#include "tgdk_pch.h"
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"


namespace tgdk
{
	class TGDK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	// to be defined in CLIENT
	Application* CreateApplication();
}


