#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>

class Point {

protected:
	
public:
  Point();
  ~Point();

  virtual void afficher(std::ostream & stream) const;

};
