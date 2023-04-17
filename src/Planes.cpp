/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Planes.cpp
*/

#include "Planes.hpp"

Planes::Planes(const libconfig::Setting &setting)
{
    try
    {
        _position.setPoint(setting);
        std::cout << _position << std::endl;
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

Planes::~Planes()
{
}
