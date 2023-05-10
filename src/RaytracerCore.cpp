/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** RaytracerCore
*/

#include "RaytracerCore.hpp"

RaytracerCore::RaytracerCore(const std::string &sceneFile) : _file(sceneFile)
{
    _primitives = _file.getPrimitives();
    _lights = _file.getLights();
    _camera = _file.getCamera();
}

std::shared_ptr<sf::Image> RaytracerCore::renderImage()
{
    auto image = std::make_shared<sf::Image>();
    image->create(_camera.getResolutionX(), _camera.getResolutionY());

    for (int i = 0; i < _camera.getResolutionX(); i++) {
        for (int j = 0; j < _camera.getResolutionY(); j++) {
            float u = (float) i / _camera.getResolutionX();
            float v = (float) j / _camera.getResolutionY();
            Math::Ray ray = _camera.getRay(u, v);
            image->setPixel(i, j, sf::Color::Black);
            std::shared_ptr<Primitive::IPrimitives> closest = nullptr;
            Math::Point3D intersexe;
            Color temp = Color(0, 0, 0);

            for (long unsigned int k = 0; k < _primitives.size(); k++) {
                if (_primitives[k]->hit(ray)
                    && (closest == nullptr
                        || _camera.getPosition().distance(
                               _primitives[k]->getIntersexe())
                            < _camera.getPosition().distance(intersexe))) {
                    if (_primitives[k]->isNeon()) {
                        _coordsToBlur.push_back(std::make_pair(i, j));
                        _raysToBlur.push_back(ray);
                    }
                    closest = _primitives[k];
                    intersexe = _primitives[k]->getIntersexe();

                    temp = Color(_primitives[k]->getColor().getR(),
                        _primitives[k]->getColor().getG(),
                        _primitives[k]->getColor().getB());
                    for (long unsigned int l = 0; l < _lights.size(); l++)
                        if (!_lights[l]->is_cut(
                                _primitives[k]->getIntersexe(), _primitives))
                            temp = _lights[l]->define_color(
                                _primitives[k]->getIntersexe(),
                                _primitives[k]->getNormal(), temp, 0.2, false);
                        else
                            temp = _lights[l]->define_color(
                                _primitives[k]->getIntersexe(),
                                _primitives[k]->getNormal(), temp, 0.2, true);
                }
            }

            for (long unsigned int k = 0; k < _lights.size(); k++) {
                if (_lights[k]->getPrimitive() != nullptr
                    && _lights[k]->getPrimitive()->hit(ray)
                    && (closest == nullptr
                        || _camera.getPosition().distance(
                               _lights[k]->getPrimitive()->getIntersexe())
                            < _camera.getPosition().distance(intersexe))) {
                    temp = Color(_lights[k]->getColor().getR(),
                        _lights[k]->getColor().getG(),
                        _lights[k]->getColor().getB());
                }
            }
            image->setPixel(
                i, j, sf::Color(temp.getR(), temp.getG(), temp.getB()));
        }
    }

    return image;
}

std::shared_ptr<sf::Image> RaytracerCore::PostProcess(const sf::Image &image)
{
    if (_coordsToBlur.empty())
        return std::make_shared<sf::Image>(image);
    sf::Image blurredImg = image;
    for (int i = 0; i < 50; i++) {
        blurredImg = GaussianBlur(blurredImg);
    }
    sf::Image linkedImage = addImages(image, blurredImg);
    sf::Image maskedImage = applyMask(linkedImage);
    sf::Image maxiBlurred = GaussianBlur(maskedImage);
    for (int i = 0; i < 30; i++) {
        maxiBlurred = GaussianBlur(maxiBlurred);
    }
    sf::Image resultImage = addImages(image, maxiBlurred);
    return std::make_shared<sf::Image>(resultImage);
}

sf::Image RaytracerCore::GaussianBlur(const sf::Image &image)
{
    sf::Image blurredImg = image;
    const float kernel[3][3] = {
        {0.0751136, 0.123841, 0.0751136},
        {0.123841, 0.20418, 0.123841},
        {0.0751136, 0.123841, 0.0751136}
    };

    for (auto coord : _coordsToBlur) {
        int x = coord.first;
        int y = coord.second;
        float weightedSum = 0.0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int neighborX = x + i;
                int neighborY = y + j;
                float kernelValue = kernel[i+1][j+1];
                weightedSum += kernelValue * (float)image.getPixel(neighborX, neighborY).r;
            }
        }
        sf::Color blurredColor(weightedSum, weightedSum, weightedSum);
        blurredImg.setPixel(x, y, blurredColor);
    }
    return blurredImg;
}

sf::Image RaytracerCore::addImages(const sf::Image& image1, const sf::Image& image2) {
    sf::Image resultImage;
    sf::Vector2u imageSize = image1.getSize();

    resultImage.create(imageSize.x, imageSize.y);

    for (unsigned int x = 0; x < imageSize.x; x++) {
        for (unsigned int y = 0; y < imageSize.y; y++) {
            sf::Color color1 = image1.getPixel(x, y);
            sf::Color color2 = image2.getPixel(x, y);
            sf::Uint8 r = std::min(color1.r + color2.r, 255);
            sf::Uint8 g = std::min(color1.g + color2.g, 255);
            sf::Uint8 b = std::min(color1.b + color2.b, 255);

            sf::Color resultColor(r, g, b);
            resultImage.setPixel(x, y, resultColor);
        }
    }

    return resultImage;
}


sf::Image RaytracerCore::applyMask(const sf::Image &image)
{
    sf::Image maskedImg = image;

    for (auto coord : _coordsToBlur) {
        int x = coord.first;
        int y = coord.second;
        maskedImg.setPixel(x, y, sf::Color::White);
    }
    return maskedImg;
}


/*
Post preocessing
 Step 1:  Cpy image de base appliquer le flou gaussien sur la nouvelle image pour pouvoir creer le masque
    Voir Noyaux de convolution
 Step 2: cpy image de flouté et faire un masque dessus
    En fonction d'un treshold set pixel to blanc ou noir (maybe 0.5)
 Step 3: Appliquer le flou gaussien sur le masque
 Step 4: Additionner li'mage de base et l'image avec le masque
*/