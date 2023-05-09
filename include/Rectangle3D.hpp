/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Rectangle3D.hpp
*/

#ifndef A8A2227A_391C_476E_A9D5_40DB53734EFF
#define A8A2227A_391C_476E_A9D5_40DB53734EFF

#include <iostream>

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace Math {
    class Rectangle3D
    {
        private:
            /**
             * @brief Origin of the rectangle
             *
             */
            Math::Point3D _origin;
            /**
             * @brief Bottom vector of the rectangle
             *
             */
            Math::Vector3D _bottom;
            /**
             * @brief Left vector of the rectangle
             *
             */
            Math::Vector3D _left;
        public:
            Rectangle3D() = default;
            /**
             * @brief Construct a new Rectangle 3D object
             *
             * @param origin
             * @param bottom
             * @param left
             */
            Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &bottom, const Math::Vector3D &left);
            ~Rectangle3D();
            /**
             * @brief Get the Origin object
             *
             * @return Math::Point3D
             */
            Math::Point3D getOrigin() const;
            /**
             * @brief Get the Bottom object
             *
             * @return Math::Vector3D
             */
            Math::Vector3D getBottom() const;
            /**
             * @brief Get the Left object
             *
             * @return Math::Vector3D
             */
            Math::Vector3D getLeft() const;
            /**
             * @brief Get the point at the given u and v
             *
             * @param u
             * @param v
             * @return Math::Point3D
             */
            Math::Point3D pointAt(float u, float v) const;
    };
}

#endif /* A8A2227A_391C_476E_A9D5_40DB53734EFF */
