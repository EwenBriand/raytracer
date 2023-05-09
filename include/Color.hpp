/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Color.hpp
*/

#ifndef AA3F6387_7A9D_46F0_8695_EF3803BB196D
#define AA3F6387_7A9D_46F0_8695_EF3803BB196D

#include <iostream>
#include <libconfig.h++>

class Color {
  private:
    /**
     * @brief Red value of the color
     *
     */
    int _r;
    /**
     * @brief Green value of the color
     *
     */
    int _g;
    /**
     * @brief Blue value of the color
     *
     */
    int _b;

  public:
    /**
     * @brief Construct a new Color object
     *
     * @param r Red value of the color
     * @param g Green value of the color
     * @param b Blue value of the color
     */
    Color(int r, int g, int b);
    Color() = default;
    ~Color();
    /**
     * @brief Set the Color object
     *
     * @param r Red value of the color
     * @param g Green value of the color
     * @param b Blue value of the color
     */
    void setColor(int r, int g, int b);
    /**
     * @brief Set the Color object from a libconfig::Setting
     *
     * @param setting
     */
    void setColor(const libconfig::Setting &setting);
    /**
     * @brief Get the R value
     *
     * @return int
     */
    int getR() const;
    /**
     * @brief Get the G value
     *
     * @return int
     */
    int getG() const;
    /**
     * @brief Get the B value
     *
     * @return int
     */
    int getB() const;
    Color normalized();
};
std::ostream &operator<<(std::ostream &s, const Color &color);
Color operator*(const Color &c, float &scalar);
Color operator/(const Color &c, float &scalar);
Color operator*(const Color &c1, const Color &c2);
Color operator+(const Color &c1, const Color &c2);

#endif /* AA3F6387_7A9D_46F0_8695_EF3803BB196D */
