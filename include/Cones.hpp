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

namespace Primitive {
    class Cones : public IPrimitives
    {
        private:
            /**
             * @brief radius of the cone
             *
             */
            float _radius;
            /**
             * @brief height of the cone
             *
             */
            int _height;
            /**
             * @brief angle of the cone
             *
             */
            float _angle;
            /**
             * @brief is the cone limited
             *
             */
            bool _isLimited;
        public:
            /**
             * @brief Construct a new Cones object from a libconfig::Setting
             *
             * @param setting
             */
            Cones(const libconfig::Setting &setting);
            ~Cones() override;
            bool hit(const Math::Ray &ray) override;
            Color getColor() const override;
    };
}

#endif /* C7304198_8C73_4EEC_BDEE_FF214F9B8958 */
