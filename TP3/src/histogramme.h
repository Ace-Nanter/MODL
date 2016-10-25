#ifndef __HistogrammeGRAMME_H__
#define __HistogrammeGRAMME_H__

#include <algorithm>
#include <vector>

#include "echantillon.h"
#include "classe.h"

template<class T = std::less<Classe>>
class Histogramme {

    protected:
        //std::vector<Classe> m_container;
        std::set<Classe, T> m_container;

    public:
        
        // Constructeurs/Destructeurs
        Histogramme(const double &, const double &, const unsigned int &);

        // Accesseurs
        const std::set<Classe, T> & getClasses() const;

        void ajouter(const Echantillon &);

        typedef typename std::set<Classe, T> classes_t;
};


#include "histogramme.cxx"

#endif