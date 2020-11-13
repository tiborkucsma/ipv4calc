require "_premake/clean"
require "_premake/gmake2-build"

workspace "ipv4-calc"
    location "generated"
    language "C"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    filter { "configurations:Debug" }
        symbols "On"

    filter { "configurations:Release" }
        optimize "On"
    
    filter {}

    targetdir ("build/bin/%{prj.name}/%{cfg.longname}")
    objdir ("build/obj/%{prj.name}/%{cfg.longname}")

project "ipv4-clalc"
    kind "ConsoleApp"
    files { "src/**", "include/**" }