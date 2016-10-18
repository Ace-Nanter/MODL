#ifndef __FACTORIELLE_H_
#define __FACTORIELLE_H_


template <int T>
class Factorielle {

    public:
        static const unsigned long valeur = T * Factorielle<T - 1>::valeur;


};

template <>
class Factorielle<0> {
    public:
        static const unsigned long valeur = 1;
};


#endif