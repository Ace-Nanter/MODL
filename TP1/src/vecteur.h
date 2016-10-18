#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <cmath>
#include <string>
#include <cstdlib>


class Vecteur {
    protected:
        int * m_container;

    public:
        Vecteur();
        Vecteur(const Vecteur &);
        ~Vecteur();
}

/*
Définir une classe Vecteur conservant des entiers dans un tableau dynamique.
Proposer les méthodes nécessaires au fonctionnement de cette classe,
en particulier celles de la forme normale de Coplien (constructeur par défaut,
constructeur par copie, destructeur et opérateur de copie).
2) Ajouter des opérateurs pour l’insertion sur le flux en sortie (<<),
la concaténation (+), l’accès direct ([], accès lecture ou lecture/écriture)
et le produit scalaire (*).
3) Définir une classe Iterateur pour parcourir un vecteur avec les mécanismes élémentaires :
- itérateur au début du vecteur (fourni par le vecteur) :
Iterateur begin() - itérateur à la fin du vecteur (fourni par le vecteur) :
Iterateur end() - passage à l'élément suivant (préfixé) :
Iterateur & operator ++ () - passage à l'élément suivant (postfixé) :
Iterateur operator ++ (int) - accès à l'élément pointé : int operator * () -
comparaison entre deux itérateurs : bool operator == (const Iterateur &)
*/