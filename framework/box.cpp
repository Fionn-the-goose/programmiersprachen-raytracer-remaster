#include "box.hpp"
#include <cmath>

Box::Box():
    min_{0, 0, 0},
    max_{1, 1, 1}{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
    min_{min},
    max_{max}{}

//hier überprüfen warum ich kein override verwenden sollte.
double Box::area() const{
}

//hier überprüfen warum ich kein override verwenden sollte.  
double Box::volume() const{
    return 1;
}