/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Torus.hpp
*/

#ifndef D4E88905_726D_4F79_AFCA_7257590B44E5
#define D4E88905_726D_4F79_AFCA_7257590B44E5

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"

namespace Primitive
{
    class Torus : public IPrimitives {
      private:
        /**
         * @brief radius minor of the torus
         *
         */
        float _radiusMinor;
        /**
         * @brief radius major of the torus
         *
         */
        float _radiusMajor;

      public:
        /**
         * @brief Construct a new Torus object from a libconfig::Setting
         *
         * @param setting
         */
        Torus(const libconfig::Setting &setting);
        ~Torus() override;
        bool hit(const Math::Ray &ray) override;
        Color getColor() const override;
        Math::Point3D getIntersexe() const override;
        Math::Vector3D getNormal() const override;
        void setIntersexe(const Math::Point3D &value) override;
        bool isNeon() const override;
    };
} // namespace Primitive

#endif /* D4E88905_726D_4F79_AFCA_7257590B44E5 */
