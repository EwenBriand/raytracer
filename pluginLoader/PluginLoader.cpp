/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** dlLoader
*/

#include "PluginLoader.hpp"

PluginLoader::~PluginLoader()
{
    closePlugin();
}

void PluginLoader::closePlugin()
{
    if (_lib)
        dlclose(_lib);
}

std::vector<std::string> PluginLoader::listPlugins(const std::string &dir)
{
    std::vector<std::string> libs;

    for (const auto &entry : std::filesystem::directory_iterator(dir)) {
        if (entry.path().extension() == ".so")
            libs.push_back(entry.path());
    }
    return libs;
}