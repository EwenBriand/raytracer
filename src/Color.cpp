/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Color.cpp
*/

#include "Color.hpp"

Color::Color(int r, int g, int b): _r(r), _g(g), _b(b)
{
}

Color::~Color()
{
}

void Color::setColor(int r, int g, int b)
{
    _r = r;
    _g = g;
    _b = b;
}

void Color::setColor(const libconfig::Setting &setting)
{
    try
    {
        setting.lookupValue("r", _r);
        setting.lookupValue("g", _g);
        setting.lookupValue("b", _b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int Color::getR() const
{
    return _r;
}

int Color::getG() const
{
    return _g;
}

int Color::getB() const
{
    return _b;
}

std::ostream &operator<<(std::ostream &s, const Color &color)
{
    s << "r: " << color.getR() << " g: " << color.getG() << " b: " << color.getB();
    return s;
}