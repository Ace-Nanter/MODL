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

  void afficher(std::ostream & stream) const;

};
