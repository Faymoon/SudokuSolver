workspace "SudokuSolver"
    configurations { "Release", "Debug" }
    platforms { "x86", "x64" }

    location "build/"

    startproject "SudokuSolver"

project "SudokuSolver"

    kind "ConsoleApp"

    cppdialect "C++17"

    includedirs "include/"

    files {
        "include/*.hpp",
        "include/*.inl",
        "src/*.cpp"
    }

    filter "configurations:Debug"
        targetdir "bin/Debug/"
		defines { "DEBUG" }
        symbols "On"
        buildoptions { "-g" }

	filter "configurations:Release"
        targetdir "bin/Release/"
		defines { "NDEBUG" }
        optimize "On"
    
    filter "platforms:x86"
        architecture "x86"
    filter "platforms:x86_64"
        architecture "x86_64"

    filter {}


