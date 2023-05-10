/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Directional.cpp
*/

#include "Directional.hpp"
#include <cmath>
#include "Spheres.hpp"

Light::Directional::Directional(const libconfig::Setting &setting)
{
    try {
        _point.setPoint(setting["point"]);
        std::cout << _point << std::endl;
        _direction.setVector3D(setting["vector"]);
        std::cout << "direction " << _direction << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        setting["power"].lookupValue("p", _power);
        std::cout << "power " << _power << std::endl;
        _primitive = new Primitive::Spheres(setting["spheres"]);
        std::cout << "primitive " << _primitive << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Light::Directional::~Directional()
{
}

Color Light::Directional::getColor() const
{
    return _color;
}

Math::Point3D Light::Directional::getPoint() const
{
    return _point;
}

Math::Vector3D Light::Directional::getDirection() const
{
    return _direction;
}

Primitive::IPrimitives *Light::Directional::getPrimitive() const
{
    return _primitive;
}

float Light::Directional::getPower() const
{
    return _power;
}

bool Light::Directional::is_cut(const Math::Point3D &point, const std::vector<std::shared_ptr<Primitive::IPrimitives>> primitives) const
{
    bool hited = false;
    Math::Ray ray = Math::Ray(point, point.vectorTo(_point));
    for (long unsigned int k = 0; k < primitives.size(); k++) {
        Math::Point3D tmp(point);
        if (primitives[k]->hit(ray)) {
            if (primitives[k]->getIntersexe() != point) {
                hited = true;
                break;
            }
        }
    }
    return hited;
}

Color Light::Directional::blinn_phong(Math::Point3D inter, Math::Vector3D dir, Math::Vector3D normal, Color c)
{
    Math::Vector3D light_direction = (_point - inter).normalize();
    Math::Vector3D halfway_direction = (light_direction + dir).normalize();

    float diffuse_factor = normal.dot(light_direction) > 0.0 ? normal.dot(light_direction) : 0.0;
    Color diffuse_term = (c * _color) * diffuse_factor;

    return diffuse_term.normalized();
}

Color Light::Directional::define_color(Math::Point3D inter, Math::Vector3D normal, const Color &origin_color, double t, bool is_cut)
{
    Color blended = blinn_phong(inter, inter.vectorTo(_point), normal, _color);
    int r =
        (unsigned char) ((1.0 - t) * origin_color.getR() + t * blended.getR());
    int g =
        (unsigned char) ((1.0 - t) * origin_color.getG() + t * blended.getG());
    int b =
        (unsigned char) ((1.0 - t) * origin_color.getB() + t * blended.getB());

    if (is_cut) {
        r = (unsigned char) ((1.0 - t) * origin_color.getR() + t * 0);
        g = (unsigned char) ((1.0 - t) * origin_color.getG() + t * 0);
        b = (unsigned char) ((1.0 - t) * origin_color.getB() + t * 0);
    }

    Color newColor = Color(r, g, b);

    return newColor;
}
