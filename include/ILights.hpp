/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** ILights
*/

#ifndef D7777FC2_C7BD_4BDA_BC6A_E26393F1EFD6
#define D7777FC2_C7BD_4BDA_BC6A_E26393F1EFD6

#include <iostream>
#include <vector>
#include <libconfig.h++>

#include "Color.hpp"
#include "IPrimitives.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

class ILights {
  public:
    virtual ~ILights() = default;
    virtual Color getColor() const = 0;
    virtual Math::Point3D getPoint() const = 0;
    virtual Math::Vector3D getDirection() const = 0;
    virtual IPrimitives *getPrimitive() const = 0;
    // virtual float getPower() const = 0;

    virtual bool is_cut(const Math::Point3D &point,
        const std::vector<IPrimitives *> primitives) const = 0;
    virtual Color define_color(
        const Color &origin_color, double distance, bool is_cut) = 0;
};

#endif /* D7777FC2_C7BD_4BDA_BC6A_E26393F1EFD6 */
