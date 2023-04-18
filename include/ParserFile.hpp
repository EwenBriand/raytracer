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

#include "Camera.hpp"
#include "IPrimitives.hpp"
#include "Lights.hpp"
#include "AllPrimitives.hpp"

class ParserFile
{
    public:
        ParserFile(std::string filename);
        ~ParserFile();
        void setCamera(const libconfig::Setting &root);
        void setPrimitives(const libconfig::Setting &root);
        void setLights(const libconfig::Setting &root);
    private:
        Camera _camera;
        std::vector<IPrimitives > _primitives;
        std::vector<Lights> _lights;
};

#endif /* DEA803B7_0073_403F_AFAB_9646A6CEAFEC */
