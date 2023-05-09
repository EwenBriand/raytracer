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
        /**
         * @brief Resolution of the camera
         *
         */
        int _resolution[2];
        /**
         * @brief Position of the camera
         *
         */
        Math::Point3D _position;
        /**
         * @brief Rotation of the camera
         *
         */
        Math::Point3D _rotation;
        /**
         * @brief Field of view of the camera
         *
         */
        float _fieldOfView;
        /**
         * @brief Screen of the camera
         *
         */
        Math::Rectangle3D _screen;
    public:
        /**
         * @brief Construct a new Camera object from a libconfig::Setting
         *
         * @param setting
         */
        Camera(const libconfig::Setting &setting);
        /**
         * @brief Construct a new Camera object
         *
         * @param position
         * @param screen
         */
        Camera(Math::Point3D position, Math::Rectangle3D screen);
        Camera() = default;
        ~Camera() = default;
        /**
         * @brief Get the resolution X of the camera
         * @return resolution X of the camera
         */
        int getResolutionX() const;
        /**
         * @brief Get the resolution Y of the camera
         * @return resolution Y of the camera
         */
        int getResolutionY() const;
        /**
         * @brief Get the position of the camera
         * @return position of the camera
         */
        Math::Point3D getPosition() const;
        /**
         * @brief Get the rotation of the camera
         * @return rotation of the camera
         */
        Math::Point3D getRotation() const;
        /**
         * @brief Get the field of view of the camera
         * @return field of view of the camera
         */
        float getFieldOfView() const;
        /**
         * @brief Get the ray from the camera to the screen
         * @param x
         * @param y
         * @return ray from the camera to the screen
         */
        Math::Ray getRay(float x, float y) const;
};

#endif /* DEA2BC57_EC1D_42F7_906B_3BD0CB06AC65 */
