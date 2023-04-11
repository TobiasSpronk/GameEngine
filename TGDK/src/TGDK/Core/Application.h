#pragma once
#include "tgdk_pch.h"
#include "TGDK//Core.h"
#include "TGDK//Events/Event.h"
#include "TGDK/Events/ApplicationEvent.h"
#include "Window.h"
#include "TGDK/Core/LayerStack.h"


namespace tgdk
{
	class TGDK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	// to be defined in CLIENT
	Application* CreateApplication();
}


