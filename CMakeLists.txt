cmake_minimum_required(VERSION 3.11.4 FATAL_ERROR)

project(qtif-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)

# dynamic lib component
add_library(component_a SHARED
        src/component_a.cpp)

target_include_directories(component_a
        PUBLIC
            include
        )

target_compile_definitions(component_a PRIVATE BUILD_DLL)

add_executable(app src/main.cpp)

target_link_libraries(app PRIVATE component_a)