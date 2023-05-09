/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Vector3D.hpp
*/

#ifndef EC1D4C7D_1C94_4522_BD2A_74CFFAA13F3E
#define EC1D4C7D_1C94_4522_BD2A_74CFFAA13F3E

#include <iostream>
#include <cmath>
#include <libconfig.h++>

#include "Point3D.hpp"

namespace Math
{
    class Point3D;
    class Vector3D
    {
        private:
            /**
             * @brief x coordinate of the vector
             *
             */
            float _x;
            /**
             * @brief y coordinate of the vector
             *
             */
            float _y;
            /**
             * @brief z coordinate of the vector
             *
             */
            float _z;

        public:
            Vector3D();
            /**
             * @brief Construct a new Vector3D object
             *
             * @param x
             * @param y
             * @param z
             */
            Vector3D(float x, float y, float z);
            /**
             * @brief Construct a new Vector3D object
             *
             * @param point
             */
            Vector3D(const Point3D &point);
            ~Vector3D() = default;
            /**
             * @brief Set the Vector3D object
             *
             * @param x
             * @param y
             * @param z
             */
            void setVector3D(float x, float y, float z);
            /**
             * @brief Set the Vector3D object from a libconfig::Setting
             *
             * @param setting
             */
            void setVector3D(const libconfig::Setting &setting);
            /**
             * @brief Get the X coordinate
             *
             * @return float
             */
            float getX() const;
            /**
             * @brief Get the Y coordinate
             *
             * @return float
             */
            float getY() const;
            /**
             * @brief Get the Z coordinate
             *
             * @return float
             */
            float getZ() const;
            /**
             * @brief Get the length of the vector
             *
             * @return float
             */
            float length() const;
            /**
             * @brief Do the dot product between two vectors
             *
             * @param other
             * @return float
             */
            float dot(const Vector3D& other) const;
    };

}
std::ostream &operator<<(std::ostream &s, const Math::Vector3D &vector);
Math::Vector3D operator*(const Math::Vector3D &vector, const float &scalar);

#endif /* EC1D4C7D_1C94_4522_BD2A_74CFFAA13F3E */
