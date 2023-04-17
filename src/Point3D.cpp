/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Point3D.cpp
*/

#include "Point3D.hpp"

Point3D::Point3D(int x, int y, int z): _x(x), _y(y), _z(z)
{
}

Point3D::~Point3D()
{
}

void Point3D::setPoint(int x, int y, int z)
{
    _x = x;
    _y = y;
    _z = z;
}

void Point3D::setPoint(const libconfig::Setting &setting)
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

int Point3D::getX() const
{
    return _x;
}

int Point3D::getY() const
{
    return _y;
}

int Point3D::getZ() const
{
    return _z;
}

Point3D Point3D::cross(const Point3D &point) const
{
    return Point3D(_y * point.getZ() - _z * point.getY(), _z * point.getX() - _x * point.getZ(), _x * point.getY() - _y * point.getX());
}

std::ostream &operator<<(std::ostream &os, const Point3D &point)
{
    os << "x: " << point.getX() << " y: " << point.getY() << " z: " << point.getZ();
    return os;
}

Point3D operator-(const Point3D &point1, const Point3D &point2)
{
    return Point3D(point1.getX() - point2.getX(), point1.getY() - point2.getY(), point1.getZ() - point2.getZ());
}