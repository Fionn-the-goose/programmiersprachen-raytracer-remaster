#include "sphere.hpp"
#include <cmath>

Sphere::Sphere():
    center_{0, 0, 0},
    radius_{0}{}

Sphere::Sphere(glm::vec3 const& center, double radius = 1):
    center_{center},
    radius_{radius}{}

//hier überprüfen warum ich kein override verwenden sollte.
double Sphere::area()const{
    return 4*M_PI*pow(radius_,2);
}

//hier überprüfen warum ich kein override verwenden sollte.  
double Sphere::volume() const{
    return (4/3)*M_PI*pow(radius_,3);
}