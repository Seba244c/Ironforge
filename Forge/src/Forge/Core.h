#pragma once

#ifdef FE_PLATFORM_WINDOWS
	#ifdef FE_BUILD_DLL
		#define FORGE_API __declspec(dllexport)
	#else
		#define FORGE_API __declspec(dllimport)
	#endif // FE_BUILD_DLL
#else
	#error Forge only supports Windows!
#endif  // FE_PLATFORM_WINDOWS
