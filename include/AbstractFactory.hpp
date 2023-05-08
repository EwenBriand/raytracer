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

class AbstractFactory
{
    public:
        AbstractFactory();
        virtual ~AbstractFactory() = default;
        std::shared_ptr<IPrimitives> createPrimitive(const std::string type, const libconfig::Setting &setting);

    private:
        std::map<std::string, std::shared_ptr<PrimitiveBuilder>> builders_;
};
