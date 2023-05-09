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

namespace Primitive {
    class Spheres : public IPrimitives
    {
        private:
            /**
             * @brief radius of the sphere
             *
             */
            double _radius;
        public:
            /**
             * @brief Construct a new Spheres object from a libconfig::Setting
             *
             * @param setting
             */
            Spheres(const libconfig::Setting &setting);
            ~Spheres() override;
            bool hit(const Math::Ray &ray) override;
            Color getColor() const override;
    };
}

#endif /* BE5DD2F6_0056_455A_9E60_33757B907054 */
