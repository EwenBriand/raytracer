/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Torus.hpp
*/

#ifndef D4E88905_726D_4F79_AFCA_7257590B44E5
#define D4E88905_726D_4F79_AFCA_7257590B44E5

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"

class Torus : public IPrimitives
{
    private:
        int _radiusMinor;
        int _radiusMajor;
    public:
        Torus(const libconfig::Setting &setting);
        ~Torus() override;
        bool hit(const Ray &ray) override;
        Color getColor() const override;
};

#endif /* D4E88905_726D_4F79_AFCA_7257590B44E5 */
