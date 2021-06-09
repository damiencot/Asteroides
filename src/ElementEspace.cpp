#include "ElementEspace.h"

#include <iostream>

ElementEspace::Asteroide(std::string_view const& cheminImage)
{
    if(!texture.loadFromFile(cheminImage.data())){
            std::cerr << "L'image "<<  cheminImage << " n'a pas été correctement chargée" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(position.getX(), position.getY());
}

void ElementEspace::mettreAJour(float temps){
    auto deplacement = vitesse*temps;
    position += deplacement;
    sprite.setPosition(position.getX(), position.getY());
}

void ElementEspace::afficher(sf::RenderWindow &fenetre) const{
    auto affichages = std::array<Vecteur,9>{Vecteur{-1, -1}, Vecteur{0, -1},Vecteur{1, -1},
                                                                        Vecteur{-1, 0},Vecteur{0, 0},Vecteur{1, 0},
                                                                        Vecteur{-1, 1},Vecteur{0, 1},Vecteur{1, 1}};

    for(auto& affichage : affichages){
            auto transformation = sf::Transform();
            transformation.translate(affichage.x*Coordonnees::getLongueurEspace(), affichage.y*Coordonnees::getHauteurEspace())
            fenetre.draw(sprite, transformation);
    }

}


