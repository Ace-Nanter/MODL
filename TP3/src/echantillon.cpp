#include "echantillon.h"


Echantillon::Echantillon() { }

Echantillon::~Echantillon() { }

const int Echantillon::getTaille() const {
    return m_container.size();
}

void Echantillon::ajouter(const double & v) {
    m_container.push_back(Valeur(v));
}

void Echantillon::ajouter(const Valeur & v) {
    m_container.push_back(v);
}

const Valeur Echantillon::getMinimum() const {
    std::vector<Valeur>::const_iterator it;
    it = std::min_element(m_container.begin(), m_container.end(), ValeurComparaison());
    return *it;
}


const Valeur Echantillon::getMaximum() const {
    std::vector<Valeur>::const_iterator it;
    it = std::max_element(m_container.begin(), m_container.end(), ValeurComparaison());
    return *it;
}