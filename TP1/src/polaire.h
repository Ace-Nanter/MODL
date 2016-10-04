#pragma once

#include "point.h"
#include "cartesien.h"

class Polaire: public Point {

protected:
  double m_angle;
  double m_distance;

public:
  // Constructeurs/Destructeurs
  Polaire();
  Polaire(const Cartesien &);
  Polaire(double const &, double const &);
	~Polaire();


  // Getters
  const double & getAngle() const;
  const double & getDistance() const;
  
  // Setters
  void setAngle(const double &);
  void setDistance(const double &);

  void convertir(Cartesien &) const;
  void convertir(Polaire &) const;
  void afficher(std::ostream & stream) const;
};
