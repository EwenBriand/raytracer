/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Torus.cpp
*/

#include "Torus.hpp"

Torus::Torus(const libconfig::Setting &setting)
{
    try {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("r", _radiusMinor);
        std::cout << _radiusMinor << std::endl;
        setting.lookupValue("R", _radiusMajor);
        std::cout << _radiusMajor << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Torus::~Torus()
{
}

bool Torus::hit(const Ray &ray)
{
    _intersexe = Math::Point3D(0, 0, 0);
    return false;
}

Color Torus::getColor() const
{
    return _color;
}

Math::Point3D Torus::getIntersexe() const
{
    return _intersexe;
}

Math::Vector3D Torus::getNormal() const
{
    return Math::Vector3D(0, 0, 0);
}

void Torus::setIntersexe(const Math::Point3D &value)
{
    _intersexe = value;
}
