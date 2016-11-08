#ifndef __HistogrammeGRAMME_H__
#define __HistogrammeGRAMME_H__

#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <map>

#include "echantillon.h"
#include "classe.h"

template<class T = std::less<Classe>>
class Histogramme {

    protected:
        //std::vector<Classe> m_container;
        std::set<Classe, T> m_container;
        std::multimap<Classe, Valeur> m_values;

    public:

        // Déclaration typdef
        typedef typename std::set<Classe, T> classes_t;
        typedef typename std::multimap<Classe, Valeur> valeurs_t;
        typedef typename valeurs_t::const_iterator it_valeurs_t;

        // Constructeurs/Destructeurs
        template <class U>
        Histogramme(const Histogramme<U> & h);
        Histogramme(const double &, const double &, const unsigned int &);

        // Accesseurs
        const std::multimap<Classe, Valeur> & getValeurs() const;
        
        const std::set<Classe, T> & getClasses() const;
        std::pair<it_valeurs_t, it_valeurs_t> getValeurs(const Classe & c) const;

        void ajouter(const double);
        void ajouter(const Echantillon &);
};


#include "histogramme.cxx"

#endif