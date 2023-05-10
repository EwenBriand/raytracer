/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Triangles.hpp
*/

#ifndef E6FB8944_93AB_44F6_84DC_8F965B067DC4
#define E6FB8944_93AB_44F6_84DC_8F965B067DC4

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"

class Triangles : public IPrimitives {
  private:
    Math::Point3D _sommet1;
    Math::Point3D _sommet2;
    Math::Point3D _sommet3;
    Math::Point3D _normal;

  public:
    Triangles(const libconfig::Setting &setting);
    ~Triangles() override;
    bool hit(const Ray &ray) override;
    Color getColor() const override;
    Math::Point3D getIntersexe() const override;
    Math::Vector3D getNormal() const;
    void setIntersexe(const Math::Point3D &value) override;
    bool isNeon() const override;
};

#endif /* E6FB8944_93AB_44F6_84DC_8F965B067DC4 */
