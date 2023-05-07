/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Cones.hpp
*/

#ifndef C7304198_8C73_4EEC_BDEE_FF214F9B8958
#define C7304198_8C73_4EEC_BDEE_FF214F9B8958

#include <iostream>
#include <libconfig.h++>
#include <cmath>
#include "IPrimitives.hpp"

class Cones : public IPrimitives
{
    private:
        float _radius;
        int _height;
        float _angle;
        bool _isLimited;
    public:
        Cones(const libconfig::Setting &setting);
        ~Cones() override;
        bool hit(const Ray &ray) override;
        Color getColor() const override;
};

#endif /* C7304198_8C73_4EEC_BDEE_FF214F9B8958 */
