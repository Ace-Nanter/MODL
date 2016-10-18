#pragma once

#include "point.h"
#include "polaire.h"

class Cartesien: public Point {

protected:
  double m_x;
  double m_y;

public:
  // Constructeurs/Destructeurs
  Cartesien();
  Cartesien(const Cartesien &);
  Cartesien(const Polaire &);
	Cartesien(const double &, const double &);
	~Cartesien();


  // Getters
  const double & getX() const;
  const double & getY() const;
  
  // Setters
  void setX(const double &);
  void setY(const double &);

  void convertir(Cartesien &) const;
  void convertir(Polaire &) const;
  void afficher(std::ostream & stream) const;
};