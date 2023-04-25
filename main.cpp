/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** main.cpp
*/

#include "RaytracerCore.hpp"
#include "RaytracerGraphic.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;

    RaytracerCore core(av[1]);
    std::shared_ptr<sf::Image> image = core.renderImage();
    RaytracerGraphic interface(image);
    interface.run();

    return 0;
}
