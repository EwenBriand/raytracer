/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** PluginLoader
*/

#pragma once

#include <iostream>
#include <dlfcn.h>
#include <vector>
#include <filesystem>

class PluginLoader {
    public:
        PluginLoader() = default;
        ~PluginLoader();
        void closePlugin();
        std::vector<std::string> listPlugins(const std::string &dir);

        template <typename T>
        T *loadPlugin(const std::string &path) {
            void *lib = dlopen(path.c_str(), RTLD_LAZY);
            if (!lib) {
                // add throw exception
                std::cerr << "[DLL ERROR] " << path << ": " << dlerror() << std::endl;
            }
            void *(*entry_point)() = (void *(*)()) dlsym(lib, "entry_point");
            if (!entry_point) {
                // add throw exception
                std::cerr << "[DLL ERROR] " << path << ": entry Point not found." << std::endl;
            }
            _lib = lib;
            return ((T *(*)()) entry_point)();
        };

    private:
        void *_lib;
};