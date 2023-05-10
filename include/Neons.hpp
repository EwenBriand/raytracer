/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Neons
*/

#ifndef NEONS_HPP_
    #define NEONS_HPP_
    #include "Boxes.hpp"

class BoxeNeon: public Boxes {
  private:
    Color _neonColor;
    float _intensity;

  public:
    BoxeNeon(const libconfig::Setting &setting);
    ~BoxeNeon() override;
    Color getColor() const override;
};



#endif /* !NEON_HPP_ */
