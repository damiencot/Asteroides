#ifndef ELEMENTESPACE_H
#define ELEMENTESPACE_H


#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"


class ElementEspace
{
    public:
        ElementEspace(std::string_view const&);
        void mettreAJour(float temps);
        void afficher(sf::RenderWindow &fenetre) const;

    protected:
        sf::Texture texture;
        sf::Sprite sprite{};
        Coordonnees position{};
        Vecteur vitesse {0.f, 0.f,};
};

#endif // ELEMENTESPACE_H
