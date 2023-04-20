/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Spheres.cpp
*/

#include "Spheres.hpp"

Spheres::Spheres(const libconfig::Setting &setting)
{
    try
    {
        _position.setPoint(setting);
        std::cout << _position << std::endl;

        setting.lookupValue("r", _radius);
        if (setting.exists("r") == true)
            std::cout << _radius << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Spheres::Spheres(Math::Point3D position, double radius)
{
    _position = position;
    _radius = radius;
}

Spheres::~Spheres()
{
}

bool Spheres::hit(const Ray &ray)
{
    Math::Vector3D oc = ray.getOrigin() - _position;
    double a = ray.getDirection().length();
    double half_b = oc.dot(ray.getDirection());
    double c = oc.length() - _radius * _radius;
    double discriminant = half_b * half_b - a * c;

    if (discriminant < 0) {
        return false;
    }
    else {
        return true;
    }
}
