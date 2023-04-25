/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Core
*/

#include "Core.hpp"

core::CoreException::CoreException(const std::string &str)
{
    _msg = str;
}

const char *core::CoreException::what() const noexcept
{
    return _msg.c_str();
}

core::Core::Core(int ac, char **av)
{
    if (ac != 2)
        throw CoreException("Invalid number of arguments");
    _plugins = loadConfig("config_files/test.config");
    _sceneFile = checkSceneFile(av[1]);
}

std::string core::Core::checkSceneFile(std::string path)
{
    std::ifstream file(path);
    if (file.good())
        return path;
    throw CoreException("Invalid scene file");
}

int core::Core::run()
{
    std::cout << "Plugin list:" << std::endl;
    for (const auto& pair : _plugins) {
        const std::string& key = pair.first;
        const std::string& value = pair.second;
        std::cout << "Name:" << key << " Path:" << value << std::endl;
    }
    std::cout << "Path to the file:" << _sceneFile << std::endl;
    return 0;
}

std::map<std::string, std::string> core::Core::loadConfig(std::string path)
{
    std::map<std::string, std::string> plugins;
    std::ifstream file(path);
    std::string line;

    if (!file.is_open())
        return plugins;
    while (std::getline(file, line)) {
        if (line[0] == '#')
            continue;
        std::string name = line.substr(0, line.find('='));
        std::string path = line.substr(line.find('=') + 1, line.size());
        if (name.empty() || path.empty())
            continue;
        plugins[name] = path;
    }
    file.close();
    return plugins;
}