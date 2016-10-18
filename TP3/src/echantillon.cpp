#include "echantillon.h"


Echantillon::Echantillon() { }

Echantillon::~Echantillon() { }

const int Echantillon::getTaille() const {
    return m_container.size();
}

const bool Echantillon::empty() const {
    return (m_container.size() == 0);
}

void Echantillon::ajouter(const double & v) {
    m_container.push_back(Valeur(v));
}

void Echantillon::ajouter(const Valeur & v) {
    m_container.push_back(v);
}

const Valeur Echantillon::getMinimum() const throw (std::domain_error) {
    if(empty()) {
        throw std::domain_error("Vecteur vide !");
    }
    std::vector<Valeur>::const_iterator it;
    it = std::min_element(m_container.begin(), m_container.end(), ValeurComparaison());
    return *it;
}


const Valeur Echantillon::getMaximum() const throw (std::domain_error) {
    if(empty()) {
        throw std::domain_error("Vecteur vide !");
    }
    std::vector<Valeur>::const_iterator it;
    it = std::max_element(m_container.begin(), m_container.end(), ValeurComparaison());
    return *it;
}