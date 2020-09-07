-- Helpful premake documentation
-- Tokens https://github.com/premake/premake-core/wiki/Tokens

workspace ("RuntimeCompiling")
	
	configurations { "Debug32", "Release32", "Debug64", "Release64" }

   filter "configurations:*32"
      architecture "x86"

   filter "configurations:*64"
      architecture "x86_64"

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

	-- Samples
	project ("msvc")
		location ("Samples")
		kind "SharedLib"
		language "C++"
		cppdialect "C++17"

		targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
		objdir ("Bin-Int/" .. outputdir .. "/%{prj.name}")
		
		files
		{
			"Samples/Source/**.cpp",
			"Samples/Source/**.h",
		}
		
	postbuildcommands
	{
		("{COPY} %{wks.location}Bin/".. outputdir .. "/%{prj.name}/%{prj.name}.dll ../RuntimeCompiling/")
	}