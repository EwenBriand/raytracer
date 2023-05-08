/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Planes.cpp
*/

#include "Planes.hpp"

Planes::Planes(const libconfig::Setting &setting)
{
    try {
        _position.setPoint(setting["p1"]);
        std::cout << _position << std::endl;
        _p2.setPoint(setting["p2"]);
        std::cout << _p2 << std::endl;
        _p3.setPoint(setting["p3"]);
        std::cout << _p3 << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        Math::Point3D tmp((_p2 - _position).cross(_p3 - _position));
        std::cout << tmp << std::endl;
        _normal.setVector3D(tmp.getX(), tmp.getY(), tmp.getZ());
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Planes::~Planes()
{
}

bool Planes::hit(const Ray &ray)
{
    double denominator = _normal.dot(ray.getDirection());

    // Check if the ray is parallel to the plane
    if (denominator == 0) {
        return false;
    }

    // Compute the t parameter of the intersection point
    double t =
        ((_position.getX() - ray.getOrigin().getX()) * _normal.getX()
            + (_position.getY() - ray.getOrigin().getY()) * _normal.getY()
            + (_position.getZ() - ray.getOrigin().getZ()) * _normal.getZ())
        / denominator;

    // Check if the intersection point is in front of the ray origin
    if (t < 0) {
        return false;
    }

    _intersexe = ray.getOrigin() + (ray.getDirection() * (t));

    return true;
}

Color Planes::getColor() const
{
    return _color;
}

Math::Point3D Planes::getIntersexe() const
{
    return _intersexe;
}

Math::Vector3D Planes::getNormal() const
{
    return Math::Vector3D(0, 0, 0);
}
