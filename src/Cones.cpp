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
            if (_height == 0)
                _angle = 0;
            else
                _angle = 2 * atan(_radius / _height);
            std::cout << _angle << std::endl;
        } else {
            setting.lookupValue("angle", _angle);
            std::cout << _angle << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Cones::~Cones()
{}

bool Cones::hitUnlimited(const Ray &ray)
{
    double a = ray.getDirection().getX() * ray.getDirection().getX() + ray.getDirection().getY() * ray.getDirection().getY() - _angle * _angle * ray.getDirection().getZ() * ray.getDirection().getZ();
    double b = 2 * (ray.getOrigin().getX() * ray.getDirection().getX() + ray.getOrigin().getY() * ray.getDirection().getY() - _angle * _angle * (ray.getOrigin().getZ() - _position.getZ()) * ray.getDirection().getZ() - _position.getX() * ray.getDirection().getX() - _position.getY() * ray.getDirection().getY() + _angle * _angle * (ray.getOrigin().getZ() - _position.getZ()) * ray.getDirection().getY() * (_position.getY() + 1) / (_position.getX() * _position.getX() + (_position.getY() + 1) * (_position.getY() + 1)) - _angle * _angle * (ray.getOrigin().getZ() - _position.getZ()) * ray.getDirection().getX() * _position.getX() / (_position.getX() * _position.getX() + (_position.getY() + 1) * (_position.getY() + 1)));
    double c = ray.getOrigin().getX() * ray.getOrigin().getX() + ray.getOrigin().getY() * ray.getOrigin().getY() - _angle * _angle * (ray.getOrigin().getZ() - _position.getZ()) * (ray.getOrigin().getZ() - _position.getZ()) - 2 * (ray.getOrigin().getX() * _position.getX() + ray.getOrigin().getY() * _position.getY() - _angle * _angle * (ray.getOrigin().getZ() - _position.getZ()) * (_position.getY() + 1) / (_position.getX() * _position.getX() + (_position.getY() + 1) * (_position.getY() + 1)) * _position.getY() / (_position.getY() + 1) - _angle * _angle * (ray.getOrigin().getZ() - _position.getZ()) * _position.getX() / (_position.getX() * _position.getX() + (_position.getY() + 1) * (_position.getY() + 1)) * _position.getX() / _position.getX());

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }

    double t1 = (-b + std::sqrt(discriminant)) / (2 * a);
    double t2 = (-b - std::sqrt(discriminant)) / (2 * a);

    if (t1 < 0 && t2 < 0) {
        return false;
    }

    return true;
}

bool Cones::hitLimited(const Ray &ray)
{
    double a = ray.getDirection().getX() * ray.getDirection().getX() + ray.getDirection().getY() * ray.getDirection().getY() - ray.getDirection().getZ() * ray.getDirection().getZ() * _radius * _radius / (_height * _height);
    double b = 2 * (ray.getOrigin().getX() * ray.getDirection().getX() + ray.getOrigin().getY() * ray.getDirection().getY() - (ray.getOrigin().getZ() - _position.getZ()) * ray.getDirection().getZ() * _radius * _radius / (_height * _height) - _position.getX() * ray.getDirection().getX() - _position.getY() * ray.getDirection().getY() + (ray.getOrigin().getZ() - _position.getZ()) * _radius * _radius * _height / (_height * _height));
    double c = ray.getOrigin().getX() * ray.getOrigin().getX() + ray.getOrigin().getY() * ray.getOrigin().getY() - (ray.getOrigin().getZ() - _position.getZ()) * (ray.getOrigin().getZ() - _position.getZ()) * _radius * _radius / (_height * _height) - 2 * (ray.getOrigin().getX() * _position.getX() + ray.getOrigin().getY() * _position.getY() - (ray.getOrigin().getZ() - _position.getZ()) * _height) + _position.getX() * _position.getX() + _position.getY() * _position.getY() - _height * _height;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }

    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);

    if (t1 < 0 && t2 < 0) {
        return false;
    }

    return true;
}

bool Cones::hit(const Ray &ray)
{
    if (_isLimited)
        return hitLimited(ray);
    else
        return hitUnlimited(ray);
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