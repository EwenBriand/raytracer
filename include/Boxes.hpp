/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Boxes.hpp
*/

#ifndef D428BE3F_E861_4C23_A929_D74DB520103F
#define D428BE3F_E861_4C23_A929_D74DB520103F

#include <iostream>
#include "IPrimitives.hpp"
#include <libconfig.h++>

namespace Primitive
{
    class Boxes : public IPrimitives {
      private:
        /**
         * @brief The width of the box
         */
        float _width;
        /**
         * @brief The height of the box
         */
        float _height;
        /**
         * @brief The depth of the box
         */
        float _depth;

      public:
        /**
         * @brief Construct a new Boxes object from a libconfig::Setting
         *
         * @param setting
         */
        Boxes(const libconfig::Setting &setting);
        ~Boxes() override;
        bool hit(const Math::Ray &ray) override;
        Color getColor() const override;
        Math::Point3D getIntersexe() const override;
        Math::Vector3D getNormal() const override;
    };
} // namespace Primitive

#endif /* D428BE3F_E861_4C23_A929_D74DB520103F */
