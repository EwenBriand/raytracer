/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Lights.hpp
*/

#ifndef A6948A32_3AC8_4519_A3CC_636F8DF1EEF5
#define A6948A32_3AC8_4519_A3CC_636F8DF1EEF5

#include <iostream>
#include <vector>
#include <libconfig.h++>

#include "Color.hpp"
#include "ILights.hpp"
#include "IPrimitives.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

class Directional : public ILights {
  private:
    Math::Point3D _point;
    Color _color;
    Math::Vector3D _direction;
    IPrimitives *_primitive;
    // float _power;

  public:
    Directional(const libconfig::Setting &setting);
    Directional() = default;
    ~Directional();

    Color getColor() const;
    Math::Point3D getPoint() const;
    Math::Vector3D getDirection() const;
    IPrimitives *getPrimitive() const;
    // float getPower() const;

    bool is_cut(const Math::Point3D &point,
        const std::vector<IPrimitives *> primitives) const;

    // Color blinn_phong(Math::Point3D &inter, Math::Vector3D &dir, )
    Color define_color(
        const Color &origin_color, double distance, bool is_cut) override;
};

#endif /* A6948A32_3AC8_4519_A3CC_636F8DF1EEF3 */
