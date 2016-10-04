#include "cartesien.h"

Cartesien::Cartesien() : m_x(0), m_y(0) { }

Cartesien::Cartesien(const Polaire & p) {
  m_x = (double) p.getDistance() * (double) cos(p.getAngle() * ((double) M_PI) / 180.0);
  m_y = ((double) p.getDistance() * (double) sin(p.getAngle() * ((double) M_PI) / 180.0));
}

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

void Cartesien::convertir(Cartesien & c) const {
  c.setX(m_x);
  c.setY(m_y);
}

void Cartesien::convertir(Polaire & p) const {
  p.setAngle(atan2(m_y, m_x) * (180.0 / (double) M_PI));
  p.setDistance(sqrt(m_x * m_x + m_y * m_y));
}

void Cartesien::afficher(std::ostream & stream) const {
  stream << "(x=" << m_x << ";y=" << m_y << ")" ;
}