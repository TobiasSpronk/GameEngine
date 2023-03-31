workspace "TGDK"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
	startproject "Sandbox"
outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TGDK"
    location "TGDK"
    kind "SharedLib"
    language "C++"
	
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp"
    }
    includedirs
    {
        "TGDK/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TGDK_PLATFORM_WINDOWS",
            "TGDK_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "TGDK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TGDK_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "TGDK_DIST"
        symbols "On"
    
   
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp"
    }
    includedirs
    {
        "TGDK/vendor/spdlog/include",
        "TGDK/src"
    }

    links
    {
        "TGDK"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TGDK_PLATFORM_WINDOWS",
        }

    
    filter "configurations:Debug"
        defines "TGDK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TGDK_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "TGDK_DIST"
        symbols "On"
		
		
newaction {
    trigger = "clean",
    description = "Remove all binaries and intermediate binaries, and vs files.",
    execute = function()
        print("Removing binaries")
        os.rmdir("./bin")
        print("Removing intermediate binaries")
        os.rmdir("./bin-int")
        print("Removing project files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
}