#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "shape.hpp"
#include <iostream>
#include <glm/vec3.hpp>

class Sphere : public Shape{
    private:
        glm::vec3 center_{};
        double radius_{};
    public:
        Sphere();
        Sphere(glm::vec3 const& center, double radius);
        Sphere( glm::vec3 const& center, double radius, std::string const& name, Color const& color);
        double area() const override;
        double volume() const override;
        std::ostream& print(std::ostream& os) const override;
};

#endif