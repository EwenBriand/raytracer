/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** main.cpp
*/

#include "ParserFile.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    ParserFile file(av[1]);
    std::vector<IPrimitives *> primitives = file.getPrimitives();
    Camera camera = file.getCamera();
    sf::RenderWindow window(sf::VideoMode(camera.getResolutionX(), camera.getResolutionY()), "Raytracer");
    sf::Image image;
    image.create(camera.getResolutionX(), camera.getResolutionY());
    for (int i = 0; i < camera.getResolutionX(); i++) {
        for (int j = 0; j < camera.getResolutionY(); j++) {
            float u = (float)i / camera.getResolutionX();
            float v = (float)j / camera.getResolutionY();
            Ray ray = camera.getRay(u, v);
            image.setPixel(i, j, sf::Color::Black);
            for (long unsigned int k = 0; k < primitives.size(); k++) {
                if (primitives[k]->hit(ray)) {
                    image.setPixel(i, j, sf::Color(primitives[k]->getColor().getR(), primitives[k]->getColor().getG(), primitives[k]->getColor().getB()));
                    break;
                }
            }
        }
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
