#include "polaire.h"

Polaire::Polaire() : m_angle(0.0), m_distance(0.0) { }

Polaire::Polaire(const Cartesien & c) {
  double angle = atan2(c.getY(), c.getX()) * (180.0 / (double) M_PI);
  double distance = sqrt(c.getX() * c.getX() + c.getY() * c.getY());

  m_angle = angle;
  m_distance = distance;
}

Polaire::Polaire(double const & angle, double const & distance) : m_angle(angle), m_distance(distance) { }

Polaire::~Polaire() { }

const double & Polaire::getAngle() const {
  return m_angle;
}

const double & Polaire::getDistance() const {
  return m_distance;
}

void Polaire::setAngle(const double & angle) {
  m_angle = angle;
}

void Polaire::setDistance(const double & distance) {
  m_distance = distance;
}

void Polaire::convertir(Cartesien & c) const {
  c.setX((double) m_distance * (double) cos(m_angle * ((double) M_PI) / 180.0));
  c.setY((double) m_distance * (double) sin(m_angle * ((double) M_PI) / 180.0));
}

void Polaire::convertir(Polaire & p) const {
  p.setAngle(m_angle);
  p.setDistance(m_distance);
}

void Polaire::afficher(std::ostream & stream) const {
  stream << "(a=" << m_angle << ";d=" << m_distance << ")" ;
}