/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Point3D.cpp
*/

#include "Point3D.hpp"

Math::Point3D::Point3D(float x, float y, float z): _x(x), _y(y), _z(z)
{
}

Math::Point3D::~Point3D()
{
}

void Math::Point3D::setPoint(float x, float y, float z)
{
    _x = x;
    _y = y;
    _z = z;
}

void Math::Point3D::setPoint(const libconfig::Setting &setting)
{
    try
    {
        setting.lookupValue("x", _x);
        setting.lookupValue("y", _y);
        setting.lookupValue("z", _z);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

float Math::Point3D::getX() const
{
    return _x;
}

float Math::Point3D::getY() const
{
    return _y;
}

float Math::Point3D::getZ() const
{
    return _z;
}

Math::Point3D Math::Point3D::cross(const Math::Point3D &point) const
{
    return Point3D(_y * point.getZ() - _z * point.getY(), _z * point.getX() - _x * point.getZ(), _x * point.getY() - _y * point.getX());
}

std::ostream &operator<<(std::ostream &os, const Math::Point3D &point)
{
    os << "x: " << point.getX() << " y: " << point.getY() << " z: " << point.getZ();
    return os;
}

Math::Point3D operator-(const Math::Point3D &point1, const Math::Point3D &point2)
{
    return Math::Point3D(point1.getX() - point2.getX(), point1.getY() - point2.getY(), point1.getZ() - point2.getZ());
}

Math::Point3D operator+(const Math::Point3D &point1, const Math::Vector3D &vector)
{
    return Math::Point3D(point1.getX() + vector.getX(), point1.getY() + vector.getY(), point1.getZ() + vector.getZ());
}
