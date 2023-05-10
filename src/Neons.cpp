/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** Neon
*/

#include "Neons.hpp"

BoxeNeon::BoxeNeon(const libconfig::Setting &setting)
{
    _isNeon = true;
    _intensity = 3.9;
}

Color BoxeNeon::getColor() const {
  Color boxeColor = Boxes::getColor();
  Color neonColor = Color(_neonColor.getR() * _intensity, _neonColor.getG() * _intensity, _neonColor.getB() * _intensity);
  Color finalColor = boxeColor + neonColor;

  finalColor.setColor(std::min(255, std::max(0, finalColor.getR())),
                      std::min(255, std::max(0, finalColor.getG())),
                      std::min(255, std::max(0, finalColor.getB())));
  return finalColor;
}


/*
Processing
Get all ray that fit with the néons
*/

/*
Post preocessing
 Step 1:  Cpy image de base appliquer le flou gaussien sur la nouvelle image pour pouvoir creer le masque
    Voir Noyaux de convolution
 Step 2: cpy image de flouté et faire un masque dessus
    En fonction d'un treshold set pixel to blanc ou noir (maybe 0.5)
 Step 3: Appliquer le flou gaussien sur le masque
 Step 4: Additionner li'mage de base et l'image avec le masque
*/