#include "box.hpp"
#include <cmath>

Box::Box():
    Shape::Shape{},    
    min_{0, 0, 0},
    max_{1, 1, 1}{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
    Shape::Shape{},
    min_{min},
    max_{max}{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Color color):
    Shape::Shape{name,color},
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

//erklär hier die verwendung von override.
std::ostream& Box::print(std::ostream& os) const{
    Shape::print(os);
    os << "objekt-type: Box" << std::endl;
    os << "length: " <<  fabs(min_.x - max_.x) << std::endl;
    os << "width: " <<  fabs(min_.y - max_.y) << std::endl;
    os << "height: " <<  fabs(min_.z - max_.z) << std::endl;
    os << "area: " <<  area() << std::endl;
    os << "volume: " <<  volume() << std::endl;
    return os;
}