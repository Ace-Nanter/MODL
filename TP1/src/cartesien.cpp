#include "cartesien.h"

Cartesien::Cartesien() : m_x(0), m_y(0) { }

Cartesien::Cartesien(const double & x, const double & y) : m_x(x), m_y(y) { }

Cartesien::~Cartesien() { }

const double & Cartesien::getX() const {
  return m_x;
}

const double & Cartesien::getY() const {
  return m_y;
}

void Cartesien::setX(const double & x) {
  m_x = x;
}

void Cartesien::setY(const double & y) {
  m_y = y;
}

void Cartesien::afficher(std::ostream & stream) const {
  stream << "(x=" << m_x << ";y=" << m_y << ")" ;
}
