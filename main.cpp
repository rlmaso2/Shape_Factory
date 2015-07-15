#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "mesh.h"

int main(){
  
  try {
    
    Mesh mesh("employees.xml");
    mesh.process();
    
  } catch (std::exception&e) {
    
    std::cerr << "Exception caught: " << e.what() << '\n';
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
