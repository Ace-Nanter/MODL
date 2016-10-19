#include "histogramme.h"

Histo::Histo(const double & borneInf, const double & borneSup, const unsigned int & quantite) {
    const double intervalle = (borneSup - borneInf) / quantite;
    for(unsigned int i = 0 ; i < quantite ; i++) {
        const double & inf = borneInf + i * intervalle;
        const double & sup = borneSup - (quantite - (i + 1)) * intervalle;
        m_container.push_back(Classe(inf, sup));
    }
 }

Histo::~Histo() { }

const std::vector<Classe> & Histo::getClasses() const {
    return m_container;
}

void Histo::ajouter(const Echantillon & e) {
    for(unsigned int i = 0 ; i < e.getTaille() ; i++) {
        for(auto & c : m_container) {
            if(e.getValeur(i).getNombre() >= c.getBorneInf()
                && e.getValeur(i).getNombre() < c.getBorneSup()) {
                c.ajouter();
            }
        }
    }
}