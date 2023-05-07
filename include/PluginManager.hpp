/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** PluginManager
*/

#pragma once

#include <iostream>
#include <dlfcn.h>
#include <vector>
#include <filesystem>

namespace plugin {

    class PluginManagerException : public std::exception {
        public:
            PluginManagerException(const std::string &message);
            const char *what() const noexcept override;
        private:
            std::string _msg;
    };

    class PluginManager {
        public:
            PluginManager() = default;
            ~PluginManager();
            void closePlugins();
            std::vector<std::string> listPlugins(const std::string &dir);

            template <typename T>
            T *loadPlugin(const std::string &path);

        private:
            std::vector<void *> _handlers;
    };
}

template <typename T>
T *plugin::PluginManager::loadPlugin(const std::string &path) {
    void *lib = dlopen(path.c_str(), RTLD_LAZY);
    if (!lib)
        throw PluginManagerException(path + ": " + dlerror());
    void *(*entry_point)() = (void *(*)()) dlsym(lib, "entry_point");
    if (!entry_point)
        throw PluginManagerException(path + ": entry Point not found.");
    _handlers.push_back(lib);
    return ((T *(*)()) entry_point)();
};