/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** RaytracerCore
*/

#ifndef RAYTRACERCORE_HPP_
#define RAYTRACERCORE_HPP_
#include <SFML/Graphics.hpp>
#include <memory>
#include "ParserFile.hpp"

class RaytracerCore {
  public:
    RaytracerCore(const std::string &sceneFile);
    std::shared_ptr<sf::Image> renderImage();
    std::shared_ptr<sf::Image> PostProcess(const sf::Image &image);

  private:
    ParserFile _file;
    std::vector<IPrimitives *> _primitives;
    std::vector<ILights *> _lights;
    std::vector<Ray> _raysToBlur;
    Camera _camera;
};

#endif /* !RAYTRACERCORE_HPP_ */
