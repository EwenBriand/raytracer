/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Triangles.cpp
*/

#include "Triangles.hpp"

Triangles::Triangles(const libconfig::Setting &setting)
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

Triangles::~Triangles()
{
}

bool Triangles::hit(const Ray &ray)
{
    _intersexe = Math::Point3D(0, 0, 0);
    return false;
}

Color Triangles::getColor() const
{
    return _color;
}

Math::Point3D Triangles::getIntersexe() const
{
    return _intersexe;
}

Math::Vector3D Triangles::getNormal() const
{
    return Math::Vector3D(0, 0, 0);
}

void Triangles::setIntersexe(const Math::Point3D &value)
{
    _intersexe = value;
}
