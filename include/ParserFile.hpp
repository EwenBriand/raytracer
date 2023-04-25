/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** ParseFile.hpp
*/

#ifndef DEA803B7_0073_403F_AFAB_9646A6CEAFEC
#define DEA803B7_0073_403F_AFAB_9646A6CEAFEC

#include <iostream>
#include <vector>
#include <libconfig.h++>
#include <SFML/Graphics.hpp>

#include "Camera.hpp"
#include "IPrimitives.hpp"
#include "Lights.hpp"
#include "AllPrimitives.hpp"
#include "AbstractFactory.hpp"

class ParserFile
{
    public:
        ParserFile(std::string filename);
        ~ParserFile();
        void setCamera(const libconfig::Setting &root);
        void setPrimitives(const libconfig::Setting &root);
        void setLights(const libconfig::Setting &root);
        Camera getCamera() const;
        std::vector<std::shared_ptr<IPrimitives>> getPrimitives() const;
        std::vector<Lights> getLights() const;
    private:
        Camera _camera;
        std::vector<std::shared_ptr<IPrimitives>> _primitives;
        std::vector<Lights> _lights;
        AbstractFactory *_factory;
};

#endif /* DEA803B7_0073_403F_AFAB_9646A6CEAFEC */
