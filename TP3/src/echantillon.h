#ifndef __ECHANTILLON_H__
#define __ECHANTILLON_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include "valeur.h"

class Echantillon {
    protected:
        std::vector<Valeur> m_container;

    public:
        // Constructeur / Destructeurs
        Echantillon();
        ~Echantillon();

        // Accesseurs
        const int getTaille() const;
        void ajouter(const double &);
        void ajouter(const Valeur &);
        const Valeur getMinimum() const;
        const Valeur getMaximum() const;
};



#endif