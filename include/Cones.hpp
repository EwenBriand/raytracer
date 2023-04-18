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
        int _radius;
        int _height;
        int _angle;
        bool _isLimited;
    public:
        Cones(const libconfig::Setting &setting);
        ~Cones() override;
};

#endif /* C7304198_8C73_4EEC_BDEE_FF214F9B8958 */
