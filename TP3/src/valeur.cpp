#include "valeur.h"

Valeur::Valeur()
    : m_value(0.0), m_nom("inconnu") { }

Valeur::Valeur(const double d) 
    : m_value(d), m_nom("inconnu") { }

Valeur::Valeur(const double d, const std::string & nom)
    : m_value(d), m_nom(nom) { }

Valeur::~Valeur() { }

const double Valeur::getNombre() const {
    return m_value;
}

const double Valeur::getNote() const {
    return m_value;
}

const std::string Valeur::getEtudiant() const {
    return m_nom;
}

void Valeur::setNombre(const double v) {
    m_value = v;
}

void Valeur::setNote(const double v) {
    m_value = v;
}

void Valeur::setEtudiant(const std::string & nom) {
    m_nom = nom;
}