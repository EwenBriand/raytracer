/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Planes.hpp
*/

#ifndef F2AA8B37_71DB_4B85_9E0D_E45189DC1639
#define F2AA8B37_71DB_4B85_9E0D_E45189DC1639

#include <iostream>
#include <libconfig.h++>

#include "IPrimitives.hpp"

class Planes : public IPrimitives {
  private:
    Math::Point3D _p2;
    Math::Point3D _p3;
    Math::Vector3D _normal;

  public:
    Planes(const libconfig::Setting &setting);
    ~Planes() override;
    bool hit(const Ray &ray) override;
    Color getColor() const override;
    Math::Point3D getIntersexe() const override;
    Math::Vector3D getNormal() const;
    void setIntersexe(const Math::Point3D &value) override;

};

#endif /* F2AA8B37_71DB_4B85_9E0D_E45189DC1639 */
