#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <cmath>
#include <string>
#include <cstdlib>

class Cartesien;
class Polaire;

class Point {

protected:
	
public:
  Point();
  ~Point();

  virtual void convertir(Cartesien &) const = 0;
  virtual void convertir(Polaire &) const = 0;

  virtual void afficher(std::ostream & stream) const = 0;
};

// Opérateurs
std::ostream & operator <<(std::ostream &, const Point &);  // Sortie
std::istream & operator >>(std::istream &, Point &);        // Entrée
