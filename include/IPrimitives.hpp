/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** IPrimitives.hpp
*/

#ifndef D0BF50CA_8DC2_492F_8976_E70BDD268926
#define D0BF50CA_8DC2_492F_8976_E70BDD268926

#include <iostream>

#include "Color.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

namespace Primitive
{
    class IPrimitives {
      protected:
        /**
         * @brief The position of the primitive
         *
         */
        Math::Point3D _position;
        /**
         * @brief The color of the primitive
         *
         */
        Color _color;
        /**
         * @brief The rotation of the primitive
         *
         */
        Math::Vector3D _rotation;
        /**
         * @brief The scale of the primitive
         *
         */
        float _scale;
        Math::Point3D _intersexe = Math::Point3D(0, 0, 0);

      public:
        virtual ~IPrimitives() = default;
        /**
         * @brief Check if the ray hit the primitive
         * @return true if the ray hit the primitive
         */
        virtual bool hit(const Math::Ray &ray) = 0;
        /**
         * @brief Get the color of the primitive
         * @return the color of the primitive
         */
        virtual Color getColor() const = 0;
        virtual Math::Point3D getIntersexe() const = 0;
        virtual Math::Vector3D getNormal() const = 0;
    };
} // namespace Primitive

#endif /* D0BF50CA_8DC2_492F_8976_E70BDD268926 */
