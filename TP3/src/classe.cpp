#include "classe.h"

Classe::Classe()
    : m_borneInf(0), m_borneSup(0), m_quantite(0)
{ }

Classe::Classe(const double & a, const double & b)
    : m_borneInf(a), m_borneSup(b), m_quantite(0)
{ }

Classe::~Classe() { }

const double & Classe::getBorneInf() const {
    return m_borneInf;
}

const double & Classe::getBorneSup() const {
    return m_borneSup;
}

const unsigned int & Classe::getQuantite() const {
    return m_quantite;
}

void Classe::setBorneInf(const double & v) {
    m_borneInf = v;
}

void Classe::setBorneSup(const double & v) {
    m_borneSup = v;
}

void Classe::setQuantite(const unsigned int & n) {
    m_quantite = n;
}

void Classe::ajouter() {
    m_quantite++;
}
