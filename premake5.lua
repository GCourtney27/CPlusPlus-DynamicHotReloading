-- Helpful premake documentation
-- Tokens https://github.com/premake/premake-core/wiki/Tokens

workspace ("RuntimeCompiling")
	architecture ("x86")

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["dlfcn"] = "RuntimeCompiling/Vendor/dlfcn"

-- Engine
project ("RuntimeCompiling")
	location ("RuntimeCompiling")
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Bin-Int/" .. outputdir .. "/%{prj.name}")

	pchheader "stdafx.h"
	pchsource "RuntimeCompiling/Source/stdafx.cpp" 

	files
	{
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/Source/**.h",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
	}

	includedirs
	{
		"%{IncludeDir.dlfcn}/",
		"%{prj.name}/Source/",
	}

	links
	{
	}

	filter "system:windows"
		systemversion "latest"

		flags
		{
			"MultiProcessorCompile"
		}
