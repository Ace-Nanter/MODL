#ifndef __PUISSANCE_H_
#define __PUISSANCE_H_


template <int T>
class Puissance {

    public:
        static const double valeur(double a) {
            return a * Puissance<T - 1>::valeur(a); 
        } 


};

template <>
class Puissance<0> {
    public:
        static const double valeur(double a) {
            return 1;
        }
};


#endif