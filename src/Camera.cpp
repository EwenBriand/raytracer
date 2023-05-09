/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

Camera::Camera(const libconfig::Setting &setting)
{
    try
    {
        setting["resolution"].lookupValue("width", _resolution[0]);
        std::cout << _resolution[0] << std::endl;
        setting["resolution"].lookupValue("height", _resolution[1]);
        std::cout << _resolution[1] << std::endl;
        _position.setPoint(setting["position"]);
        std::cout << _position << std::endl;
        _rotation.setPoint(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("fieldOfView", _fieldOfView);
        std::cout << _fieldOfView << std::endl;
        _screen = Math::Rectangle3D(Math::Point3D(-0.5, -0.5, 0), Math::Vector3D(1.0,0.0,0.0), Math::Vector3D(0.0,1.0,0.0));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Camera::Camera(Math::Point3D position, Math::Rectangle3D screen)
{
    _position = position;
    _screen = screen;
}

int Camera::getResolutionX() const
{
    return _resolution[0];
}

int Camera::getResolutionY() const
{
    return _resolution[1];
}

float Camera::getFieldOfView() const
{
    return _fieldOfView;
}

Math::Point3D Camera::getPosition() const
{
    return _position;
}

Math::Point3D Camera::getRotation() const
{
    return _rotation;
}

Math::Ray Camera::getRay(float x, float y) const
{
    Math::Point3D origin = _position;
    Math::Point3D point = _screen.pointAt(x, y);
    Math::Vector3D direction = point - origin;
    return Math::Ray(origin, direction);
}
