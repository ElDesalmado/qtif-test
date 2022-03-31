cmake_minimum_required(VERSION 3.11.4 FATAL_ERROR)

project(qtif-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)

find_package(Qt5 COMPONENTS Core GUI REQUIRED)

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

include(GNUInstallDirs)

install(TARGETS app DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT app)
install(TARGETS component_a DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT comp_a)

include(InstallRequiredSystemLibraries)
# TODO: runtime libraries and dependencies

# variables must be set before inclusion of CPack and CPackIFW
set(CPACK_IFW_PACKAGE_TITLE "Qt IFW Installation")
set(CPACK_IFW_PACKAGE_ALLOW_NON_ASCII_CHARACTERS ON)

include(CPack)
include(CPackIFW)

message(STATUS "Package title: ${CPACK_IFW_PACKAGE_TITLE}")