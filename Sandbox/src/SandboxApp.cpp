#include <Forge.h>

class ExampleLayer : public Forge::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		FE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Forge::Event& event) override
	{
		FE_TRACE("{0}", event);
	}

};

class Sandbox : public Forge::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
};

Forge::Application* Forge::CreateApplication() {
	return new Sandbox();
}