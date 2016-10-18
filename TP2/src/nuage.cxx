template <typename T>
Nuage<T>::Nuage() { }

template <typename T>
Nuage<T>::~Nuage() { }

template <typename T>
void Nuage<T>::ajouter(const T & e) {
    m_container.push_back(e);
}

template <typename T>
const int Nuage<T>::size() const {
    return m_container.size();
}

template <typename T>
typename T::value_type barycentre_v2(const T & n) {
    
    typename T::value_type ret;
    Cartesien tmp;
    Cartesien result(0,0);
    
    int size = std::distance(n.begin(), n.end());

    if(size != 0) {
        for(const auto & element : n) {  
            // Conversion
            element.convertir(tmp);

            // Calcul barycentre
            result.setX(result.getX() + tmp.getX());
            result.setY(result.getY() + tmp.getY());
        }    
        result.setX(result.getX() / (double) n.size());
        result.setY(result.getY() / (double) n.size());
    }

    // Conversion
    result.convertir(ret);

    return ret;
}
/*
Polaire barycentre_v2(Nuage<Polaire> & n) {
    
    double angle = 0;
    double distance = 0;
    Polaire result(0, 0);

    if(n.size() != 0) {
        for(const auto & element : n) {

            // Calcul barycentre
            distance += element.getDistance();
            angle += element.getAngle();
        }
        distance = distance / (double) n.size();
        angle = angle / (double) n.size();

        result.setDistance(distance);
        result.setAngle(angle);
    }

    return result;
}
*/
/*
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
*/

/*
const Cartesien BarycentreCartesien::operator()(Nuage & n) {
  return barycentre(n);
}

const Polaire BarycentrePolaire::operator()(Nuage & n) {
  return Polaire(barycentre(n));
}
*/