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
    float tmin = (_position.getX() - ray.getOrigin().getX()) / ray.getDirection().getX();
    float tmax = ((_position.getX() + _width) - ray.getOrigin().getX()) / ray.getDirection().getX();
    float tymin = (_position.getY() - ray.getOrigin().getY()) / ray.getDirection().getY();
    float tymax = ((_position.getY() + _height) - ray.getOrigin().getY()) / ray.getDirection().getY();
    float tzmin = (_position.getZ() - ray.getOrigin().getZ()) / ray.getDirection().getZ();
    float tzmax = ((_position.getZ() + _depth) - ray.getOrigin().getZ()) / ray.getDirection().getZ();

    float t0 = std::max(std::max(std::min(tmin, tmax), std::min(tymin, tymax)), std::min(tzmin, tzmax));
    float t1 = std::min(std::min(std::max(tmin, tmax), std::max(tymin, tymax)), std::max(tzmin, tzmax));

    if (t1 < 0) {
        return false;
    }
    if (t0 > t1) {
        return false;
    }
    return true;
}

Color Boxes::getColor() const
{
    return _color;
}
