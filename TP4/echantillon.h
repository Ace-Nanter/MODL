#ifndef __ECHANTILLON_H__
#define __ECHANTILLON_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "valeur.h"

class Echantillon {
    protected:
        std::vector<Valeur> m_container;
        
    public:
        // Constructeur / Destructeurs
        Echantillon();
        ~Echantillon();

        // Accesseurs
        const unsigned int getTaille() const;
        const bool empty() const;
        void ajouter(const double &);
        void ajouter(const Valeur &);
        const Valeur & getValeur(const unsigned int &) const;
        const Valeur getMinimum() const throw (std::domain_error);
        const Valeur getMaximum() const throw (std::domain_error);

        // Opérations
        const double Moyenne() const;
        const double EcartType() const;
};



#endif
