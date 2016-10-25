#ifndef __HISTO_H__
#define __HISTO_H__

#include <algorithm>
//#include <vector>
#include <set>
#include <iostream>

#include "echantillon.h"
#include "classe.h"

class Histo {

    protected:
        //std::vector<Classe> m_container;
        std::set<Classe> m_container;

    public:
        
        // Constructeurs/Destructeurs
        Histo(const double, const double, const unsigned int);

        // Accesseurs
        const std::set<Classe> & getClasses() const;

        void ajouter(const Echantillon &);

        typedef typename std::set<Classe> classes_t;
};

#endif