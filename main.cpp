/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** main.cpp
*/

#include "ParserFile.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    ParserFile file(av[1]);
    return 0;
}
