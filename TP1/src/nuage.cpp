#include <nuage.h>

Nuage::Nuage() { }

Nuage::~Nuage()
{
    for(auto element : m_container) {
        delete element;
    }
}

BarycentreCartesien::BarycentreCartesien() { }

BarycentreCartesien::~BarycentreCartesien() { }

BarycentrePolaire::BarycentrePolaire() { }

BarycentrePolaire::~BarycentrePolaire() { }

void Nuage::ajouter(const Cartesien & c) {
    m_container.push_back(new Cartesien(c));
}

void Nuage::ajouter(const Polaire & p) {
    m_container.push_back(new Polaire(p));
}

const int Nuage::size() const {
    return m_container.size();
}

const Cartesien barycentre(Nuage & n) {
  double x = 0, y = 0;
  Nuage::const_iterator it;

  for(auto element : n) {
      if(typeid(*(element)) == typeid(Cartesien)) {
        x += ((Cartesien *) element)->getX();
        y += ((Cartesien *) element)->getY();
      }
      else if(typeid(*(element)) == typeid(Polaire)) {
          double distance = ((Polaire *) element)->getDistance();
          double angle = ((Polaire *) element)->getAngle();
          x += ((double) distance * (double) cos(angle * ((double) M_PI) / 180.0));
          y += ((double) distance * (double) sin(angle * ((double) M_PI) / 180.0));
      }
      else {
          std::cout << "Unrecognized type of Point !" << std::endl;
      }
  } 

  x = x / (double) n.size();
  y = y / (double) n.size();

  return Cartesien(x, y);  
}

const Cartesien BarycentreCartesien::operator()(Nuage & n) {
  return barycentre(n);
}

const Polaire BarycentrePolaire::operator()(Nuage & n) {
  return Polaire(barycentre(n));
}
