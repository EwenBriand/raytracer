/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** RaytracerCore
*/

#ifndef RAYTRACERCORE_HPP_
    #define RAYTRACERCORE_HPP_
    #include "ParserFile.hpp"
    #include <memory>
    #include <SFML/Graphics.hpp>

class RaytracerCore {
    public:
        RaytracerCore(const std::string &sceneFile);
        std::shared_ptr<sf::Image> renderImage();

    private:
        ParserFile _file;
        std::vector<std::shared_ptr<IPrimitives>> _primitives;
        Camera _camera;
};

#endif /* !RAYTRACERCORE_HPP_ */
