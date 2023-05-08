/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Directional.cpp
*/

#include "Directional.hpp"
#include "Spheres.hpp"

Directional::Directional(const libconfig::Setting &setting)
{
    try {
        _point.setPoint(setting["point"]);
        std::cout << _point << std::endl;

        _direction.setVector3D(setting["vector"]);
        std::cout << "direction " << _direction << std::endl;

        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _primitive = new Spheres(setting["spheres"]);
        std::cout << "primitive " << _primitive << std::endl;
        _power = 10;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

Directional::~Directional()
{
}

Color Directional::getColor() const
{
    return _color;
}

Math::Point3D Directional::getPoint() const
{
    return _point;
}

Math::Vector3D Directional::getDirection() const
{
    return _direction;
}

IPrimitives *Directional::getPrimitive() const
{
    return _primitive;
}

float Directional::getPower() const
{
    return _power;
}

bool Directional::is_cut(const Math::Point3D &point,
    const std::vector<IPrimitives *> primitives) const
{
    bool hited = false;
    Ray ray = Ray(point, point.vectorTo(_point));

    // std::cout << "\n\npoint A " << point << "\npoint B " << _point
    //           << std::endl;
    // std::cout << "direction " << ray.getDirection() << std::endl;

    for (long unsigned int k = 0; k < primitives.size(); k++) {
        Math::Point3D tmp(point);
        if (primitives[k]->hit(ray)) {
            // std::cout << "point " << point << std::endl;
            // std::cout << "tmp " << tmp << std::endl;
            double dist = primitives[k]->getIntersexe().distance(point);
            // if (((dist < 0) ? (dist * (-1)) : dist) > 0.0001) {
            if (primitives[k]->getIntersexe() != point) {
                // std::cout << "\nhited" << std::endl;
                // std::cout << "point inter " <<
                // primitives[k]->getIntersexe()
                //           << "\npoint start " << point << std::endl;
                // std::cout << (primitives[k]->getIntersexe() != point) <<
                // std::endl; std::cout << "false = " << false <<
                // std::endl;
                hited = true;
                break;
            }
            // std::cout << "dist " << dist << std::endl;
        }
    }

    // std::cout << "hited " << hited << false << std::endl;

    return hited;
}

Color Directional::define_color(
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
// direction la lumiere touche un truc alors c'est un obstacle sinon
// calculer la nouvelle couleuren mixant les deux couleurs