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

class Rectangle3D
{
    private:
        Math::Point3D _origin;
        Math::Vector3D _bottom;
        Math::Vector3D _left;
    public:
        Rectangle3D() = default;
        Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &bottom, const Math::Vector3D &left);
        ~Rectangle3D();
        Math::Point3D getOrigin() const;
        Math::Vector3D getBottom() const;
        Math::Vector3D getLeft() const;
        Math::Point3D pointAt(float u, float v) const;
};

#endif /* A8A2227A_391C_476E_A9D5_40DB53734EFF */
