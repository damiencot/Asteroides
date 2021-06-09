#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"

class Vaisseau : public ElementEspace{
    public:
        Vaisseau(sf::Color const& couleur);
        void actualiserEtat();
        void mettreAJour(float temps);

    private:
        bool accelerationEnCours{false};
        bool tourneAGauche{false};
        bool tourneADroite{false};

    static constexpr float ACCELERATION{7000.f};
    static constexpr float COEFF_FROTTEMENTS{2.f};
    static constexpr float VITESSE_ANGULAIRE{50.f};
};
#endif // VAISSEAU_H_INCLUDED
