#include "classe.h"

Classe::Classe()
    : m_borneInf(0), m_borneSup(0), m_quantite(0)
{ }

Classe::Classe(const double a, const double b)
    : m_borneInf(a), m_borneSup(b), m_quantite(0)
{ }

Classe::Classe(const double inf, const double sup, const double quantite)
    : m_borneInf(inf), m_borneSup(sup), m_quantite(quantite)
{ }

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

const bool Classe::operator<(const Classe & c) const {
    return getBorneInf() < c.getBorneInf();
}

const bool Classe::operator>(const Classe & c) const {
    return getBorneInf() > c.getBorneInf();
}

// Foncteur
bool ComparateurQuantite<Classe>::operator()(const Classe & c1, const Classe & c2) const {
    return (c1.getQuantite() == c2.getQuantite()) ?
        c1.getBorneInf() < c2.getBorneInf()
        : c1.getQuantite() > c2.getQuantite();
}