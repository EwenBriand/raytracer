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

class IPrimitives {
  protected:
    Math::Point3D _position;
    Math::Point3D _intersexe = Math::Point3D(0, 0, 0);
    Color _color;
    Math::Vector3D _rotation;
    bool _isNeon = false;

  public:
    virtual ~IPrimitives() = default;
    virtual bool hit(const Ray &ray) = 0;
    virtual Color getColor() const = 0;
    virtual Math::Point3D getIntersexe() const = 0;
    virtual Math::Vector3D getNormal() const = 0;
    virtual void setIntersexe(const Math::Point3D &value) = 0;
    virtual bool isNeon() const = 0;
};

#endif /* D0BF50CA_8DC2_492F_8976_E70BDD268926 */
