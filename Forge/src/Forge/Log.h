#pragma once
#include "Core.h"
#include <memory>
#include "spdlog\spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Forge {
	class FORGE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define FE_CORE_INFO(...)     ::Forge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FE_CORE_WARN(...)     ::Forge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FE_CORE_ERROR(...)    ::Forge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FE_CORE_FATAL(...)    ::Forge::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define FE_INFO(...)	      ::Forge::Log::GetClientLogger()->info(__VA_ARGS__)
#define FE_WARN(...)	      ::Forge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FE_ERROR(...)	      ::Forge::Log::GetClientLogger()->error(__VA_ARGS__)
#define FE_FATAL(...)	      ::Forge::Log::GetClientLogger()->fatal(__VA_ARGS__) 