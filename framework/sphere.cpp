#include "sphere.hpp"
#include <cmath>

Sphere::Sphere():
    Shape::Shape{},
    center_{0, 0, 0},
    radius_{1}{}

Sphere::Sphere(glm::vec3 const& center, double radius = 1):
    Shape::Shape{},
    center_{center},
    radius_{radius}{}

Sphere::Sphere( glm::vec3 const& center, double radius, Color const& color, std::string const& name):
    Shape::Shape{name, color},
    center_{center},
    radius_{radius}{}

Sphere::Sphere( glm::vec3 const& center, double radius, std::string const& name, Color const& color):
    Shape::Shape{name, color},
    center_{center},
    radius_{radius}{}

//hier überprüfen warum ich kein override verwenden sollte.
double Sphere::area()const{
    return fabs(4*M_PI*pow(radius_,2));
}

//hier überprüfen warum ich kein override verwenden sollte.  
double Sphere::volume() const{
    return fabs((4.0/3.0)*M_PI*pow(radius_,3));
}

//erklär hier die verwendung von override.
std::ostream& Sphere::print(std::ostream& os) const{
    Shape::print(os);
    os << "objekt-type: Box" << std::endl;
    os << "radius: " << radius_ << std::endl;
    os << "area: " <<  area() << std::endl;
    os << "volume: " <<  volume() << std::endl;
    return os;
}

HitPoint Sphere::intersect(Ray const& ray){
    float distance{5.0};
    bool has_hit{glm::intersectRaySphere(
        ray.origin,
        glm::normalize(ray.direction),
        center_,
        std::pow(radius_,2),
        distance)};
    HitPoint hitpoint{
        has_hit,
        distance,
        name_,
        color_,
        ray.origin + (distance * glm::normalize(ray.direction)),
        glm::normalize(ray.direction)};
    return hitpoint;
}