/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Spheres.cpp
*/

#include "Spheres.hpp"

Spheres::Spheres(const libconfig::Setting &setting)
{
    try
    {
        _position.setPoint(setting);
        std::cout << _position << std::endl;

        setting.lookupValue("r", _radius);
        if (setting.exists("r") == true)
            std::cout << _radius << std::endl;
        _color.setColor(setting["color"]);
        std::cout << _color << std::endl;
        _rotation.setPoint(setting["rotation"]);
        std::cout << _rotation << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Spheres::~Spheres()
{
}