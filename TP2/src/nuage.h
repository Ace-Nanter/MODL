#pragma once

#include <cstdlib>
#include <vector>
#include <typeinfo>

#include "point.h"
#include "cartesien.h"
#include "polaire.h"

class Nuage {

    protected:
        std::vector<Point *> m_container;

    public:
        // Constructeurs/Destructeurs
        Nuage();
        ~Nuage();

        // Méthodes
        void ajouter(const Cartesien &);
        void ajouter(const Polaire &);
        const int size() const;
        
        typedef std::vector<Point *>::iterator iterator;
        typedef std::vector<Point *>::const_iterator const_iterator;
        
        iterator begin() { return m_container.begin(); }
        iterator end() { return m_container.end(); }
};

const Cartesien barycentre(Nuage &);

class BarycentreCartesien {
  public:
    BarycentreCartesien();
    ~BarycentreCartesien();

    const Cartesien operator()(Nuage &);
};

class BarycentrePolaire {
  public:
    BarycentrePolaire();
    ~BarycentrePolaire();

    const Polaire operator()(Nuage &);
};