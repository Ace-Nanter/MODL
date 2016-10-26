#ifndef __HistogrammeGRAMME_H__
#define __HistogrammeGRAMME_H__

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>

#include "echantillon.h"
#include "classe.h"

template<class T = std::less<Classe>>
class Histogramme {

    protected:
        //std::vector<Classe> m_container;
        std::set<Classe, T> m_container;
        std::multimap<Classe, Valeur> m_values;

    public:
        
        // Constructeurs/Destructeurs
        template <class U>
        Histogramme(const Histogramme<U> & h);
        Histogramme(const double &, const double &, const unsigned int &);

        // Accesseurs
        const std::multimap<Classe, Valeur> & getValeurs() const;
        const std::set<Classe, T> & getClasses() const;

        void ajouter(const double);
        void ajouter(const Echantillon &);

        typedef typename std::set<Classe, T> classes_t;
        typedef typename std::multimap<Classe, Valeur> valeurs_t;
};


#include "histogramme.cxx"

#endif