/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Core
*/
#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <string>
    #include <map>
    #include <fstream>
    #include <iostream>

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
            std::map<std::string, std::string> loadConfig(std::string path);
            std::string checkSceneFile(std::string path);
            int run();
        private:
            std::map<std::string, std::string> _plugins;
            std::string _sceneFile;
    };
}

#endif /* !CORE_HPP_ */
