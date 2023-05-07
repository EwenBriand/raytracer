/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Lights.cpp
*/

#include "Lights.hpp"

Lights::Lights(const libconfig::Setting &setting)
{
    try
    {
        setting.lookupValue("ambient", _ambient);
        std::cout << _ambient << std::endl;
        setting.lookupValue("diffuse", _diffuse);
        std::cout << _diffuse << std::endl;
        _point.setPoint(setting);
        std::cout << _point << std::endl;
        setting.lookupValue("directional", _isDirectionalLight);
        std::cout << _isDirectionalLight << std::endl;
        if (_isDirectionalLight)
            _isAmbientLight = false;
        else
            _isAmbientLight = true;
        std::cout << _isAmbientLight << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Lights::~Lights()
{
}
