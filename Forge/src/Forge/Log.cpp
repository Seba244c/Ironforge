#include "fepch.h"
#include "Log.h"

namespace Forge {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("CORE");
		s_CoreLogger->set_level(spdlog::level::info);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::info);
	}

	void Log::Test() {
		FE_INFO("Info");
		FE_WARN("Warn");
		FE_ERROR("Error");
		FE_FATAL("Fatal");
	}
}
