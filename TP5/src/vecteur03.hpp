// Gardien //---------------------------------------------------------------------------------------
#ifndef _VECTEUR03_HPP_
#define _VECTEUR03_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <complexe.hpp>
#include <stdexcept>

// Classe  V e c t e u r //-------------------------------------------------------------------------
class Vecteur {
  private:
    unsigned     taille_;
    complexe_t * tableau_;

 public:
    // Constructeurs
    explicit Vecteur(unsigned t = 10) : taille_(t),tableau_(new complexe_t[taille_]) { }

    // Constructeur par copie
    Vecteur(const Vecteur & v) : taille_(v.taille_),tableau_(new complexe_t[taille_]) {
      for (unsigned i = 0; i < taille_; ++i)
        tableau_[i] = v[i];
    }

    // Constructeur par mouvement
    Vecteur(Vecteur && v) : taille_(v.taille_), tableau_(v.tableau_) { 
      v.tableau_ = nullptr;
      v.taille_ = 0;
    }

    ~Vecteur(void) { if (tableau_) delete [] tableau_; }

    // Affectation par copie
    Vecteur & operator=(const Vecteur & v) {
      if (this != &v) {
        if (taille_ != v.taille_)
          throw std::length_error("");
          
        for (unsigned i = 0; i<v.taille_; ++i)
          tableau_[i]=v[i];
      }

      return *this;
    }

    // Affectation par mouvement
    Vecteur & operator = (Vecteur && v) {
      std::swap (tableau_, v.tableau_);
      std::swap(taille_, v.taille_);

      return *this;
    }

    // Accesseurs
    unsigned getTaille(void) const { return taille_; }
    
    complexe_t & operator[](unsigned i) {
      if (i<taille_)
        return tableau_[i];

      throw std::out_of_range("");
    }

    const complexe_t & operator[](unsigned i) const {
      if (i<taille_)
        return tableau_[i];
   
      throw std::out_of_range("");
    }

    // Iterateurs
    typedef complexe_t* iterator;
    typedef const complexe_t* const_iterator;

    iterator begin() { return tableau_; }
    iterator end() { return tableau_ + (taille_ - 1); }
    const_iterator begin() const { return tableau_; }
    const_iterator end() const { return tableau_ + (taille_ - 1); }

};    

// Surcharge operateurs //--------------------------------------------------------------------------

//----------------------------------------------------------------------------------------operator<<
inline std::ostream & operator<<(std::ostream & flux,const Vecteur & v) {
    //for (unsigned i = 0 ; i < v.getTaille() ; ++i)
    for(auto & e : v)
      flux << e << " ";
    return flux;
}

//-----------------------------------------------------------------------------------------operator+
inline Vecteur operator+(const Vecteur & v1,const Vecteur & v2) {
    Vecteur v;
    for (unsigned i = 0; i<v1.getTaille(); ++i)
      v[i] = v1[i] + v2[i];

 return v;
}

//-----------------------------------------------------------------------------------------operator*
inline Vecteur operator*(const Vecteur & v1,const Vecteur & v2) {
    Vecteur v;

    for (unsigned i = 0; i<v1.getTaille(); ++i)
      v[i] = v1[i] * v2[i];

    return v;
}

// Fin //-------------------------------------------------------------------------------------------
#endif