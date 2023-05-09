/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Point3D.hpp
*/

#ifndef A9DE60FF_0966_4C55_9EB0_8ECE064F4322
#define A9DE60FF_0966_4C55_9EB0_8ECE064F4322

#include <iostream>
#include "Vector3D.hpp"
#include <libconfig.h++>

namespace Math
{
    class Vector3D;

    class Point3D {
      private:
        /**
         * @brief x coordinate
         *
         */
        float _x;
        /**
         * @brief y coordinate
         *
         */
        float _y;
        /**
         * @brief z coordinate
         *
         */
        float _z;

      public:
        /**
         * @brief Construct a new Point 3D object
         *
         * @param x
         * @param y
         * @param z
         */
        Point3D(float x, float y, float z);
        Point3D() = default;
        ~Point3D();
        /**
         * @brief Set the Point object
         *
         * @param x
         * @param y
         * @param z
         */
        void setPoint(float x, float y, float z);
        /**
         * @brief Set the Point object from a libconfig::Setting
         *
         * @param setting
         */
        void setPoint(const libconfig::Setting &setting);
        /**
         * @brief Get the X object
         *
         * @return float
         */
        float getX() const;
        /**
         * @brief Get the Y object
         *
         * @return float
         */
        float getY() const;
        /**
         * @brief Get the Z object
         *
         * @return float
         */
        float getZ() const;
        /**
         * @brief Do a cross product between two points
         *
         * @return Point3D
         */
        Point3D cross(const Point3D &point) const;
        /**
         * @brief Do a dot product between two points
         *
         * @return float
         */
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
