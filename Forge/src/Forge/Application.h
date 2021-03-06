#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Forge/LayerStack.h"
#include "Forge/Events/Event.h"
#include "Forge/Events/ApplicationEvent.h"

namespace Forge {
	class FORGE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}
