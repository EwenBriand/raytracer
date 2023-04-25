/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Rectangle3D.cpp
*/

#include "Rectangle3D.hpp"

Rectangle3D::Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &bottom, const Math::Vector3D &left)
{
    _origin = origin;
    _bottom = bottom;
    _left = left;
}

Rectangle3D::~Rectangle3D()
{
}

Math::Point3D Rectangle3D::getOrigin() const
{
    return _origin;
}

Math::Vector3D Rectangle3D::getBottom() const
{
    return _bottom;
}

Math::Vector3D Rectangle3D::getLeft() const
{
    return _left;
}

Math::Point3D Rectangle3D::pointAt(float u, float v) const
{
    return _origin + _bottom * u + _left * v;
}
