cmake_minimum_required(VERSION 3.5)

project(Raytracer
    VERSION 1.0
    DESCRIPTION "My project description"
    LANGUAGES CXX
)

# force .so pour moi sous mac ^^
set(CMAKE_SHARED_LIBRARY_SUFFIX .so)

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
)

add_executable(raytracer ${SOURCES})

set(PLUGIN
    badWords/badWord.cpp
    badWords/entryPoint.cpp
)

add_library(BadWord SHARED ${PLUGIN})

# trouver la SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Trouver libconfig
find_path(LIBCONFIG_INCLUDE_DIR libconfig.h++ PATH_SUFFIXES libconfig++)
find_library(LIBCONFIG_LIBRARY libconfig++.dylib)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(libconfig++ DEFAULT_MSG LIBCONFIG_LIBRARY LIBCONFIG_INCLUDE_DIR)

mark_as_advanced(LIBCONFIG_INCLUDE_DIR LIBCONFIG_LIBRARY)

include_directories(${LIBCONFIG_INCLUDE_DIR})

# Linker les bibliothèques
target_link_libraries(
    raytracer
    ${LIBCONFIG_LIBRARY}
    -lsfml-system
    -lsfml-window
    -lsfml-graphics
    -ldl
)
