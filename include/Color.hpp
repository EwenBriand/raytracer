/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Color.hpp
*/

#ifndef AA3F6387_7A9D_46F0_8695_EF3803BB196D
#define AA3F6387_7A9D_46F0_8695_EF3803BB196D

#include <iostream>
#include <libconfig.h++>

class Color
{
    private:
        int _r;
        int _g;
        int _b;
    public:
        Color(int r, int g, int b);
        Color() = default;
        ~Color();
        void setColor(int r, int g, int b);
        void setColor(const libconfig::Setting &setting);
        int getR() const;
        int getG() const;
        int getB() const;
};
std::ostream &operator<<(std::ostream &s, const Color &color);



#endif /* AA3F6387_7A9D_46F0_8695_EF3803BB196D */
