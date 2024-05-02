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
IncludeDir["glad"] = "ThrylosEngine/3rd/glad/include"
IncludeDir["imgui"] = "ThrylosEngine/3rd/imgui"
IncludeDir["stb_image"] = "ThrylosEngine/3rd/stb_image"
IncludeDir["glm"] = "ThrylosEngine/3rd/glm"

include "ThrylosEngine/3rd/glfw_premake.lua"
include "ThrylosEngine/3rd/glad_premake.lua"
include "ThrylosEngine/3rd/imgui_premake.lua"

project "ThrylosEngine"
    location "ThrylosEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "tpch.h"
    pchsource "ThrylosEngine/src/tpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/3rd/stb_image/**.h",
        "%{prj.name}/3rd/stb_image/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/src/Thrylos",
        "%{prj.name}/3rd/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "glad",
        "imgui",
        "opengl32.lib",
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "THRYLOS_PLATFORM_WINDOWS",
            "THRYLOS_BUILD_DLL",
            "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
            "_WINDLL",
            "_CRT_SECURE_NO_WARNINGS",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "THRYLOS_DEBUG"
        symbols "on"

    filter "configurations:Release"
        defines "THRYLOS_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "THRYLOS_DIST"
        optimize "on"

    filter {"system:windows", "configurations:Debug"}
        defines "THRYLOS_DEBUG"
        runtime "Debug"
        symbols "On"

    filter {"system:windows", "configurations:Release"}
        defines "THRYLOS_RELEASE"
        runtime "Release"
        optimize "On"

    filter {"system:windows", "configurations:Dist"}
        defines "THRYLOS_DIST"
        runtime "Release"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    cppdialect "C++20"
    language "C++"
    staticruntime "On"

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
        "%{IncludeDir.Glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.imgui}"
    }

    links
    {
        "ThrylosEngine",
        "imgui",
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "THRYLOS_PLATFORM_WINDOWS",
            "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        }

    filter "configurations:Debug"
        defines "THRYLOS_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "THRYLOS_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "THRYLOS_DIST"
        runtime "Release"
        optimize "On"




