#pragma once
#include "Core.h"

namespace Forge {
	class FORGE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		
	};

	// TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}