#pragma once
#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Forge {
	class FORGE_API Log
	{
	public:
		static void Init();
		static void Test();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#ifndef FE_DIST
	#define FE_CORE_TRACE(...)    ::Forge::Log::GetCoreLogger()->trace(__VA_ARGS__)
#else
	#define FE_CORE_TRACE(x, ...)
#endif
#define FE_CORE_INFO(...)     ::Forge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FE_CORE_WARN(...)     ::Forge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FE_CORE_ERROR(...)    ::Forge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FE_CORE_FATAL(...)    ::Forge::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#ifndef FE_DIST
	#define FE_TRACE(...)         ::Forge::Log::GetClientLogger()->trace(__VA_ARGS__)
#else
	#define FE_TRACE(x, ...)
#endif
#define FE_INFO(...)	      ::Forge::Log::GetClientLogger()->info(__VA_ARGS__)
#define FE_WARN(...)	      ::Forge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FE_ERROR(...)	      ::Forge::Log::GetClientLogger()->error(__VA_ARGS__)
#define FE_FATAL(...)	      ::Forge::Log::GetClientLogger()->critical(__VA_ARGS__) 
