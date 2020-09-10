workspace "Game"
	configurations { "Debug", "Release" }
	platforms {"x64"}
	location "build"
	characterset "MBCS"
	
project "Game"
	kind "WindowedApp"
	
	files {
		"Game/Source/**.cpp",
		"GenerateProjectFiles.bat",
		"premake5.lua",
		".gitignore"
		}
		