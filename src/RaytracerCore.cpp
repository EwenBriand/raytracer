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
    _lights = _file.getLights();
    _camera = _file.getCamera();
}

std::shared_ptr<sf::Image> RaytracerCore::renderImage()
{
    auto image = std::make_shared<sf::Image>();
    image->create(_camera.getResolutionX(), _camera.getResolutionY());

    for (int i = 0; i < _camera.getResolutionX(); i++) {
        for (int j = 0; j < _camera.getResolutionY(); j++) {
            float u = (float) i / _camera.getResolutionX();
            float v = (float) j / _camera.getResolutionY();
            Ray ray = _camera.getRay(u, v);
            image->setPixel(i, j, sf::Color::Black);

            for (long unsigned int k = 0; k < _primitives.size(); k++) {
                if (_primitives[k]->hit(ray)) {
                    auto temp = Color(_primitives[k]->getColor().getR(),
                        _primitives[k]->getColor().getG(),
                        _primitives[k]->getColor().getB());
                    for (long unsigned int l = 0; l < _lights.size(); l++)
                        if (!_lights[l]->is_cut(
                                _primitives[k]->getIntersexe(), _primitives))
                            temp = _lights[l]->define_color(temp, 0.2, false);
                        else
                            temp = _lights[l]->define_color(temp, 0.2, true);
                    image->setPixel(i, j,
                        sf::Color(temp.getR(), temp.getG(), temp.getB()));
                    break;
                }
            }
            for (long unsigned int k = 0; k < _lights.size(); k++) {
                if (_lights[k]->getPrimitive() != nullptr
                    && _lights[k]->getPrimitive()->hit(ray)) {
                    // printf("lighting pos %i %i\n", i, j);
                    image->setPixel(i, j,
                        sf::Color(_lights[k]->getColor().getR(),
                            _lights[k]->getColor().getG(),
                            _lights[k]->getColor().getB()));
                    break;
                }
            }
        }
    }
    // exit(0);
    return image;
}
