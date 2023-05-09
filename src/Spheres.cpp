/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Spheres.cpp
*/

#include "Spheres.hpp"

Primitive::Spheres::Spheres(const libconfig::Setting &setting)
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
        setting.lookupValue("scale", _scale);
        if (!_scale) {
            _scale = 1;
        } else {
            _radius *= _scale;
        }
        std::cout << "scale " << _scale << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Primitive::Spheres::~Spheres()
{
}

bool Primitive::Spheres::hit(const Math::Ray &ray)
{
    float a = ray.getDirection().dot(ray.getDirection());
    float b = 2 * ray.getDirection().dot(ray.getOrigin() - _position);
    float c = (ray.getOrigin() - _position).dot(ray.getOrigin() - _position) - _radius * _radius;
    float delta = b * b - 4 * a * c;
    if (delta < 0)
        return false;
    float t1 = (-b + sqrt(delta)) / (2 * a);
    float t2 = (-b - sqrt(delta)) / (2 * a);
    if (t1 > 0 && t2 > 0)
        return true;
    return false;
}

Color Primitive::Spheres::getColor() const
{
    return _color;
}
