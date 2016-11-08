#include "histo.h"

Histo::Histo(const double borneInf, const double borneSup, const unsigned int quantite) {
    const double intervalle = (borneSup - borneInf) / quantite;
    for(unsigned int i = 0u ; i < quantite ; i++) {
        const double inf = borneInf + i * intervalle;
        const double sup = inf + intervalle;
        m_container.insert(Classe(inf, sup));
    }
 }

const std::set<Classe> & Histo::getClasses() const {
    return m_container;
}

void Histo::ajouter(const Echantillon & e) {
    for(unsigned int i = 0 ; i < e.getTaille() ; i++) {
        Histo::classes_t::iterator it = m_container.begin();
        while(it != m_container.end()) {
            if(e.getValeur(i).getNombre() >= it->getBorneInf() 
                && e.getValeur(i).getNombre() < it->getBorneSup()) {
                    const_cast<Classe&>(*it).ajouter();

                break;
            }
            it++;
        }
    }
}