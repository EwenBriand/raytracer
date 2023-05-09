/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Cones.cpp
*/

#include "Cones.hpp"

Primitive::Cones::Cones(const libconfig::Setting &setting)
{
    try {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("limited", _isLimited);
        std::cout << _isLimited << std::endl;
        if (_isLimited) {
            setting.lookupValue("r", _radius);
            std::cout << _radius << std::endl;
            setting.lookupValue("h", _height);
            std::cout << _height << std::endl;
            std::cout << "la" << std::endl;
            if (_height == 0)
                _angle = 0;
            else
                _angle = atan(_height
                             / (sqrtf(_radius * _radius + _height * _height)))
                    * 180 / M_PI;
            setting.lookupValue("scale", _scale);
            if (!_scale)
                _scale = 1;
            _radius *= _scale;
            _height *= _scale;
            std::cout << "scale " << _scale << std::endl;
            std::cout << _angle << std::endl;
        } else {
            setting.lookupValue("angle", _angle);
            std::cout << _angle << std::endl;
            _height = 1000000000;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Primitive::Cones::~Cones()
{
}

bool Primitive::Cones::hit(const Math::Ray &ray)
{
    double k = pow(tan(_angle), 2);
    double a = ray.getDirection().dot(ray.getDirection()) - (1 + k) * pow(ray.getDirection().getY(), 2);
    double b = 2 * (ray.getDirection().dot(ray.getOrigin() - _position) - (1 + k) * ray.getDirection().getY() * (ray.getOrigin().getY() - _position.getY()));
    double c = (ray.getOrigin() - _position).dot(ray.getOrigin() - _position) - (1 + k) * pow(ray.getOrigin().getY() - _position.getY(), 2);

    double discriminant = pow(b, 2) - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    double t = (-b - sqrt(discriminant)) / (2 * a);

    if (t < 0) {
        return false;
    }
    double y = ray.getOrigin().getY() + t * ray.getDirection().getY();
    if (y > _position.getY() && y < _position.getY() + _height) {
        _intersexe = ray.getOrigin() + ray.getDirection() * t;
        return true;
    }
    return false;
}

Color Primitive::Cones::getColor() const
{
    return _color;
}

Math::Point3D Primitive::Cones::getIntersexe() const
{
    return _intersexe;
}

Math::Vector3D Primitive::Cones::getNormal() const
{
    Math::Vector3D normal = Math::Vector3D(
        2 * (_intersexe.getX() - _position.getX()),
        2 * (_intersexe.getY() - _position.getY()) * -pow(tan(_angle), 2),
        2 * (_intersexe.getZ() - _position.getZ())
    );
    return normal.normalize();
}

void Primitive::Cones::setIntersexe(const Math::Point3D &value)
{
    _intersexe = value;
}
