/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Triangles.hpp
*/

#ifndef E6FB8944_93AB_44F6_84DC_8F965B067DC4
#define E6FB8944_93AB_44F6_84DC_8F965B067DC4

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"

namespace Primitive
{
    class Triangles : public IPrimitives {
      private:
        /**
         * @brief Point 1 of the triangle
         *
         */
        Math::Point3D _sommet1;
        /**
         * @brief Point 2 of the triangle
         *
         */
        Math::Point3D _sommet2;
        /**
         * @brief Point 3 of the triangle
         *
         */
        Math::Point3D _sommet3;
        /**
         * @brief Normal of the triangle
         *
         */
        Math::Point3D _normal;

      public:
        /**
         * @brief Construct a new Triangles object from a libconfig::Setting
         *
         * @param setting
         */
        Triangles(const libconfig::Setting &setting);
        ~Triangles() override;
        bool hit(const Math::Ray &ray) override;
        Color getColor() const override;
        Math::Point3D getIntersexe() const override;
        Math::Vector3D getNormal() const override;
        void setIntersexe(const Math::Point3D &value) override;
    };
} // namespace Primitive
#endif /* E6FB8944_93AB_44F6_84DC_8F965B067DC4 */
