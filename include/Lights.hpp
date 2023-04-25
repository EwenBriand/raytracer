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
        float _ambient;
        float _diffuse;
        bool _isAmbientLight;
        bool _isDirectionalLight;
        Math::Point3D _point;
        Color _color;

    public:
        Lights(const libconfig::Setting &setting);
        Lights() = default;
        ~Lights();
};

#endif /* A6948A32_3AC8_4519_A3CC_636F8DF1EEF3 */
