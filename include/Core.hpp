/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Core
*/
#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <string>
    #include <iostream>
    #include <map>
    #include <fstream>
    #include <stdexcept>
    #include <memory>
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include "RaytracerCore.hpp"
    #include "RaytracerGraphic.hpp"
    #include "PluginManager.hpp"
    #include "IPlugins.hpp"

namespace core {

    class CoreException : public std::exception {
        public:
            CoreException(const std::string &message);
            const char *what() const noexcept override;
        private:
            std::string _msg;
    };

    class Core {
        public:
            Core(int ac, char **av);
            ~Core() = default;
            void loadConfig(std::string path);
            int run();
        private:
            std::string checkFile(std::string path);

            std::string _sceneFile;
            plugin::PluginManager _pluginManager;
            std::vector<IPlugins *> _plugins;

    };
}

#endif /* !CORE_HPP_ */
