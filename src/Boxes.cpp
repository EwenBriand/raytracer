/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Boxes.cpp
*/

#include "Boxes.hpp"

Primitive::Boxes::Boxes(const libconfig::Setting &setting)
{
    try {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("scale", _scale);
        if (!_scale)
            _scale = 1;
        setting.lookupValue("w", _width);
        _width *= _scale;
        std::cout << _width << std::endl;
        setting.lookupValue("h", _height);
        _height *= _scale;
        std::cout << _height << std::endl;
        setting.lookupValue("d", _depth);
        _depth *= _scale;
        std::cout << _depth << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Primitive::Boxes::~Boxes()
{
}

bool Primitive::Boxes::hit(const Math::Ray &ray)
{
    float tmin = (_position.getX() - ray.getOrigin().getX())
        / ray.getDirection().getX();
    float tmax = ((_position.getX() + _width) - ray.getOrigin().getX())
        / ray.getDirection().getX();
    float tymin = (_position.getY() - ray.getOrigin().getY())
        / ray.getDirection().getY();
    float tymax = ((_position.getY() + _height) - ray.getOrigin().getY())
        / ray.getDirection().getY();
    float tzmin = (_position.getZ() - ray.getOrigin().getZ())
        / ray.getDirection().getZ();
    float tzmax = ((_position.getZ() + _depth) - ray.getOrigin().getZ())
        / ray.getDirection().getZ();

    float t0 = std::max(std::max(std::min(tmin, tmax), std::min(tymin, tymax)),
        std::min(tzmin, tzmax));
    float t1 = std::min(std::min(std::max(tmin, tmax), std::max(tymin, tymax)),
        std::max(tzmin, tzmax));

    if (t1 < 0)
        return false;
    if (t0 > t1)
        return false;
    _intersexe = ray.getOrigin() + (ray.getDirection() * (t0));
    return true;
}

Color Primitive::Boxes::getColor() const
{
    return _color;
}

Math::Point3D Primitive::Boxes::getIntersexe() const
{
    return _intersexe;
}

Math::Vector3D Primitive::Boxes::getNormal() const
{
    Math::Vector3D vertices[8] = {{0, 0, 0}, {_position.getX(), 0, 0},
        {_position.getX(), _position.getY(), 0}, {0, _position.getY(), 0},
        {0, 0, _position.getZ()}, {_position.getX(), 0, _position.getZ()},
        {_position.getX(), _position.getY(), _position.getZ()},
        {0, _position.getY(), _position.getZ()}};

    // Define the indices of the faces of the box
    int pos = 0;
    int indices[6][4] = {
        {0, 1, 2, 3}, // bottom face
        {1, 5, 6, 2}, // front face
        {5, 4, 7, 6}, // top face
        {4, 0, 3, 7}, // back face
        {0, 4, 5, 1}, // left face
        {3, 2, 6, 7}  // right face
    };

    // Calculate the normal vectors of each face
    Math::Vector3D normals[6];
    for (int i = 0; i < 6; i++) {
        Math::Vector3D v1 = vertices[indices[i][1]] - vertices[indices[i][0]];
        Math::Vector3D v2 = vertices[indices[i][2]] - vertices[indices[i][1]];
        normals[i] = (v1.cross(v2)).normalize();
    }

    if (_intersexe.getY() == _position.getY() + _height)
        pos = 0;
    else if (_intersexe.getZ() == _position.getZ() - _depth)
        pos = 1;
    else if (_intersexe.getZ() == _position.getZ() - _depth)
        pos = 2;
    else if (_intersexe.getY() == _position.getY() + _height)
        pos = 3;
    else if (_intersexe.getX() == _position.getX() - _width)
        pos = 4;
    else if (_intersexe.getX() == _position.getX() + _width)
        pos = 5;

    return normals[pos];
}

void Primitive::Boxes::setIntersexe(const Math::Point3D &value)
{
    _intersexe = value;
}
