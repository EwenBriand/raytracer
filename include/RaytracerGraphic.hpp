/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** RaytracerGraphic
*/

#ifndef RAYTRACERGRAPHIC_HPP_
    #define RAYTRACERGRAPHIC_HPP_
    #include <fstream>

    #include "RaytracerCore.hpp"
    #include <SFML/Graphics.hpp>

class RaytracerGraphic {
    public:
        RaytracerGraphic(std::shared_ptr<sf::Image> image);
        void run();
        void drawPPM();

    private:
        void processMenuInput(const sf::Event &event);
        void updateMenuSelection();
        void renderMenu(sf::RenderWindow &window);

        std::shared_ptr<sf::Image> _image;
        sf::RenderWindow _window;
        sf::RectangleShape _menuBackground;
        sf::Font _font;
        sf::Text _menuText;
        sf::Text _startText;
        sf::Text _exitText;
        bool _showMenu;
        int _selectedOption;
};

#endif /* !RAYTRACERGRAPHIC_HPP_ */
