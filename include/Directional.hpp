/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Lights.hpp
*/

#ifndef B9F6121A_55A2_42E9_9357_547E2F111F51
#define B9F6121A_55A2_42E9_9357_547E2F111F51

#ifndef A6948A32_3AC8_4519_A3CC_636F8DF1EEF5
    #define A6948A32_3AC8_4519_A3CC_636F8DF1EEF5

    #include <iostream>
    #include <memory>
    #include <vector>
    #include <libconfig.h++>

    #include "Color.hpp"
    #include "ILights.hpp"
    #include "IPrimitives.hpp"
    #include "Point3D.hpp"
    #include "Vector3D.hpp"

namespace Light {
  class Directional : public ILights {
    private:
      Math::Point3D _point;
      Color _color;
      Math::Vector3D _direction;
      Primitive::IPrimitives *_primitive;
      float _power = 10.0;

    public:
    /**
     * @brief Construct a new Directional object from a libconfig::Setting
     *
     * @param setting
     */
      Directional(const libconfig::Setting &setting);
      Directional() = default;
      ~Directional();
      Color getColor() const override;
      Math::Point3D getPoint() const override;
      Math::Vector3D getDirection() const override;
      Primitive::IPrimitives *getPrimitive() const override;
      float getPower() const override;
      bool is_cut(const Math::Point3D &point, const std::vector<std::shared_ptr<Primitive::IPrimitives>> primitives) const override;
      /**
       * @brief Blinn-Phong shading
       *
       * @param inter
       * @param dir
       * @param normal
       * @param c
       * @return Color
       */
      Color blinn_phong(Math::Point3D inter, Math::Vector3D dir, Math::Vector3D normal, Color c);
      Color define_color(Math::Point3D inter, Math::Vector3D normal, const Color &origin_color, double t, bool is_cut) override;
  };
}

#endif /* A6948A32_3AC8_4519_A3CC_636F8DF1EEF3 */

#endif /* B9F6121A_55A2_42E9_9357_547E2F111F51 */
