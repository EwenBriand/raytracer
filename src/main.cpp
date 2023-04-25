/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** main
*/
#include "main.hpp"
#include "PluginLoader.hpp"
#include "badWord.hpp"

int main(void)
{
    std::cout << "Hello World!" << std::endl;
    PluginLoader pl;
    BadWord *bw = pl.loadPlugin<BadWord>("./plugins/libBadWord.so");

    bw->setWord("Shitty");
    std::cout << bw->getWord() << "World!" << std::endl;

    return 0;
}