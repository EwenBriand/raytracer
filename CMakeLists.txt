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
    src/Core.cpp
    src/Boxes.cpp
    src/Camera.cpp
    src/Color.cpp
    src/Cones.cpp
    src/Cylinders.cpp
    src/Lights.cpp
    src/ParserFile.cpp
    src/Planes.cpp
    src/Point3D.cpp
    src/Ray.cpp
    src/RaytracerCore.cpp
    src/RaytracerGraphic.cpp
    src/Spheres.cpp
    src/Rectangle3D.cpp
    src/Vector3D.cpp
    src/Spheres.cpp
    src/Torus.cpp
    src/Triangles.cpp
    src/PluginManager.cpp
)

add_executable(raytracer ${SOURCES})

# set(PLUGIN
# )

# add_library(BadWord SHARED ${PLUGIN})

target_link_libraries(
    raytracer
    -lsfml-system
    -lsfml-window
    -lsfml-graphics
    -ldl
    -lconfig++
)