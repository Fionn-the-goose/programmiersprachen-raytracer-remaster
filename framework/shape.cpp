#include "shape.hpp"

Shape::Shape():
    name_{"shape"},
    color_{Color{1.0f,1.0f,1.0f}}{
        //std::cout << "construkt: " << name_ << "." << std::endl;
    }

Shape::Shape(std::string const& name, Color const& color):
    name_{name},
    color_{color}{
        //std::cout << "construkt: " << name_ << "." << std::endl;
    }

Shape::~Shape(){
    //std::cout << "Livetime of: " << name_ << ", has enden." << std::endl;
}

std::ostream& Shape::print(std::ostream& os) const{
    os << "name: " << name_ << std::endl;
    os << "color: " << color_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}