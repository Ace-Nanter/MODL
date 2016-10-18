#include "valeur.h"

Valeur::Valeur()
    : m_value(0.0) { }

Valeur::Valeur(const double & v) 
    : m_value(v) { }

Valeur::~Valeur() { }

const double & Valeur::getNombre() const {
    return m_value;
}

void Valeur::setNombre(const double & v) {
    m_value = v;
}