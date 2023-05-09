/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** ParseFile.hpp
*/

#ifndef DEA803B7_0073_403F_AFAB_9646A6CEAFEC
#define DEA803B7_0073_403F_AFAB_9646A6CEAFEC

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <libconfig.h++>

#include "AbstractFactory.hpp"
#include "AllLight.hpp"
#include "AllPrimitives.hpp"
#include "Camera.hpp"
#include "ILights.hpp"
#include "IPrimitives.hpp"

class ParserFile {
  public:
    /**
     * @brief Construct a new Parser File object
     *
     * @param filename
     */
    ParserFile(std::string filename);
    ~ParserFile();
    /**
     * @brief Set the Camera object
     *
     * @param root
     */
    void setCamera(const libconfig::Setting &root);
    /**
     * @brief Set the Primitives object
     *
     * @param root
     */
    void setPrimitives(const libconfig::Setting &root);
    /**
     * @brief Set the Lights object
     *
     * @param root
     */
    void setLights(const libconfig::Setting &root);
    /**
     * @brief Get the Camera object
     *
     * @return Camera
     */
    Camera getCamera() const;
    /**
     * @brief Get the Primitives object
     *
     * @return std::vector<std::shared_ptr<Primitive::IPrimitives>>
     */
    std::vector<std::shared_ptr<Primitive::IPrimitives>> getPrimitives() const;
    /**
     * @brief Get the Lights object
     *
     * @return std::vector<Lights>
     */
    std::vector<Light::ILights *> getLights() const;

  private:
    /**
     * @brief The camera of the scene
     *
     */
    Camera _camera;
    /**
     * @brief The primitives of the scene
     *
     */
    std::vector<std::shared_ptr<Primitive::IPrimitives>> _primitives;
    /**
     * @brief The lights of the scene
     *
     */
    std::vector<Light::ILights *> _lights;
    /**
     * @brief The factory of the primitives
     *
     */
    Primitive::AbstractFactory *_factory;
};

#endif /* DEA803B7_0073_403F_AFAB_9646A6CEAFEC */
