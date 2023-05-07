/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Torus.cpp
*/

#include "Torus.hpp"

Torus::Torus(const libconfig::Setting &setting)
{
    try
    {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setVector3D(setting["rotation"]);
        std::cout << _rotation << std::endl;
        setting.lookupValue("r", _radiusMinor);
        std::cout << _radiusMinor << std::endl;
        setting.lookupValue("R", _radiusMajor);
        std::cout << _radiusMajor << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Torus::~Torus()
{
}

bool Torus::hit(const Ray &ray)
{
    // Définir les constantes pour la formule du tore
    const float R = _radiusMajor;
    const float r = _radiusMinor;

    // Définir les constantes pour la formule du rayon
    const Math::Vector3D o = ray.getDirection();
    const Math::Vector3D d = ray.getOrigin();

    // Calculer les coefficients pour la formule du 4ème degré
    const float A = d.dot(d);
    const float B = 2 * o.dot(d);
    const float C = o.dot(o) - R * R - r * r;
    const float D = 2 * B * C + 4 * R * r * d.getY() * d.getY();
    const float E = 4 * A * C + 2 * B * B + 4 * R * r * (d.getX() * d.getX() + d.getZ() * d.getZ() - 2 * d.getY() * d.getY());
    const float F = 4 * A * B + 8 * R * r * o.getY() * d.getY();
    const float G = 4 * A * (R * R - r * r) + B * B + 4 * R * r * (o.getX() * o.getX() + o.getZ() * o.getZ() - 2 * o.getY() * o.getY())
                   + 4 * R * r * d.getY() * d.getY() * (2 * o.getY() * o.getY() - R * R - r * r);

    // Utiliser la formule de Ferrari pour trouver les racines du polynôme du 4ème degré
    const float a = E / A;
    const float b = D / A;
    const float c = C / A;

    const float p = (3 * a - b * b) / 3;
    const float q = (2 * b * b * b - 9 * a * b + 27 * c) / 27;

    const float delta = q * q / 4 + p * p * p / 27;

    if (delta > 0) {
        // Cas de deux racines réelles et une racine complexe
        const float u = std::cbrt(-q / 2 + std::sqrt(delta));
        const float v = std::cbrt(-q / 2 - std::sqrt(delta));

        const float x1 = u + v - b / 3;
        const float x2_real = -(u + v) / 2 - b / 3;
        const float x2_imag = std::abs(std::sqrt(3.0f) * (u - v) / 2);

        // On teste les racines réelles pour savoir si elles sont sur le rayon
        if (x1 > 0 && (ray.getOrigin() + ray.getDirection() * x1).getY() * (ray.getOrigin() + ray.getDirection() * x1).getY()
                     <= (R * R + r * r - x1 * x1 - 2 * r * r * std::sqrt((R * R - x1 * x1) / (R * R + r * r)))) {
            return true;
                }
        if (x2_real > 0 && (ray.getOrigin() + ray.getDirection() * x2_real).getY() * (ray.getOrigin() + ray.getDirection() * x2_real).getY()
                          <= (R * R + r * r - x2_real * x2_real - 2 * r * r * std::sqrt((R * R - x2_real * x2_real) / (R * R + r * r)))) {
            return true;
        }
    } else if (delta == 0) {
        // Cas de trois racines réelles
        const float u = std::cbrt(-q / 2);
        const float x1 = 2 * u - b / 3;
        const float x2 = -u - b / 3;

        // On teste les racines réelles pour savoir si elles sont sur le rayon
        if (x1 > 0 && (ray.getOrigin() + ray.getDirection() * x1).getY() * (ray.getOrigin() + ray.getDirection() * x1).getY()
                     <= (R * R + r * r - x1 * x1 - 2 * r * r * std::sqrt((R * R - x1 * x1) / (R * R + r * r)))) {
            return true;
        }
        if (x2 > 0 && (ray.getOrigin() + ray.getDirection() * x2).getY() * (ray.getOrigin() + ray.getDirection() * x2).getY()
                     <= (R * R + r * r - x2 * x2 - 2 * r * r * std::sqrt((R * R - x2 * x2) / (R * R + r * r)))) {
            return true;
        }
    } else {
        // Cas de trois racines complexes conjuguées
        const float alpha = -q / 2;
        const float beta = std::sqrt(-delta);

        const Math::Vector3D root1 = Math::Vector3D(std::pow(alpha * alpha + beta * beta, 1.0f / 6.0f), 0, 0);
        const Math::Vector3D root2 = Math::Vector3D(-alpha / 2, beta / 2, 0);
        const Math::Vector3D root3 = Math::Vector3D(-alpha / 2, -beta / 2, 0);

        // On teste les racines réelles pour savoir si elles sont sur le rayon
        if (root1.getY() == 0 && root1.getX() > 0 && root1.getX() * root1.getX() + root1.getZ() * root1.getZ() <= R * R + r * r) {
            const float y2 = root1.getX() * root1.getX() + root1.getZ() * root1.getZ() - R * R - r * r;
            if (std::abs(root1.getY()) <= std::sqrt(4 * r * r * (R * R - y2) / ((R * R + r * r - y2) * (R * R + r * r - y2) - 4 * R * R * r * r))) {
                return true;
            }
        }
        if (root2.getY() == 0 && root2.getX() > 0 && root2.getX() * root2.getX() + root2.getZ() * root2.getZ() <= R * R + r * r) {
            const float y2 = root2.getX() * root2.getX() + root2.getZ() * root2.getZ() - R * R - r * r;
            if (std::abs(root2.getY()) <= std::sqrt(4 * r * r * (R * R - y2) / ((R * R + r * r - y2) * (R * R + r * r - y2) - 4 * R * R * r * r))) {
                return true;
            }
        }
        if (root3.getY() == 0 && root3.getX() > 0 && root3.getX() * root3.getX() + root3.getZ() * root3.getZ() <= R * R + r * r) {
            const float y2 = root3.getX() * root3.getX() + root3.getZ() * root3.getZ() - R * R - r * r;
            if (std::abs(root3.getY()) <= std::sqrt(4 * r * r * (R * R - y2) / ((R * R + r * r - y2) * (R * R + r * r - y2) - 4 * R * R * r * r))) {
                return true;
            }
        }
    }

    return false;
}

Color Torus::getColor() const
{
    return _color;
}
