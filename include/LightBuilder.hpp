/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** LightBuilder.hpp
*/

#pragma once

#include <memory>
#include "ILights.hpp"
#include "AllLight.hpp"

namespace Light {
    class LightBuilder
    {
        public:
            virtual ~LightBuilder() = default;
            /**
             * @brief Build the light
             *
             * @param setting
             * @return std::shared_ptr<ILights>
             */
            virtual std::shared_ptr<ILights> build(const libconfig::Setting &setting) const = 0;
    };

    class DiffuseBuilder : public LightBuilder
    {
        public:
            std::shared_ptr<ILights> build(const libconfig::Setting &setting) const override
            {
                return std::make_shared<Diffuse>(setting);
            }
    };

    class DirectionalBuilder : public LightBuilder
    {
        public:
            std::shared_ptr<ILights> build(const libconfig::Setting &setting) const override
            {
                return std::make_shared<Directional>(setting);
            }
    };
}
