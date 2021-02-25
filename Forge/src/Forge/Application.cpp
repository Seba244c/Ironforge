#include "fepch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Forge {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			FE_INFO(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			FE_INFO(e);
		}

		while (true);
	}
}