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
    /**
     * @brief Construct a new Raytracer Core object
     *
     * @param sceneFile
     */
    RaytracerCore(const std::string &sceneFile);
    /**
     * @brief Render the image
     *
     */
    std::shared_ptr<sf::Image> renderImage();

  private:
    /**
     * @brief Parse the file
     *
     */
    ParserFile _file;
    /**
     * @brief Vector of all the primitives
     *
     */
    std::vector<std::shared_ptr<Primitive::IPrimitives>> _primitives;
    /**
     * @brief Camera of the scene
     *
     */
    Camera _camera;
    /**
     * @brief Vector of all the lights
     *
     */
    std::vector<std::shared_ptr<Light::ILights>> _lights;
};

#endif /* !RAYTRACERCORE_HPP_ */
