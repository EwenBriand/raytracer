/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Point3D.hpp
*/

#ifndef A9DE60FF_0966_4C55_9EB0_8ECE064F4322
#define A9DE60FF_0966_4C55_9EB0_8ECE064F4322

#include <libconfig.h++>
#include <iostream>

class Point3D
{
    private:
        int _x;
        int _y;
        int _z;
    public:
        Point3D(int x, int y, int z);
        Point3D() = default;
        ~Point3D();
        void setPoint(int x, int y, int z);
        void setPoint(const libconfig::Setting &setting);
        int getX() const;
        int getY() const;
        int getZ() const;
        Point3D cross(const Point3D &point) const;
};

std::ostream &operator<<(std::ostream &s, const Point3D &point);

Point3D operator-(const Point3D &point1, const Point3D &point2);


#endif /* A9DE60FF_0966_4C55_9EB0_8ECE064F4322 */
