/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** PrimitiveBuilder
*/

#ifndef PRIMITIVEBUILDER_HPP_
    #define PRIMITIVEBUILDER_HPP_
    #include <memory>
    #include "IPrimitives.hpp"
    #include "AllPrimitives.hpp"

class PrimitiveBuilder
{
    public:
        virtual ~PrimitiveBuilder() = default;
        virtual std::shared_ptr<IPrimitives> build(const libconfig::Setting &setting) const = 0;
};

class SphereBuilder : public PrimitiveBuilder
{
    public:
        std::shared_ptr<IPrimitives> build(const libconfig::Setting &setting) const override
        {
            return std::make_shared<Spheres>(setting);
        }
};

class PlaneBuilder : public PrimitiveBuilder
{
    public:
        std::shared_ptr<IPrimitives> build(const libconfig::Setting &setting) const override
        {
            return std::make_shared<Planes>(setting);
        }
};

class TriangleBuilder : public PrimitiveBuilder
{
    public:
        std::shared_ptr<IPrimitives> build(const libconfig::Setting &setting) const override
        {
            return std::make_shared<Triangles>(setting);
        }
};

class ConeBuilder : public PrimitiveBuilder
{
    public:
        std::shared_ptr<IPrimitives> build(const libconfig::Setting &setting) const override
        {
            return std::make_shared<Cones>(setting);
        }
};

class CylinderBuilder : public PrimitiveBuilder
{
    public:
        std::shared_ptr<IPrimitives> build(const libconfig::Setting &setting) const override
        {
            return std::make_shared<Cylinders>(setting);
        }
};

class TorusBuilder : public PrimitiveBuilder
{
    public:
        std::shared_ptr<IPrimitives> build(const libconfig::Setting &setting) const override
        {
            return std::make_shared<Torus>(setting);
        }
};

class BoxBuilder : public PrimitiveBuilder
{
    public:
        std::shared_ptr<IPrimitives> build(const libconfig::Setting &setting) const override
        {
            return std::make_shared<Boxes>(setting);
        }
};

#endif /* !PRIMITIVEBUILDER_HPP_ */
