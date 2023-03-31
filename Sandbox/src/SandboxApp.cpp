#include "TGDK.h"

class Sandbox : public tgdk::Application
{
public:
	Sandbox()
	{
		
	}
	~Sandbox()
	{
		
	}
};

tgdk::Application* tgdk::CreateApplication()
{
	return new Sandbox();
}
