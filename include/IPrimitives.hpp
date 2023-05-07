/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** IPrimitives.hpp
*/

#ifndef D0BF50CA_8DC2_492F_8976_E70BDD268926
#define D0BF50CA_8DC2_492F_8976_E70BDD268926

#include <iostream>

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Color.hpp"
#include "Ray.hpp"

class IPrimitives {
    protected:
        Math::Point3D _position;
        Color _color;
        Math::Vector3D _rotation;
    public:
        virtual ~IPrimitives() = default;
        virtual bool hit(const Ray &ray) = 0;
        virtual Color getColor() const = 0;
};

#endif /* D0BF50CA_8DC2_492F_8976_E70BDD268926 */
