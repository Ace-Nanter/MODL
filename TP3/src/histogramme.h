#ifndef __HISTOGRAMME_H__
#define __HISTOGRAMME_H__

#include <algorithm>
#include <vector>

#include "echantillon.h"
#include "classe.h"

class Histo {

    protected:
        std::vector<Classe> m_container;

    public:
        
        // Constructeurs/Destructeurs
        Histo(const double &, const double &, const unsigned int &);
        ~Histo();

        // Accesseurs
        const std::vector<Classe> & getClasses() const;

        void ajouter(const Echantillon &);

        typedef typename std::vector<Classe> classes_t;

};


#endif