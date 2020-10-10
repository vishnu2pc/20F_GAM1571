workspace "Game"
	configurations	{ "Debug", "Release" }
	platforms		{ "x64" }
	location		"build"
	characterset	"MBCS"
	startproject	"Game"

project "Game"
	kind		"WindowedApp"
	location	"build/Game"
	debugdir	"Game"

	files {
		"Game/Source/**.cpp",
		"Game/Source/**.h",
		"Game/Data/**.vert",
		"Game/Data/**.frag",
		"premake5.lua",
		".gitignore",
		"GenerateProjectFiles.bat",
	}

	includedirs {
		"Game/Source",
	}

	links {
		"Framework",
		"opengl32",
	}

	pchheader "GamePCH.h"
	pchsource "Game/Source/WinMain.cpp"

project "Framework"
	kind		"StaticLib"
	location	"build/Framework"

	files {
		"Framework/Source/**.cpp",
		"Framework/Source/**.h",
		"Framework/Libraries/imgui/*.cpp",
		"Framework/Libraries/imgui/*.h",
	}

	includedirs {
		"Framework/Source",
		
	}

	pchheader "FrameworkPCH.h"
	pchsource "Framework/Source/Core/FWCore.cpp"

	filter "files:Framework/Libraries/imgui/*.cpp"
		flags { "NoPCH" }