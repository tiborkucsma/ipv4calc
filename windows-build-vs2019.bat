@echo off
echo --------------------------------
echo -- Generating vs2019 solution --
echo --------------------------------
echo.
START /B /wait .\_premake\bin\premake5.exe vs2019
PUSHD generated
echo.
echo --------------------------------
echo --   Starting vs2019 build    --
echo --------------------------------
echo Please wait...
echo.
START /B /wait devenv ipv4calc.sln /Build
POPD
PAUSE