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
        
        typedef typename std::vector<T>::iterator iterator;
        typedef typename std::vector<T>::const_iterator const_iterator;
        
        iterator begin() { return m_container.begin(); }
        iterator end() { return m_container.end(); }
};

template <typename T>
T barycentre_v1(Nuage<T> &);

Polaire barycentre_v1(Nuage<Polaire> &);

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