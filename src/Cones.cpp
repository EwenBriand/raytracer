/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Cones.cpp
*/

#include "Cones.hpp"

Cones::Cones(const libconfig::Setting &setting)
{
    _type = pluginType::PRIMITIVE;
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
            std::cout << "la" << std::endl;
            if (_height == 0)
                _angle = 0;
            else
                _angle = atan(_height / (sqrtf(_radius * _radius + _height * _height))) * 180 / M_PI;
            std::cout << _angle << std::endl;
        } else {
            setting.lookupValue("angle", _angle);
            std::cout << _angle << std::endl;
            _height = 1000000000;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Cones::~Cones()
{}

bool Cones::hit(const Ray &ray)
{
    double a = pow(ray.getDirection().getX(), 2) + pow(ray.getDirection().getZ(), 2) - pow(ray.getDirection().getY(), 2) * pow(tan(_angle), 2);
    double b = 2 * (ray.getDirection().getX() * (ray.getOrigin().getX() - _position.getX())
                    + ray.getDirection().getZ() * (ray.getOrigin().getZ() - _position.getZ())
                    - ray.getDirection().getY() * (ray.getOrigin().getY() - _position.getY()) * pow(tan(_angle), 2));
    double c = pow(ray.getOrigin().getX() - _position.getX(), 2) + pow(ray.getOrigin().getZ() - _position.getZ(), 2) - pow(ray.getOrigin().getY() - _position.getY(), 2) * pow(tan(_angle), 2);

    double discriminant = pow(b, 2) - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    double t = (-b - sqrt(discriminant)) / (2 * a);

    if (t < 0) {
        return false;
    }
    double y = ray.getOrigin().getY() + t * ray.getDirection().getY();

    if (y > _position.getY() && y < _position.getY() + _height)
        return true;
    return false;
}

Color Cones::getColor() const
{
    return _color;
}

void Cones::setType(pluginType type)
{
    _type = type;
}

int Cones::getType() const
{
    return _type;
}