/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** ParserFile.cpp
*/

#include "ParserFile.hpp"

ParserFile::ParserFile(std::string filename)
{
    libconfig::Config cfg;
    try {
        cfg.readFile(filename.c_str());
        libconfig::Setting &root = cfg.getRoot();
        setCamera(root);
        std::cout << "Camera set\n" << std::endl;
        setLights(root);
        std::cout << "Lights set\n" << std::endl;
        setPrimitives(root);
        std::cout << "Primitives set" << std::endl;
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
    }
    std::cout << "File loaded" << std::endl;
}

ParserFile::~ParserFile()
{
}

void ParserFile::setCamera(const libconfig::Setting &root)
{
    try {
        const libconfig::Setting &camera = root["camera"];
        _camera = Camera(camera);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'camera' setting in configuration file." << std::endl;
    }
}

void ParserFile::setLights(const libconfig::Setting &root)
{
    try {
        std::cout << "setLights" << std::endl;
        const libconfig::Setting &lights = root["lights"];
        if (lights.exists("ambiante"))
            for (int i = 0; i < lights["ambiante"].getLength(); i++) {
                const libconfig::Setting &light = lights["ambiante"][i];
                _lights.push_back(new Diffuse(light));
                std::cout << "Ambiante created\n" << std::endl;
            }
        if (lights.exists("directional"))
            for (int i = 0; i < lights["directional"].getLength(); i++) {
                const libconfig::Setting &light = lights["directional"][i];
                _lights.push_back(new Directional(light));
                std::cout << "Directional created\n" << std::endl;
            }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'lights' setting in configuration file." << std::endl;
    }
}

void ParserFile::setPrimitives(const libconfig::Setting &root)
{
    try {
        const libconfig::Setting &primitives = root["primitives"];
        if (primitives.exists("spheres")) {
            std::cout << "Spheres" << std::endl;
            for (int i = 0; i < primitives["spheres"].getLength(); i++) {
                const libconfig::Setting &sphere = primitives["spheres"][i];
                _primitives.push_back(new Spheres(sphere));
            }
        }
        if (primitives.exists("cylinders")) {
            std::cout << "Cylinders" << std::endl;
            for (int i = 0; i < primitives["cylinders"].getLength(); i++) {
                const libconfig::Setting &cylinder =
                    primitives["cylinders"][i];
                _primitives.push_back(new Cylinders(cylinder));
            }
        }
        if (primitives.exists("planes")) {
            std::cout << "Planes" << std::endl;
            for (int i = 0; i < primitives["planes"].getLength(); i++) {
                const libconfig::Setting &plane = primitives["planes"][i];
                _primitives.push_back(new Planes(plane));
            }
        }
        if (primitives.exists("cones")) {
            std::cout << "Cones" << std::endl;
            for (int i = 0; i < primitives["cones"].getLength(); i++) {
                const libconfig::Setting &cone = primitives["cones"][i];
                _primitives.push_back(new Cones(cone));
            }
        }
        if (primitives.exists("triangles")) {
            std::cout << "Triangles" << std::endl;
            for (int i = 0; i < primitives["triangles"].getLength(); i++) {
                const libconfig::Setting &triangle =
                    primitives["triangles"][i];
                _primitives.push_back(new Triangles(triangle));
            }
        }
        if (primitives.exists("torus")) {
            std::cout << "Torus" << std::endl;
            for (int i = 0; i < primitives["torus"].getLength(); i++) {
                const libconfig::Setting &torus = primitives["torus"][i];
                _primitives.push_back(new Torus(torus));
            }
        }
        if (primitives.exists("boxes")) {
            std::cout << "Boxes" << std::endl;
            for (int i = 0; i < primitives["boxes"].getLength(); i++) {
                const libconfig::Setting &box = primitives["boxes"][i];
                _primitives.push_back(new Boxes(box));
            }
        }

    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'primitives' setting in configuration file."
                  << std::endl;
    }
}

Camera ParserFile::getCamera() const
{
    return _camera;
}

std::vector<ILights *> ParserFile::getLights() const
{
    return _lights;
}

std::vector<IPrimitives *> ParserFile::getPrimitives() const
{
    return _primitives;
}
