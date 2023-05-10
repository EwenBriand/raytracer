/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Planes.hpp
*/

#ifndef F2AA8B37_71DB_4B85_9E0D_E45189DC1639
#define F2AA8B37_71DB_4B85_9E0D_E45189DC1639

#include <iostream>
#include "IPrimitives.hpp"
#include <libconfig.h++>

namespace Primitive
{
    class Planes : public IPrimitives {
      private:
        /**
         * @brief Point 1 of the plane
         *
         */
        Math::Point3D _p2;
        /**
         * @brief Point 2 of the plane
         *
         */
        Math::Point3D _p3;
        /**
         * @brief Normal of the plane
         *
         */
        Math::Vector3D _normal;

      public:
        /**
         * @brief Construct a new Planes object from a libconfig::Setting
         *
         * @param setting
         */
        Planes(const libconfig::Setting &setting);
        ~Planes() override;
        bool hit(const Math::Ray &ray) override;
        Color getColor() const override;
        Math::Point3D getIntersexe() const override;
        Math::Vector3D getNormal() const override;
        void setIntersexe(const Math::Point3D &value) override;
        bool isNeon() const override;
    };
} // namespace Primitive

#endif /* F2AA8B37_71DB_4B85_9E0D_E45189DC1639 */
