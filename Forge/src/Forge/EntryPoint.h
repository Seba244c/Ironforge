#pragma once

#ifdef FE_PLATFORM_WINDOWS
	extern Forge::Application* Forge::CreateApplication();
	
	int main(int argc, char** argv) {
		Forge::Log::Init();
		FE_CORE_INFO("Initlialized the logging system!");
		
		auto app = Forge::CreateApplication();
		app->Run();
		delete app;
	}
#endif // FE_PLATFORM_WINDOWS
