/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Spheres.hpp
*/

#ifndef BE5DD2F6_0056_455A_9E60_33757B907054
#define BE5DD2F6_0056_455A_9E60_33757B907054

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"
#include "IPlugins.hpp"

class Spheres : public IPrimitives
{
    private:
        double _radius;
    public:
        Spheres(const libconfig::Setting &setting);
        Spheres(Math::Point3D origin, double radius);
        ~Spheres() override;
        bool hit(const Ray &ray) override;
        Color getColor() const override;
        int getType() const;
        void setType(pluginType type);
};

#endif /* BE5DD2F6_0056_455A_9E60_33757B907054 */
