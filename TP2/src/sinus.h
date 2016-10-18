#ifndef __SINUS_H__
#define __SINUS_H__


#include "factorielle.h"
#include "puissance.h"

template <int T>
class Sinus {

    public:
        static const double valeur(double a) {
            return Sinus<T - 1>::valeur(a) +
                (Puissance<T>::valeur(-1.0) *
                    (Puissance<2 * T + 1>::valeur(a) / Factorielle<2 * T + 1>::valeur));
        } 
};

template <>
class Sinus<0> {
    public:
        static const double valeur(double a) {
            return 0;
        }
};



#endif