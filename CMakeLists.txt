# project root.
cmake_minimum_required(VERSION 4.0.2)
set(PROJECT_NAME "audio_dsp")
set(PROJECT_VER "0.1.0")

set(LIBRARY_NAME "wisty_dsp")
set(EXE_NAME "wisty_application")

project(${PROJECT_NAME}
        VERSION ${PROJECT_VER}
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# If testing modules, Set it to ON this option.
option(BUILD_TEST "[RootLists]: build with test directory? *default is ON" ON)
# Set it to ON to create an executable file.
option(BUILD_EXE "[RootLists]: wanna create an executable file? *default is OFF" ON)

# own library directory
add_subdirectory(./src)

if(BUILD_EXE)
    add_subdirectory(./app)
endif ()
if(BUILD_TEST)
    add_subdirectory(./test)
endif()