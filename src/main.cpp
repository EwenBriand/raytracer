/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** main
*/

#include "RaytracerCore.hpp"
#include "RaytracerGraphic.hpp"
#include <string>


int main(int ac, char **av)
{
    std::string ending = ".cfg";
    std::string value = av[1];

    if (ac != 2
        || ending.size() > value.size()
        || !std::equal(ending.rbegin(), ending.rend(), value.rbegin())) {
        printf("Usage: ./raytracer [scene_file]\n");
        return 84;
    }
    RaytracerCore core(av[1]);
    std::shared_ptr<sf::Image> image = core.renderImage();
    RaytracerGraphic interface(image);
    interface.run();
    image->saveToFile("image.png");
    interface.drawPPM();
    return 0;
}
