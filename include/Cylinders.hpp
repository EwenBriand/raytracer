/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Cylinders.hpp
*/

#ifndef CAEFB936_1C79_48F5_B406_9DC688A7D20F
#define CAEFB936_1C79_48F5_B406_9DC688A7D20F

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"

class Cylinders : public IPrimitives {
  private:
    float _radius;
    int _height;
    bool _isLimited;

  public:
    Cylinders(const libconfig::Setting &setting);
    ~Cylinders() override;
    bool hit(const Ray &ray) override;
    Color getColor() const override;
    Math::Point3D getIntersexe() const override;
    Math::Vector3D getNormal() const;
};

#endif /* CAEFB936_1C79_48F5_B406_9DC688A7D20F */
