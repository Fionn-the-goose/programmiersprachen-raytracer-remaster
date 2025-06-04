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
    double l{fabs(min_.x - max_.x)}; 
    double w{fabs(min_.y - max_.y)}; 
    double h{fabs(min_.z - max_.z)}; 
    return 2*(w*l+h*l+h*w);
}

//hier überprüfen warum ich kein override verwenden sollte.  
double Box::volume() const{
    double l{fabs(min_.x - max_.x)}; 
    double w{fabs(min_.y - max_.y)}; 
    double h{fabs(min_.z - max_.z)}; 
    return w*h*l;
}