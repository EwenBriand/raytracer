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


class Camera
{
    private:
        int _resolution[2];
        Point3D _position;
        Point3D _rotation;
        float _fieldOfView;
    public:
        Camera(const libconfig::Setting &setting);
        Camera() = default;
        ~Camera() = default;
        int getResolutionX() const;
        int getResolutionY() const;
        Point3D getPosition() const;
        Point3D getRotation() const;
        float getFieldOfView() const;
};

#endif /* DEA2BC57_EC1D_42F7_906B_3BD0CB06AC65 */
