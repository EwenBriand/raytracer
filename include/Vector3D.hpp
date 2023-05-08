/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Vector3D.hpp
*/

#ifndef EC1D4C7D_1C94_4522_BD2A_74CFFAA13F3E
#define EC1D4C7D_1C94_4522_BD2A_74CFFAA13F3E

#include <cmath>
#include <iostream>
#include <libconfig.h++>

#include "Point3D.hpp"

namespace Math
{
    class Point3D;
    class Vector3D {
      private:
        float _x;
        float _y;
        float _z;

      public:
        Vector3D();
        Vector3D(float x, float y, float z);
        Vector3D(const Point3D &point);
        ~Vector3D() = default;
        void setVector3D(float x, float y, float z);
        void setVector3D(const libconfig::Setting &setting);
        float getX() const;
        float getY() const;
        float getZ() const;
        float length() const;
        float dot(const Vector3D &other) const;
        Vector3D normalize() const;
    };

} // namespace Math
std::ostream &operator<<(std::ostream &s, const Math::Vector3D &vector);
Math::Vector3D operator*(const Math::Vector3D &vector, const float &scalar);
Math::Vector3D operator-(const Math::Vector3D &v1, const Math::Vector3D v2);
Math::Vector3D operator+(const Math::Vector3D &v1, const Math::Vector3D v2);

#endif /* EC1D4C7D_1C94_4522_BD2A_74CFFAA13F3E */
