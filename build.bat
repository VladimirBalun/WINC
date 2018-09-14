@echo off

set build_directory="build"

set successful_build=0

if exist "%build_directory%\*.*" (
	rmdir /s /q %build_directory%
)

mkdir %build_directory%
cd %build_directory%
cmake ..

exit /b %successful_build%
