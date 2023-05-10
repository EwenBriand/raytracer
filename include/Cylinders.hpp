/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Cylinders.hpp
*/

#ifndef CAEFB936_1C79_48F5_B406_9DC688A7D20F
#define CAEFB936_1C79_48F5_B406_9DC688A7D20F

#include <iostream>
#include "IPrimitives.hpp"
#include <libconfig.h++>

namespace Primitive
{
    class Cylinders : public IPrimitives {
      private:
        /**
         * @brief The radius of the cylinder
         *
         */
        float _radius;
        /**
         * @brief The height of the cylinder
         *
         */
        int _height;
        /**
         * @brief The scale of the cylinder
         *
         */
        float scale;
        /**
         * @brief Is the cylinder limited
         *
         */
        bool _isLimited;

      public:
        /**
         * @brief Construct a new Cylinders object from a libconfig::Setting
         *
         * @param setting
         */
        Cylinders(const libconfig::Setting &setting);
        ~Cylinders() override;
        bool hit(const Math::Ray &ray) override;
        Color getColor() const override;
        Math::Point3D getIntersexe() const override;
        Math::Vector3D getNormal() const override;
        void setIntersexe(const Math::Point3D &value) override;
    };
} // namespace Primitive

#endif /* CAEFB936_1C79_48F5_B406_9DC688A7D20F */
