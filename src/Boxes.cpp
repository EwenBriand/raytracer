/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Boxes.cpp
*/

#include "Boxes.hpp"

Boxes::Boxes(const libconfig::Setting &setting)
{
    try
    {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("w", _width);
        std::cout << _width << std::endl;
        setting.lookupValue("h", _height);
        std::cout << _height << std::endl;
        setting.lookupValue("d", _depth);
        std::cout << _depth << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Boxes::~Boxes()
{
}

bool Boxes::hit(const Ray &ray)
{
    if (ray.getOrigin().getX() > _position.getX() && ray.getOrigin().getX() < _position.getX() + _width)
        return false;
    return false;
}
