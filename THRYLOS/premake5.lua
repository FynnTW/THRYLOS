workspace "THRYLOS"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "ThrylosEngine/3rd/glfw/include"

include "ThrylosEngine/3rd/glfw_premake.lua"

project "ThrylosEngine"
    location "ThrylosEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "tpch.h"
    
    pchsource "ThrylosEngine/src/tpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/src/Thrylos",
        "%{prj.name}/3rd/spdlog/include",
        "%{IncludeDir.GLFW}",
    }

    links
    {
        "GLFW",
        "opengl32.lib",
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "THRYLOS_PLATFORM_WINDOWS",
            "THRYLOS_BUILD_DLL",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "THRYLOS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "THRYLOS_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "THRYLOS_DIST"
        optimize "On"

    filter {"system:windows", "configurations:Debug"}
        buildoptions "/MDd"

    filter {"system:windows", "configurations:Release"}
        buildoptions "/MD"

    filter {"system:windows", "configurations:Dist"}
        buildoptions "/MD"


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
        "ThrylosEngine/3rd/spdlog/include",
        "ThrylosEngine/src",
        "%{IncludeDir.GLFW}",
    }

    links
    {
        "ThrylosEngine"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "THRYLOS_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "THRYLOS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "THRYLOS_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "THRYLOS_DIST"
        optimize "On"

    filter {"system:windows", "configurations:Debug"}
        buildoptions "/MDd"

    filter {"system:windows", "configurations:Release"}
        buildoptions "/MD"

    filter {"system:windows", "configurations:Dist"}
        buildoptions "/MD"




