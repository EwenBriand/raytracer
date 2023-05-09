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
        /**
         * @brief Construct a new Raytracer Graphic object from a sf::Image
         *
         * @param image
         */
        RaytracerGraphic(std::shared_ptr<sf::Image> image);
        /**
         * @brief Run the graphic interface
         *
         */
        void run();
        /**
         * @brief Draw the image in a ppm file
         *
         */
        void drawPPM();

    private:
        /**
         * @brief Process the input of the user
         *
         * @param event
         */
        void processMenuInput(const sf::Event &event);
        /**
         * @brief Update the selection of the menu
         *
         */
        void updateMenuSelection();
        /**
         * @brief Render the menu
         *
         * @param window
         */
        void renderMenu(sf::RenderWindow &window);
        /**
         * @brief Image to render
         */
        std::shared_ptr<sf::Image> _image;
        /**
         * @brief Window of the interface
         */
        sf::RenderWindow _window;
        /**
         * @brief Menu background
         */
        sf::RectangleShape _menuBackground;
        /**
         * @brief Menu font
         */
        sf::Font _font;
        /**
         * @brief Menu text
         */
        sf::Text _menuText;
        /**
         * @brief Start text
         */
        sf::Text _startText;
        /**
         * @brief Exit text
         */
        sf::Text _exitText;
        /**
         * @brief Boolean to know if the menu is displayed
         */
        bool _showMenu;
        /**
         * @brief Selected option of the menu
         */
        int _selectedOption;
};

#endif /* !RAYTRACERGRAPHIC_HPP_ */
