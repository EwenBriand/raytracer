/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** RaytracerCore
*/

#include "RaytracerCore.hpp"

RaytracerCore::RaytracerCore(const std::string &sceneFile) : _file(sceneFile)
{
    _primitives = _file.getPrimitives();
    _camera = _file.getCamera();
}

std::shared_ptr<sf::Image> RaytracerCore::renderImage()
{
    auto image = std::make_shared<sf::Image>();
    image->create(_camera.getResolutionX(), _camera.getResolutionY());

    for (int i = 0; i < _camera.getResolutionX(); i++) {
        for (int j = 0; j < _camera.getResolutionY(); j++) {
            float u = (float)i / _camera.getResolutionX();
            float v = (float)j / _camera.getResolutionY();
            Ray ray = _camera.getRay(u, v);
            image->setPixel(i, j, sf::Color::Black);

            for (long unsigned int k = 0; k < _primitives.size(); k++) {
                if (_primitives[k]->hit(ray)) {
                    image->setPixel(i, j, sf::Color(_primitives[k]->getColor().getR(), _primitives[k]->getColor().getG(), _primitives[k]->getColor().getB()));
                    break;
                }
            }
        }
    }
    return image;
}
