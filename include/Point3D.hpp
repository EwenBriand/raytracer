/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Point3D.hpp
*/

#ifndef A9DE60FF_0966_4C55_9EB0_8ECE064F4322
#define A9DE60FF_0966_4C55_9EB0_8ECE064F4322

#include <iostream>
#include <libconfig.h++>

#include "Vector3D.hpp"

namespace Math
{
    class Vector3D;

    class Point3D {
      private:
        float _x;
        float _y;
        float _z;

      public:
        Point3D(float x, float y, float z);
        Point3D() = default;
        ~Point3D();
        void setPoint(float x, float y, float z);
        void setPoint(const libconfig::Setting &setting);
        float getX() const;
        float getY() const;
        float getZ() const;
        Point3D cross(const Point3D &point) const;
        float dot(const Point3D &point) const;
        float distance(const Point3D &point) const;
        Vector3D vectorTo(const Math::Point3D &point) const;
        Point3D normalize() const;
    };

} // namespace Math
std::ostream &operator<<(std::ostream &s, const Math::Point3D &point);
Math::Point3D operator-(
    const Math::Point3D &point1, const Math::Point3D &point2);
Math::Point3D operator+(
    const Math::Point3D &point1, const Math::Vector3D &vector);
Math::Point3D operator+(const Math::Point3D &point1, float f);
bool operator!=(const Math::Point3D &point1, const Math::Point3D &point2);
bool operator==(const Math::Point3D &point1, const Math::Point3D &point2);

#endif /* A9DE60FF_0966_4C55_9EB0_8ECE064F4322 */
