/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Core
*/

#include "Core.hpp"
#include "PluginManager.hpp"

core::CoreException::CoreException(const std::string &str) : _msg(str)
{}

const char *core::CoreException::what() const noexcept
{
    return _msg.c_str();
}

core::Core::Core(int ac, char **av)
{
    if (ac != 2)
        throw CoreException("Invalid number of arguments");
    loadConfig("config_files/test.config");
    _sceneFile = checkFile(av[1]);
}

std::string core::Core::checkFile(std::string path)
{
    std::ifstream file(path);
    if (file.good())
        return path;
    else
        throw CoreException("Cannot find the file: " + path);
    return "";
}

int core::Core::run()
{
    std::cout << "Running..." << std::endl;
    // RaytracerCore core(_sceneFile);
    // std::shared_ptr<sf::Image> image = core.renderImage();
    // RaytracerGraphic interface(image);
    // interface.run();
    return 0;
}

void core::Core::loadConfig(std::string path)
{
    std::ifstream file(path);
    std::string line;

    if (!file.is_open())
        return;
    while (std::getline(file, line)) {
        if (line[0] == '#')
            continue;
        std::string name = line.substr(0, line.find('='));
        std::string path = line.substr(line.find('=') + 1, line.size());
        if (name.empty() || path.empty() || checkFile(path).empty())
            throw CoreException("Invalid plugin at line: " + line + ".");
        _plugins.push_back(_pluginManager.loadPlugin<IPlugins>(path));
    }
    file.close();
}