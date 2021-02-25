workspace "Ironforge"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Forge/vendor/GLFW/include"

include "Forge/vendor/GLFW"

project "Forge"
	location "Forge"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "fepch.h"
	pchsource "Forge/src/fepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links

	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FE_PLATFORM_WINDOWS",
			"FE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FE_DIST"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Forge/vendor/spdlog/include",
		"Forge/src"
	}

	links
	{
		"Forge"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FE_DIST"
		optimize "On" 