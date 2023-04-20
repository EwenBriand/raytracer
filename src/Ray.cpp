/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Ray.cpp
*/

#include "Ray.hpp"

Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction)
{
    _origin = origin;
    _direction = direction;
}

Math::Point3D Ray::getOrigin() const
{
    return _origin;
}

Math::Vector3D Ray::getDirection() const
{
    return _direction;
}
