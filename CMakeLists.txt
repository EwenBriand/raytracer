cmake_minimum_required(VERSION 3.5)

project(Raytracer
    VERSION 1.0
    DESCRIPTION "My project description"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -O3)

include_directories(./include)

set(SOURCES
    src/main.cpp
    src/AbstractFactory.cpp
    src/Boxes.cpp
    src/Camera.cpp
    src/Color.cpp
    src/Cones.cpp
    src/Cylinders.cpp
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
    src/Directional.cpp
    src/Diffuse.cpp
)

add_executable(raytracer ${SOURCES})

# # Add the move_file target as a dependency of the raytracer target to ensure it is executed during the build
# add_dependencies(raytracer move_file)

target_link_libraries(
    raytracer
    -lsfml-system
    -lsfml-window
    -lsfml-graphics
    -ldl
    -lconfig++
)

add_custom_command(
    TARGET raytracer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:raytracer> ${CMAKE_BINARY_DIR}/..
    COMMENT "Moving file from $<TARGET_FILE:raytracer> to ${CMAKE_BINARY_DIR}/raytracer."
)
