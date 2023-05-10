/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** AbstractFactory.cpp
*/

#include "AbstractFactory.hpp"
#include <functional>
#include <map>

AbstractFactory::AbstractFactory()
{
    _primitives["spheres"] = std::make_shared<Primitive::SphereBuilder>();
    _primitives["planes"] = std::make_shared<Primitive::PlaneBuilder>();
    _primitives["triangles"] = std::make_shared<Primitive::TriangleBuilder>();
    _primitives["cones"] = std::make_shared<Primitive::ConeBuilder>();
    _primitives["cylinders"] = std::make_shared<Primitive::CylinderBuilder>();
    _primitives["torus"] = std::make_shared<Primitive::TorusBuilder>();
    _primitives["boxes"] = std::make_shared<Primitive::BoxBuilder>();

    _lights["ambiante"] = std::make_shared<Light::DiffuseBuilder>();
    _lights["directional"] = std::make_shared<Light::DirectionalBuilder>();
}

std::shared_ptr<Primitive::IPrimitives> AbstractFactory::createPrimitive(const std::string type, const libconfig::Setting &setting)
{
    if (_primitives.count(type))
        return _primitives[type]->build(setting);
    else
        throw std::runtime_error("Unknown primitive type: " + type);
}

std::shared_ptr<Light::ILights> AbstractFactory::createLight(const std::string type, const libconfig::Setting &setting)
{
    printf("type: %s\n", type.c_str());
    if (_lights.count(type))
        return _lights[type]->build(setting);
    else
        throw std::runtime_error("Unknown light type: " + type);
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
