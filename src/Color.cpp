/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Color.cpp
*/

#include "Color.hpp"

Color::Color(int r, int g, int b) : _r(r), _g(g), _b(b)
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
    try {
        setting.lookupValue("r", _r);
        setting.lookupValue("g", _g);
        setting.lookupValue("b", _b);
    } catch (const std::exception &e) {
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
    s << "r: " << color.getR() << " g: " << color.getG()
      << " b: " << color.getB();
    return s;
}

Color operator*(const Color &c, float &factor)
{
    Color result = {static_cast<int>(c.getR() * factor), static_cast<int>(c.getG() * factor), static_cast<int>(c.getB() * factor)};
    return result;
}

Color operator/(const Color &c, float &factor)
{
    Color result = {static_cast<int>(c.getR() / factor), static_cast<int>(c.getG() / factor), static_cast<int>(c.getB() / factor)};
    return result;
}

Color operator+(const Color &a, const Color &b)
{
    Color result = {
        a.getR() + b.getR(), a.getG() + b.getG(), a.getB() + b.getB()};
    return result;
}

Color operator*(const Color &c1, const Color &c2)
{
    Color result = {
        c1.getR() * c2.getR(), c1.getG() * c2.getG(), c1.getB() * c2.getB()};
    return result;
}

Color Color::normalized()
{
    if (_r > 255)
        _r = 255;
    if (_g > 255)
        _g = 255;
    if (_b > 255)
        _b = 255;

    return Color(_r, _g, _b);
}