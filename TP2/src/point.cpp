#include "point.h"



Point::Point() { }

Point::~Point() { }

std::ostream & operator << (std::ostream & stream, const Point & p) {
  p.afficher(stream);
  return stream;
}

std::istream & operator >> (std::istream & stream, Point & c) {
  std::cout << "cin not implemented" << std::endl;
  return stream;
}

