#include "vecteur.h"

Vecteur::Vecteur() {
    m_container = new int(50);
}

Vecteur::~Vecteur() {
    delete m_container;
}