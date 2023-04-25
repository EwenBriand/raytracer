/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** AbstractFactory.hpp
*/

#pragma once

#include <memory>
#include "IPrimitives.hpp"

class AbstractFactory
{
    public:
        virtual ~AbstractFactory() = delete;
        std::shared_ptr<IPrimitives> createPrimitive(const std::string type,
            const libconfig::Setting &setting);
};
