/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** main
*/
#include "Core.hpp"

int main(int ac, char **av)
{
    int returnCode = 0;

    try {
        returnCode = core::Core(ac, av).run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return returnCode;
}
