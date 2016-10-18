#ifndef __COSINUS_H__
#define __COSINUS_H__


#include "factorielle.h"
#include "puissance.h"

template <int T>
class Cosinus {

    public:
        static const double valeur(double a) {
            return Cosinus<T - 1>::valeur(a) +
                (Puissance<T>::valeur(-1.0) *
                    (Puissance<2 * T>::valeur(a) / Factorielle<2 * T>::valeur));
        } 
};

template <>
class Cosinus<0> {
    public:
        static const double valeur(double a) {
            return 1;
        }
};



#endif