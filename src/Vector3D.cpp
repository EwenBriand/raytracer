/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Vector3D.cpp
*/

#include "Vector3D.hpp"

Math::Vector3D::Vector3D()
{
    _x = 0.0;
    _y = 0.0;
    _z = 0.0;
}

Math::Vector3D::Vector3D(float x, float y, float z)
{
    _x = x;
    _y = y;
    _z = z;
}

Math::Vector3D::Vector3D(const Point3D &point)
{
    _x = point.getX();
    _y = point.getY();
    _z = point.getZ();
}

float Math::Vector3D::length() const
{
    return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
}

float Math::Vector3D::getX() const
{
    return _x;
}

float Math::Vector3D::getY() const
{
    return _y;
}

float Math::Vector3D::getZ() const
{
    return _z;
}

void Math::Vector3D::setVector3D(float x, float y, float z)
{
    _x = x;
    _y = y;
    _z = z;
}

void Math::Vector3D::setVector3D(const libconfig::Setting &setting)
{
    try {
        setting.lookupValue("x", _x);
        setting.lookupValue("y", _y);
        setting.lookupValue("z", _z);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &s, const Math::Vector3D &vector)
{
    s << "Vector3D(" << vector.getX() << ", " << vector.getY() << ", "
      << vector.getZ() << ")";
    return s;
}

float Math::Vector3D::dot(const Vector3D &other) const
{
    return _x * other._x + _y * other._y + _z * other._z;
}

Math::Vector3D Math::Vector3D::normalize() const
{
    float length = sqrt(_x * _x + _y * _y + _z * _z);
    return Vector3D(_x / length, _y / length, _z / length);
}

Math::Vector3D operator*(const Math::Vector3D &vector, const float &scalar)
{
    return Math::Vector3D(vector.getX() * scalar, vector.getY() * scalar,
        vector.getZ() * scalar);
}

Math::Vector3D operator/(const Math::Vector3D &vector, const float &scalar)
{
    return Math::Vector3D(vector.getX() / scalar, vector.getY() / scalar,
        vector.getZ() / scalar);
}

Math::Vector3D operator-(const Math::Vector3D &a, const Math::Vector3D &b)
{
    Math::Vector3D result = {
        a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()};
    return result;
}

Math::Vector3D operator+(const Math::Vector3D &a, const Math::Vector3D &b)
{
    Math::Vector3D result = {
        a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ()};
    return result;
}

Math::Vector3D Math::Vector3D::cross(const Vector3D &other) const
{
    return Math::Vector3D(_y * other._z - _z * other._y,
        _z * other._x - _x * other._z, _x * other._y - _y * other._x);
}
