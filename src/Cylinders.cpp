/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Cylinders.cpp
*/

#include "Cylinders.hpp"

Cylinders::Cylinders(const libconfig::Setting &setting)
{
    try {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("r", _radius);
        std::cout << _radius << std::endl;
        setting.lookupValue("limited", _isLimited);
        std::cout << _isLimited << std::endl;
        if (_isLimited)
            setting.lookupValue("h", _height);
        else
            _height = 0;
        std::cout << _height << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Cylinders::~Cylinders()
{
}

bool Cylinders::hit(const Ray &ray)
{
    double a =
        pow(ray.getDirection().getX(), 2) + pow(ray.getDirection().getZ(), 2);
    double b = 2
        * (ray.getDirection().getX()
                * (ray.getOrigin().getX() - _position.getX())
            + ray.getDirection().getZ()
                * (ray.getOrigin().getZ() - _position.getZ()));
    double c = pow(ray.getOrigin().getX() - _position.getX(), 2)
        + pow(ray.getOrigin().getZ() - _position.getZ(), 2) - pow(_radius, 2);

    double discriminant = pow(b, 2) - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    double t = (-b - sqrt(discriminant)) / (2 * a);

    if (t < 0) {
        return false;
    }
    double y = ray.getOrigin().getY() + t * ray.getDirection().getY();

    if (_isLimited
        && (y < _position.getY() || y > _position.getY() + _height)) {
        return false;
    }

    _intersexe = ray.getOrigin() + ray.getDirection() * t;
    return true;
}

Color Cylinders::getColor() const
{
    return _color;
}

Math::Point3D Cylinders::getIntersexe() const
{
    return _intersexe;
}

Math::Vector3D Cylinders::getNormal() const
{
    return Math::Vector3D(0, 0, 0);
}

void Cylinders::setIntersexe(const Math::Point3D &value)
{
    _intersexe = value;
}

bool Cylinders::isNeon() const
{
    return _isNeon;
}