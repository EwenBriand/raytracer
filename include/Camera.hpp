/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Camera.hpp
*/

#ifndef DEA2BC57_EC1D_42F7_906B_3BD0CB06AC65
#define DEA2BC57_EC1D_42F7_906B_3BD0CB06AC65

#include <libconfig.h++>
#include <array>
#include <iostream>

#include "Point3D.hpp"
#include "Rectangle3D.hpp"
#include "Ray.hpp"

class Camera
{
    private:
        int _resolution[2];
        Math::Point3D _position;
        Math::Point3D _rotation;
        float _fieldOfView;
        Rectangle3D _screen;
    public:
        Camera(const libconfig::Setting &setting);
        Camera(Math::Point3D position, Rectangle3D screen);
        Camera() = default;
        ~Camera() = default;
        int getResolutionX() const;
        int getResolutionY() const;
        Math::Point3D getPosition() const;
        Math::Point3D getRotation() const;
        float getFieldOfView() const;
        Ray getRay(float x, float y) const;
};

#endif /* DEA2BC57_EC1D_42F7_906B_3BD0CB06AC65 */
