#ifndef __NUAGE_H__
#define __NUAGE_H__

#include <vector>

#include <point.h>
#include <cartesien.h>
#include <polaire.h>

template <typename T>
class Nuage {

    protected:
        std::vector<T> m_container;

    public:
        // Constructeurs/Destructeurs
        Nuage();
        ~Nuage();

        // Méthodes
        void ajouter(const T &);
        const int size() const;
        
        typedef T value_type;
        typedef typename std::vector<T>::iterator iterator;
        typedef typename std::vector<T>::const_iterator const_iterator;
        
        const_iterator begin() const { return m_container.begin(); }
        const_iterator end() const { return m_container.end(); }
};

/*
template <typename T>
T barycentre_v1(Nuage<T> &);

Polaire barycentre_v1(Nuage<Polaire> &);
*/

template <typename T>
typename T::value_type barycentre_v2(const T & n);

#include "nuage.cxx"
/*
const Cartesien barycentre(Nuage &);

class BarycentreCartesien {
  public:
    BarycentreCartesien();
    ~BarycentreCartesien();

    const Cartesien operator()(Nuage &);
};

class BarycentrePolaire {
  public:
    BarycentrePolaire();
    ~BarycentrePolaire();

    const Polaire operator()(Nuage &);
};
*/

#endif