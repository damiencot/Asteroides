#include "Vaisseau.h"
#include <iostream>

Vaisseau::Vaisseau(sf::Color const& couleur): ElementEspace{"ressources/vaisseau.png"}{
    sprite.setColor(couleur);
}

void Vaisseau::actualiserEtat(){
    accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    tourneAGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    tourneADroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Vaisseau::mettreAJour(float temps){
    if (accelerationEnCours){
        vitesse += Vecteur::creerDepuisAngle(ACCELERATION * temps, sprite.getRotation());
    }
    vitesse  -= vitesse * COEFF_FROTTEMENTS * temps;
    ElementEspace::mettreAJour(temps);
    if(tourneAGauche){
        sprite.rotate(- VITESSE_ANGULAIRE * temps);
    }
    if(tourneADroite){
        sprite.rotate(VITESSE_ANGULAIRE * temps);
    }
}
