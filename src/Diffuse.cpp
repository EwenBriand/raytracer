/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Diffuse.cpp
*/

#include "Diffuse.hpp"

Light::Diffuse::Diffuse(const libconfig::Setting &setting)
{
    _point = Math::Point3D(0, 0, 0);
    try {
        _point.setPoint(setting["point"]);
        std::cout << _point << std::endl;
        _direction.setVector3D(setting["vector"]);
        std::cout << "direction " << _direction << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Light::Diffuse::~Diffuse()
{
}

Color Light::Diffuse::getColor() const
{
    return _color;
}

Math::Point3D Light::Diffuse::getPoint() const
{
    return _point;
}

Math::Vector3D Light::Diffuse::getDirection() const
{
    return _direction;
}

Primitive::IPrimitives *Light::Diffuse::getPrimitive() const
{
    return nullptr;
}

float Light::Diffuse::getPower() const
{
    return 0;
}

bool Light::Diffuse::is_cut( __attribute__((unused)) const Math::Point3D &point, __attribute__((unused)) const std::vector<std::shared_ptr<Primitive::IPrimitives>> primitives) const
{
    return false;
}

Color Light::Diffuse::define_color(__attribute__((unused)) Math::Point3D inter,__attribute__((unused)) Math::Vector3D normal, const Color &origin_color, double t, bool is_cut)
{
    int r = (unsigned char) ((1.0 - t) * origin_color.getR() + t * _color.getR());
    int g = (unsigned char) ((1.0 - t) * origin_color.getG() + t * _color.getG());
    int b = (unsigned char) ((1.0 - t) * origin_color.getB() + t * _color.getB());

    if (is_cut) {
        r = (unsigned char) ((1.0 - t) * origin_color.getR() + t * 0);
        g = (unsigned char) ((1.0 - t) * origin_color.getG() + t * 0);
        b = (unsigned char) ((1.0 - t) * origin_color.getB() + t * 0);
    }

    Color newColor = Color(r, g, b);

    return newColor;
}
