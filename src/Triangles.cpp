/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Triangles.cpp
*/

#include "Triangles.hpp"

Primitive::Triangles::Triangles(const libconfig::Setting &setting)
{
    try {
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        _sommet1.setPoint(setting["sommet1"]);
        std::cout << _sommet1 << std::endl;
        _sommet2.setPoint(setting["sommet2"]);
        std::cout << _sommet2 << std::endl;
        _sommet3.setPoint(setting["sommet3"]);
        std::cout << _sommet3 << std::endl;
        _normal = (_sommet2 - _sommet1).cross(_sommet3 - _sommet1);
        std::cout << _normal << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Primitive::Triangles::~Triangles()
{
}

bool Primitive::Triangles::hit(const Math::Ray &ray)
{
    float t = (_sommet1 - ray.getOrigin()).dot(_normal)
        / ray.getDirection().dot(_normal);
    Math::Point3D p = ray.getOrigin() + ray.getDirection() * t;
    Math::Point3D v1 = _sommet2 - _sommet1;
    Math::Point3D v2 = _sommet3 - _sommet1;
    Math::Point3D v3 = p - _sommet1;
    float dot11 = v1.dot(v1);
    float dot12 = v1.dot(v2);
    float dot13 = v1.dot(v3);
    float dot22 = v2.dot(v2);
    float dot23 = v2.dot(v3);
    float invDenom = 1 / (dot11 * dot22 - dot12 * dot12);
    float u = (dot22 * dot13 - dot12 * dot23) * invDenom;
    float v = (dot11 * dot23 - dot12 * dot13) * invDenom;
    if ((u >= 0) && (v >= 0) && (u + v <= 1))
        return true;
    return false;
}

Color Primitive::Triangles::getColor() const
{
    return _color;
}

Math::Point3D Primitive::Triangles::getIntersexe() const
{
    return _intersexe;
}

Math::Vector3D Primitive::Triangles::getNormal() const
{
    return Math::Vector3D(0, 0, 0);
}

void Primitive::Triangles::setIntersexe(const Math::Point3D &value)
{
    _intersexe = value;
}
