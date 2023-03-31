#include "Application.h"



namespace tgdk
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);
		TGDK_TRACE(e);
		while (true);
	}
}