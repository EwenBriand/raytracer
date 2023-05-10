/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Boxes.hpp
*/

#ifndef D428BE3F_E861_4C23_A929_D74DB520103F
#define D428BE3F_E861_4C23_A929_D74DB520103F

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"

class Boxes : public IPrimitives {
  private:
    int _width;
    int _height;
    int _depth;

  public:
    Boxes(const libconfig::Setting &setting);
    ~Boxes() override;
    bool hit(const Ray &ray) override;
    Color getColor() const override;
    Math::Point3D getIntersexe() const override;
    Math::Vector3D getNormal() const;
    void setIntersexe(const Math::Point3D &value) override;
    bool isNeon() const override;
};

#endif /* D428BE3F_E861_4C23_A929_D74DB520103F */
