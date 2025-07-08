#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "color.hpp"
#include <string>
#include <iostream>

struct Material{
    std::string name_{"sample_mat"};
    Color ka_{0.0f,0.0f,0.0f};
    Color kd_{0.0f,0.0f,0.0f};
    Color ks_{0.0f,0.0f,0.0f};
    float m_{1.0f};
    
    friend std::ostream& operator<<(std::ostream& os, Material const& mat){
        os << mat.name_ << "\n"
        << " (" << mat.ka_.r << ", " << mat.ka_.g << ", " << mat.ka_.b <<")\n" 
        << " (" << mat.kd_.r << ", " << mat.kd_.g << ", " << mat.kd_.b << ")\n"
        << " (" << mat.ks_.r << ", " << mat.ks_.g << ", " << mat.ks_.b << ")\n" 
        << mat.m_ << "\n";
        return os;
    }
};


#endif