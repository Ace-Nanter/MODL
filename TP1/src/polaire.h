#pragma once

#include "point.h"

class Polaire: public Point {

protected:
  double m_angle;
  double m_distance;

public:
  // Constructeurs/Destructeurs
  Polaire();
  Polaire(double const &, double const &);
	~Polaire();


  // Getters
  const double & getAngle() const;
  const double & getDistance() const;
  
  // Setters
  void setAngle(const double &);
  void setDistance(const double &);
  
  void afficher(std::ostream & stream) const;
  
};
