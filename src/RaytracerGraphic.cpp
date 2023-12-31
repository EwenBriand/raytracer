/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** RaytracerGraphic
*/

#include "RaytracerGraphic.hpp"

RaytracerGraphic::RaytracerGraphic(std::shared_ptr<sf::Image> image)
    : _image(image),
      _window(sf::VideoMode(_image->getSize().x, _image->getSize().y), "Raytracer"),
      _showMenu(true), _selectedOption(0)
{
    if (!_font.loadFromFile("fonts/Roboto/Roboto-BoldItalic.ttf"))
        throw std::runtime_error("no font found");

    _menuText.setFont(_font);
    _menuText.setString("Raytracer de bg");
    _menuText.setCharacterSize(48);
    _menuText.setFillColor(sf::Color::White);
    _menuText.setPosition(_image->getSize().x / 2 - _menuText.getGlobalBounds().width / 2, _image->getSize().y / 4);

    _startText.setFont(_font);
    _startText.setString("Start");
    _startText.setCharacterSize(32);
    _startText.setFillColor(sf::Color::Magenta);
    _startText.setPosition(_image->getSize().x / 2 - _startText.getGlobalBounds().width / 2, _image->getSize().y / 2);

    _exitText.setFont(_font);
    _exitText.setString("Exit");
    _exitText.setCharacterSize(32);
    _exitText.setFillColor(sf::Color::White);
    _exitText.setPosition(_image->getSize().x / 2 - _exitText.getGlobalBounds().width / 2, _image->getSize().y / 2 + _startText.getGlobalBounds().height * 2);

    _menuBackground.setSize(sf::Vector2f(_image->getSize().x, _image->getSize().y));
    _menuBackground.setFillColor(sf::Color(0, 0, 0, 200));
}

void RaytracerGraphic::drawPPM()
{
    std::ofstream file("image.ppm");
    if (!file.is_open())
        throw std::runtime_error("cannot open file");
    file << "P3" << std::endl;
    file << _image->getSize().x << " " << _image->getSize().y << std::endl;
    file << "255" << std::endl;
    for (unsigned int i = 0; i < _image->getSize().y; i++) {
        for (unsigned int j = 0; j < _image->getSize().x; j++) {
            sf::Color color = _image->getPixel(j, i);
            file << static_cast<int>(color.r) << " " << static_cast<int>(color.g) << " " << static_cast<int>(color.b) << "  ";
        }
        file << std::endl;
    }
}

void RaytracerGraphic::processMenuInput(const sf::Event &event)
{
    if (_showMenu) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
                updateMenuSelection();
            if (event.key.code == sf::Keyboard::Enter) {
                if (_selectedOption == 0)
                    _showMenu = false;
                else if (_selectedOption == 1)
                    _window.close();
            }
        }
    } else {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
            _showMenu = !_showMenu;
    }
}

void RaytracerGraphic::updateMenuSelection()
{
    _selectedOption = (_selectedOption + 1) % 2;
    _startText.setFillColor(_selectedOption == 0 ? sf::Color::Magenta : sf::Color::White);
    _exitText.setFillColor(_selectedOption == 1 ? sf::Color::Magenta : sf::Color::White);
}

void RaytracerGraphic::renderMenu(sf::RenderWindow& window)
{
    if (_showMenu) {
        window.draw(_menuBackground);
        window.draw(_menuText);
        window.draw(_startText);
        window.draw(_exitText);
    }
}

void RaytracerGraphic::run()
{
    sf::Texture texture;
    texture.loadFromImage(*_image);
    sf::Sprite sprite(texture);

    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();

            processMenuInput(event);
        }
        _window.clear();
        _window.draw(sprite);
        renderMenu(_window);
        _window.display();
    }
}
