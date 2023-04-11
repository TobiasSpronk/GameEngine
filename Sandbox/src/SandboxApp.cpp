#include "TGDK.h"



class ExampleLayer : public tgdk::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		TGDK_TRACE("ExampleLayer::Update");
	}

	void OnEvent(tgdk::Event& event) override
	{
		TGDK_TRACE("{0}", event);

	} 
};

class Sandbox : public tgdk::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
		
	}
};

tgdk::Application* tgdk::CreateApplication()
{
	return new Sandbox();
}
