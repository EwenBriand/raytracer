/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Cones.cpp
*/

#include "Cones.hpp"

Cones::Cones(const libconfig::Setting &setting)
{
    try
    {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("limited", _isLimited);
        std::cout << _isLimited << std::endl;
        if (_isLimited)
        {
            setting.lookupValue("r", _radius);
            std::cout << _radius << std::endl;
            setting.lookupValue("h", _height);
            std::cout << _height << std::endl;
            if (_height == 0)
                _angle = 0;
            else
                _angle = 2 * atan(_radius / _height);
            std::cout << _angle << std::endl;
        } else {
            setting.lookupValue("angle", _angle);
            std::cout << _angle << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Cones::~Cones()
{
}

bool Cones::hit(const Ray &ray)
{
    if (ray.getDirection().getY() == 0)
        return false;
    return false;
}

Color Cones::getColor() const
{
    return _color;
}