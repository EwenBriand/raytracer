/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Lights.hpp
*/

#ifndef A6948A32_3AC8_4519_A3CC_636F8DF1EEF3
#define A6948A32_3AC8_4519_A3CC_636F8DF1EEF3

#include <libconfig.h++>
#include <iostream>
#include <vector>

#include "Point3D.hpp"
#include "Color.hpp"

class Lights
{
    private:
        /**
         * @brief ambient light intensity
         *
         */
        float _ambient;
        /**
         * @brief diffuse light intensity
         *
         */
        float _diffuse;
        /**
         * @brief true if the light is ambient
         *
         */
        bool _isAmbientLight;
        /**
         * @brief true if the light is directional
         *
         */
        bool _isDirectionalLight;
        /**
         * @brief position of the light
         *
         */
        Math::Point3D _point;
        /**
         * @brief color of the light
         *
         */
        Color _color;

    public:
        /**
         * @brief Construct a new Lights object
         *
         * @param setting
         */
        Lights(const libconfig::Setting &setting);
        Lights() = default;
        ~Lights();
};

#endif /* A6948A32_3AC8_4519_A3CC_636F8DF1EEF3 */
