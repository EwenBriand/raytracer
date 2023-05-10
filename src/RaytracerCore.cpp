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
            Color temp = Color(0, 0, 0);
            IPrimitives *closestPrimitive = nullptr;
            Math::Point3D closestIntersexe = Math::Point3D(0, 0, 0);

            for (long unsigned int k = 0; k < _primitives.size(); k++) {
                if (_primitives[k]->hit(ray)) {
                    if (closestPrimitive == nullptr) {
                        closestPrimitive = _primitives[k];
                        closestIntersexe = _primitives[k]->getIntersexe();
                    }
                    Math::Point3D intersexe = _primitives[k]->getIntersexe();
                    if (_camera.getPosition().distanceTo(intersexe) < _camera.getPosition().distanceTo(closestPrimitive->getIntersexe())) {
                        closestPrimitive = _primitives[k];
                        closestIntersexe = intersexe;
                    }
                    temp = Color(closestPrimitive->getColor().getR(),
                        closestPrimitive->getColor().getG(),
                        closestPrimitive->getColor().getB());
                    for (long unsigned int l = 0; l < _lights.size(); l++)
                        if (!_lights[l]->is_cut(
                                closestPrimitive->getIntersexe(), _primitives))
                            temp = _lights[l]->define_color(_primitives[k]->getIntersexe(),
                                _primitives[k]->getNormal(), temp, 0.2, false);
                        else
                            temp = _lights[l]->define_color(
                                _primitives[k]->getIntersexe(),
                                _primitives[k]->getNormal(), temp, 0.2, true);
                }
            }

            for (long unsigned int k = 0; k < _lights.size(); k++) {
                if (_lights[k]->getPrimitive() != nullptr
                    && _lights[k]->getPrimitive()->hit(ray)) {
                    Math::Point3D intersexe = _lights[k]->getPrimitive()->getIntersexe();

                    if (_camera.getPosition().distanceTo(intersexe) < _camera.getPosition().distanceTo(closestIntersexe)) {
                        closestPrimitive = _lights[k]->getPrimitive();
                        closestIntersexe = intersexe;
                    }
                }
            }
            image->setPixel(i, j,
                sf::Color(temp.getR(), temp.getG(), temp.getB()));
        }
    }
    return image;
}

std::shared_ptr<sf::Image> RaytracerCore::PostProcess(const sf::Image &image)
{
    
}