#include <cstdlib>
#include <vector>
#include <point.h>
#include <cartesien.h>
#include <polaire.h>
#include <sstream>


int main() {

  std::vector<Point *> container;

  for(int i = 0 ; i < 5 ; i++) {
      container.push_back(new Cartesien(i,i));
      container.push_back(new Polaire(i,i));
  }

  for(auto & element : container) {
    std::cout << *element << std::endl;
  }

  return EXIT_SUCCESS;
}
