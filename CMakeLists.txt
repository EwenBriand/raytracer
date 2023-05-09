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

# Trouver libconfig++ pour les systèmes Linux et macOS
if (APPLE)
    find_path(LIBCONFIG_INCLUDE_DIR libconfig.h++ PATH_SUFFIXES libconfig++)
    find_library(LIBCONFIG_LIBRARY libconfig++.dylib)
else()
    find_path(LIBCONFIG_INCLUDE_DIR libconfig.h++ PATH_SUFFIXES libconfig++)
    find_library(LIBCONFIG_LIBRARY libconfig++.so)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(libconfig++ DEFAULT_MSG LIBCONFIG_LIBRARY LIBCONFIG_INCLUDE_DIR)

mark_as_advanced(LIBCONFIG_INCLUDE_DIR LIBCONFIG_LIBRARY)

include_directories(${LIBCONFIG_INCLUDE_DIR})

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

target_link_libraries(raytracer sfml-system sfml-window sfml-graphics)
include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(
    raytracer
    ${SFML_LIBRARIES}
    ${LIBCONFIG_LIBRARY}
    dl
)

add_custom_command(
    TARGET raytracer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:raytracer> ${CMAKE_BINARY_DIR}/..
    COMMENT "Moving file from $<TARGET_FILE:raytracer> to ${CMAKE_BINARY_DIR}/raytracer."
)
