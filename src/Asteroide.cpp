#include "Asteroide.h"

#include <iostream>

Asteroide::Asteroide() : ElementEspace("ressources/asteroide.png")
{
    auto generateur = std::random_device{};
    auto distributionPosition = std::uniform_real_distribution<float>{-150,150};
    auto distributionVitesse = std::uniform_real_distribution<float>{80,120};
    auto distributionAngle = std::uniform_real_distribution<float>{0,360};
    position = {distributionPosition(generateur), distributionPosition(generateur)};
    vitesse  = Vecteur::creerDepuisAngle(distributionVitesse(generateur), distributionAngle(generateur));
}

