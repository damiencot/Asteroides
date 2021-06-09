#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"
#include "Asteroide.h"
#include "array.h"

using namespace std;

constexpr int LONGUEUR_FENETRE{800};
constexpr int HAUTEUR_FENETRE{600};
constexpr sf::Color COULEUR_VAISSEAU{sf::Color(128,255,128)};

int main()
{
    sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE,,HAUTEUR_FENETRE},  "Asteroide"};
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE,HAUTEUR_FENETRE);
    auto vaisseau = Vaisseau{COULEUR_VAISSEAU};
    auto asteroide = Asteroide{};
    auto elements = std::array<ElementEspace* , 2>{&asteroide, &vaisseau};
    auto chrono = sf::Clock{};
    auto asteroide = Asteroide{};
    while(fenetre.isOpen()){
        auto evenement = sf::Event{};
        while(fenetre.pollEvent(evenement)){
            if(evenement.type == sf::Event::Closed){
                fenetre.close();
            }
        }
        vaisseau.actualiserEtat();
        auto tempsBoucle = chrono.restart().asSeconds();
        vaisseau.mettreAJour(tempsBoucle);
        asteroide.mettreAJour(tempsBoucle);

        fenetre.clear();
        for(auto* element : elements){
            element -> afficher(fenetre);
        }
        fenetre.display();
    }
    return 0;
}
