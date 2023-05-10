/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Boxes.cpp
*/

#include "Boxes.hpp"

Primitive::Boxes::Boxes(const libconfig::Setting &setting)
{
    try {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("scale", _scale);
        if (!_scale)
            _scale = 1;
        setting.lookupValue("w", _width);
        _width *= _scale;
        std::cout << _width << std::endl;
        setting.lookupValue("h", _height);
        _height *= _scale;
        std::cout << _height << std::endl;
        setting.lookupValue("d", _depth);
        _depth *= _scale;
        std::cout << _depth << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Primitive::Boxes::~Boxes()
{
}

bool Primitive::Boxes::hit(const Math::Ray &ray)
{
    float tmin = (_position.getX() - ray.getOrigin().getX())
        / ray.getDirection().getX();
    float tmax = ((_position.getX() + _width) - ray.getOrigin().getX())
        / ray.getDirection().getX();
    float tymin = (_position.getY() - ray.getOrigin().getY())
        / ray.getDirection().getY();
    float tymax = ((_position.getY() + _height) - ray.getOrigin().getY())
        / ray.getDirection().getY();
    float tzmin = (_position.getZ() - ray.getOrigin().getZ())
        / ray.getDirection().getZ();
    float tzmax = ((_position.getZ() + _depth) - ray.getOrigin().getZ())
        / ray.getDirection().getZ();

    float t0 = std::max(std::max(std::min(tmin, tmax), std::min(tymin, tymax)),
        std::min(tzmin, tzmax));
    float t1 = std::min(std::min(std::max(tmin, tmax), std::max(tymin, tymax)),
        std::max(tzmin, tzmax));

    if (t1 < 0)
        return false;
    if (t0 > t1)
        return false;
    _intersexe = ray.getOrigin() + (ray.getDirection() * (t0));
    return true;
}

Color Primitive::Boxes::getColor() const
{
    return _color;
}

Math::Point3D Primitive::Boxes::getIntersexe() const
{
    return _intersexe;
}

Math::Vector3D Primitive::Boxes::getNormal() const
{
    double eps = 1e-5;

    if (std::abs(_intersexe.getX() - _position.getX()) < eps)
        return Math::Vector3D(-1, 0, 0);
    else if (std::abs(_intersexe.getX() - (_position.getX() + _width)) < eps)
        return Math::Vector3D(1, 0, 0);
    else if (std::abs(_intersexe.getY() - _position.getY()) < eps)
        return Math::Vector3D(0, -1, 0);
    else if (std::abs(_intersexe.getY() - (_position.getY() + _height)) < eps)
        return Math::Vector3D(0, 1, 0);
    else if (std::abs(_intersexe.getZ() - _position.getZ()) < eps)
        return Math::Vector3D(0, 0, -1);
    else if (std::abs(_intersexe.getZ() - (_position.getZ() + _depth)) < eps)
        return Math::Vector3D(0, 0, 1);

    return Math::Vector3D(0, 0, 0); // Default case, should not happen
}

void Primitive::Boxes::setIntersexe(const Math::Point3D &value)
{
    _intersexe = value;
}
