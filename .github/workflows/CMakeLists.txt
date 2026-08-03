CMake

cmake_minimum_required(VERSION 3.16)
project(VSDTPWord VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport Core Gui Network)

qt_standard_project_setup()

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/translation_engine.cpp
)

set(HEADERS
    src/mainwindow.h
    src/translation_engine.h
)

qt_add_executable(VSDTPWord ${SOURCES} ${HEADERS})

target_link_libraries(VSDTPWord PRIVATE 
    Qt6::Widgets 
    Qt6::PrintSupport 
    Qt6::Core 
    Qt6::Gui
)
