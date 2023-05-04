/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** AbstractFactory.cpp
*/

#include "AbstractFactory.hpp"
#include <functional>
#include <map>
#include "AllPrimitives.hpp"

std::shared_ptr<IPrimitives> createSpheres(const libconfig::Setting &s)
{
    return std::make_shared<Spheres>(s);
}

std::shared_ptr<IPrimitives> createCylinders(const libconfig::Setting &s)
{
    return std::make_shared<Cylinders>(s);
}

std::shared_ptr<IPrimitives> createPlanes(const libconfig::Setting &s)
{
    return std::make_shared<Planes>(s);
}

std::shared_ptr<IPrimitives> createCones(const libconfig::Setting &s)
{
    return std::make_shared<Cones>(s);
}

std::shared_ptr<IPrimitives> createTriangles(const libconfig::Setting &s)
{
    return std::make_shared<Triangles>(s);
}

std::shared_ptr<IPrimitives> createTorus(const libconfig::Setting &s)
{
    return std::make_shared<Torus>(s);
}

std::shared_ptr<IPrimitives> createBoxes(const libconfig::Setting &s)
{
    return std::make_shared<Boxes>(s);
}

std::shared_ptr<IPrimitives> AbstractFactory::createPrimitive(const std::string type,
    const libconfig::Setting &setting)
{
    std::map<std::string, std::function<std::shared_ptr<IPrimitives>(const libconfig::Setting &)> > primitiveMap = {
        {"spheres", createSpheres},
        {"cylinders", createCylinders},
        {"planes", createPlanes},
        {"cones", createCones},
        {"triangles", createTriangles},
        {"torus", createTorus},
        {"boxes", createBoxes}
    };
    if (primitiveMap.count(type)) {
        return primitiveMap[type](setting);
    } else {
        throw std::runtime_error("Unknown primitive type: " + type);
    }
}

// std::shared_ptr<IPrimitives> AbstractFactory::createPrimitive(const std::string type,
//     const libconfig::Setting &setting)
// {
//     std::map<std::string, std::function<std::shared_ptr<IPrimitives>(const libconfig::Setting &)> > primitiveMap = {
//         {"spheres",
//             [](const libconfig::Setting &s) -> std::shared_ptr<IPrimitives> {
//                 return std::make_shared<Spheres>(s);
//             }},
//         {"cylinders",
//             [](const libconfig::Setting &s) -> std::shared_ptr<IPrimitives> {
//                 return std::make_shared<Cylinders>(s);
//             }},
//         {"planes",
//             [](const libconfig::Setting &s) -> std::shared_ptr<IPrimitives> {
//                 return std::make_shared<Planes>(s);
//             }},
//         {"cones",
//             [](const libconfig::Setting &s) -> std::shared_ptr<IPrimitives> {
//                 return std::make_shared<Cones>(s);
//             }},
//         {"triangles",
//             [](const libconfig::Setting &s) -> std::shared_ptr<IPrimitives> {
//                 return std::make_shared<Triangles>(s);
//             }},
//         {"torus",
//             [](const libconfig::Setting &s) -> std::shared_ptr<IPrimitives> {
//                 return std::make_shared<Torus>(s);
//             }},
//         {"boxes",
//             [](const libconfig::Setting &s) -> std::shared_ptr<IPrimitives> {
//                 return std::make_shared<Boxes>(s);
//             }}
//     };
//     if (primitiveMap.count(type)) {
//         return primitiveMap[type](setting);
//     } else {
//         throw std::runtime_error("Unknown primitive type: " + type);
//     }
// }
