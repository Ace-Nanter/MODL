#include "polaire.h"

Polaire::Polaire() : m_angle(0.0), m_distance(0.0) { }

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


void Polaire::afficher(std::ostream & stream) const {
  stream << "(a=" << m_angle << ";d=" << m_distance << ")" ;
}


