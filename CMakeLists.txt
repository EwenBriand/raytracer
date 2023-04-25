cmake_minimum_required(VERSION 3.5)

project(Raytracer
    VERSION 1.0
    DESCRIPTION "My project description"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -O3)

include_directories(./include)

set(SOURCES
    src/main.cpp
    pluginLoader/PluginLoader.cpp
)

add_executable(raytracer ${SOURCES})

set(PLUGIN
    plugins/badWord.cpp
    plugins/entryPoint.cpp
)

add_library(BadWord SHARED ${PLUGIN})

target_link_libraries(
    raytracer
    -lsfml-system
    -lsfml-window
    -lsfml-graphics
    -ldl
)

# find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)