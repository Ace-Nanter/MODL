#ifndef __EXPONENTIELLE_H_
#define __EXPONENTIELLE_H_

#include "factorielle.h"
#include "puissance.h"

template <int T>
class Exponentielle {

    public:
        static const double valeur(double a) {
            return Exponentielle<T - 1>::valeur(a) +
                (Puissance<T>::valeur(a) / Factorielle<T>::valeur);
        } 
};

template <>
class Exponentielle<0> {
    public:
        static const double valeur(double a) {
            return 1;
        }
};


#endif