/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** main
*/
#include "Core.hpp"

int main(int ac, char **av)
{
    int returnCode = core::Core(ac, av).run();
    return returnCode;
}