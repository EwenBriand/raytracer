/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Lights.hpp
*/

#ifndef BAA422D6_AA17_4BCE_BA94_AA717CFA876B
#define BAA422D6_AA17_4BCE_BA94_AA717CFA876B

#ifndef A6948A32_3AC8_4519_A3CC_636F8DF1EEF8
    #define A6948A32_3AC8_4519_A3CC_636F8DF1EEF8

    #include <iostream>
    #include <memory>
    #include <vector>
    #include <libconfig.h++>

    #include "Color.hpp"
    #include "ILights.hpp"
    #include "IPrimitives.hpp"
    #include "Point3D.hpp"
    #include "Vector3D.hpp"

class Diffuse : public ILights {
  private:
    Math::Point3D _point;
    Color _color;
    Math::Vector3D _direction;

  public:
    Diffuse(const libconfig::Setting &setting);
    Diffuse() = default;
    ~Diffuse();

    Color getColor() const override;
    Math::Point3D getPoint() const override;
    Math::Vector3D getDirection() const override;
    Primitive::IPrimitives *getPrimitive() const override;
    float getPower() const override;

    bool is_cut(const Math::Point3D &point,
        const std::vector<std::shared_ptr<Primitive::IPrimitives>> primitives)
        const override;

    Color define_color(Math::Point3D inter, Math::Vector3D normal,
        const Color &origin_color, double t, bool is_cut) override;
};

#endif /* A6948A32_3AC8_4519_A3CC_636F8DF1EEF3 */

#endif /* BAA422D6_AA17_4BCE_BA94_AA717CFA876B */
