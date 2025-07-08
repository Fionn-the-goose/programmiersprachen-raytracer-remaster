#include "shape.hpp"

Shape::Shape():
    name_{"shape"},
    mat_{}{
        //std::cout << "construkt: " << name_ << "." << std::endl;
    }

Shape::Shape(std::string const& name, Material const& mat):
    name_{name},
    mat_{mat}{
        //std::cout << "construkt: " << name_ << "." << std::endl;
    }

Shape::~Shape(){
    //std::cout << "Livetime of: " << name_ << ", has enden." << std::endl;
}

std::ostream& Shape::print(std::ostream& os) const{
    os << "name: " << name_ << std::endl;
    os << "color: " << mat_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}