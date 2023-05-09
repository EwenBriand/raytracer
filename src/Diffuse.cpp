/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Diffuse.cpp
*/

#include "Diffuse.hpp"

Diffuse::Diffuse(const libconfig::Setting &setting)
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

Diffuse::~Diffuse()
{
}

Color Diffuse::getColor() const
{
    return _color;
}

Math::Point3D Diffuse::getPoint() const
{
    return _point;
}

Math::Vector3D Diffuse::getDirection() const
{
    return _direction;
}

Primitive::IPrimitives *Diffuse::getPrimitive() const
{
    return nullptr;
}

float Diffuse::getPower() const
{
    return 0;
}

bool Diffuse::is_cut(const Math::Point3D &point,
    const std::vector<std::shared_ptr<Primitive::IPrimitives>> primitives)
    const
{
    return false;
}

Color Diffuse::define_color(Math::Point3D inter, Math::Vector3D normal,
    const Color &origin_color, double t, bool is_cut)
{
    int r =
        (unsigned char) ((1.0 - t) * origin_color.getR() + t * _color.getR());
    int g =
        (unsigned char) ((1.0 - t) * origin_color.getG() + t * _color.getG());
    int b =
        (unsigned char) ((1.0 - t) * origin_color.getB() + t * _color.getB());

    if (is_cut) {
        r = (unsigned char) ((1.0 - t) * origin_color.getR() + t * 0);
        g = (unsigned char) ((1.0 - t) * origin_color.getG() + t * 0);
        b = (unsigned char) ((1.0 - t) * origin_color.getB() + t * 0);
    }

    Color newColor = Color(r, g, b);

    return newColor;
}

// 1 get lumiere pos
// si directionnelle
// 2 get lumiere direction
// 3 get lumiere color
// 4 get lumiere intensity
// 5 calculer la distance entre la lumiere et le point
// 6 calculer le vecteur entre la lumiere et le point
// 7 definir la couleur en fonction de la distance,
//                      obstacle,
//                      l'éloignement du vecteur directionnel,
//                      l'intensité et
//                      la couleur de la lumiere
// sinon
// obstacle entre lumiere et point
//  2 calculer la distance entre la lumiere et le point
//  3 calculer la couleur en fonction de la distance,
//                      l'intensité et
//                      la couleur de la lumiere

// OU :
// Partire du point concerner et check si le ray d'origine le point et de
// direction la lumiere touche un truc alors c'est un obstacle sinon calculer
// la nouvelle couleuren mixant les deux couleurs
