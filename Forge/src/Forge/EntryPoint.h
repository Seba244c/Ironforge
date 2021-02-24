#pragma once

#ifdef FE_PLATFORM_WINDOWS
	extern Forge::Application* Forge::CreateApplication();
	
	int main(int argc, char** argv) {
		printf("Welcome to IronForge!");
		auto app = Forge::CreateApplication();
		app->Run();
		delete app;
	}
#endif // FE_PLATFORM_WINDOWS
