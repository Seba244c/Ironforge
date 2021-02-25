#pragma once

// PLATFORM AND API
#ifdef FE_PLATFORM_WINDOWS
	#ifdef FE_BUILD_DLL
		#define FORGE_API __declspec(dllexport)
	#else
		#define FORGE_API __declspec(dllimport)
	#endif // FE_BUILD_DLL
#else
	#error Forge only supports Windows!
#endif  // FE_PLATFORM_WINDOWS

// Asserten
#ifdef FE_ENABLE_ASSERTS
	#define FE_ASSERT(x, ...) { if(!(x)) { FE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FE_CORE_ASSERT(x, ...) { if(!(x)) { FE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FE_ASSERT(x, ...)
	#define FE_CORE_ASSERT(x, ...)
#endif

// Bit
#define BIT(x) (1 << x)
