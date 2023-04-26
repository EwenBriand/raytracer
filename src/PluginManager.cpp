/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** PluginManager
*/

#include "PluginManager.hpp"

plugin::PluginManagerException::PluginManagerException(const std::string &message) : _msg(message)
{}

const char *plugin::PluginManagerException::what() const noexcept
{
    return _msg.c_str();
}

plugin::PluginManager::~PluginManager()
{
    closePlugins();
}

void plugin::PluginManager::closePlugins()
{
    for (auto &plugin : _handlers)
        dlclose(plugin);
}

template <typename T>
T *plugin::PluginManager::loadPlugin(const std::string &id, const std::string &path) {
    void *lib = dlopen(path.c_str(), RTLD_LAZY);
    if (!lib)
        throw PluginManagerException(path + ": " + dlerror());
    void *(*entry_point)() = (void *(*)()) dlsym(lib, "entry_point");
    if (!entry_point)
        throw PluginManagerException(path + ": entry Point not found.");
    _handlers[id] = lib;
    return ((T *(*)()) entry_point)();
};

std::vector<std::string> plugin::PluginManager::listPlugins(const std::string &dir)
{
    std::vector<std::string> libs;

    for (const auto &entry : std::filesystem::directory_iterator(dir)) {
        if (entry.path().extension() == ".so")
            libs.push_back(entry.path());
    }
    return libs;
}