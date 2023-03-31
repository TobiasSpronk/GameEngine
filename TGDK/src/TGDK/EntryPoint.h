#pragma once


#ifdef TGDK_PLATFORM_WINDOWS

extern tgdk::Application* tgdk::CreateApplication();

int main(int argc, char** argv)
{
	tgdk::Log::Init();
	TGDK_CORE_WARN("Initialized Log!");
	int a = 5;
	TGDK_INFO("Hello! Var = {0}", a);


	printf("Welcome to TGDK engine");
	auto app = tgdk::CreateApplication();
	app->run();
	delete app;
}
#endif
