/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** AbstractFactory.hpp
*/

#pragma once

#include <memory>
#include <map>
#include "IPrimitives.hpp"
#include "AllPrimitives.hpp"
#include "PrimitiveBuilder.hpp"
#include "ILights.hpp"
#include "AllLight.hpp"
#include "LightBuilder.hpp"

class AbstractFactory
{
    public:
        AbstractFactory();
        virtual ~AbstractFactory() = default;
        /**
         * @brief Create a Primitive object for the Factory
         *
         * @param type
         * @param setting
         * @return std::shared_ptr<IPrimitives>
         */
        std::shared_ptr<Primitive::IPrimitives> createPrimitive(const std::string type, const libconfig::Setting &setting);
        /**
         * @brief Create a Light object for the Factory
         *
         * @param type
         * @param setting
         * @return std::shared_ptr<ILights>
         */
        std::shared_ptr<Light::ILights> createLight(const std::string type, const libconfig::Setting &setting);
    private:
        /**
         * @brief Map of all the builders
         *
         */
        std::map<std::string, std::shared_ptr<Primitive::PrimitiveBuilder>> _primitives;
        std::map<std::string, std::shared_ptr<Light::LightBuilder>> _lights;
};
