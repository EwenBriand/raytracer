/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Ray.hpp
*/

#ifndef C8F844E7_AF1C_470E_8C1B_FBBE3770109E
#define C8F844E7_AF1C_470E_8C1B_FBBE3770109E

#include <iostream>

#include "Vector3D.hpp"
#include "Point3D.hpp"

namespace Math {
    class Ray
    {
        private:
            /**
             * @brief Origin of the ray
             *
             */
            Math::Point3D _origin;
            /**
             * @brief Direction of the ray
             *
             */
            Math::Vector3D _direction;
        public:
            Ray() = default;
            /**
             * @brief Construct a new Ray object
             *
             * @param origin
             * @param direction
             */
            Ray(const Math::Point3D &origin, const Math::Vector3D &direction);
            ~Ray() = default;
            /**
             * @brief Get the Origin object
             *
             * @return Math::Point3D
             */
            Math::Point3D getOrigin() const;
            /**
             * @brief Get the Direction object
             *
             * @return Math::Vector3D
             */
            Math::Vector3D getDirection() const;
    };
}

#endif /* C8F844E7_AF1C_470E_8C1B_FBBE3770109E */
