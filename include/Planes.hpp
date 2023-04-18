/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Planes.hpp
*/

#ifndef F2AA8B37_71DB_4B85_9E0D_E45189DC1639
#define F2AA8B37_71DB_4B85_9E0D_E45189DC1639

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"

class Planes : public IPrimitives
{
    private:
    public:
        Planes(const libconfig::Setting &setting);
        ~Planes() override;
};

#endif /* F2AA8B37_71DB_4B85_9E0D_E45189DC1639 */
