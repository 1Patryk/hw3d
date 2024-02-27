cmake_minimum_required(VERSION 3.1)

project(FirstProject VERSION 0.1 LANGUAGES CXX )

set(SOURCES
	WinMain.cpp)

#[===[ we need WIN32 for build windowed applications ]===]
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
