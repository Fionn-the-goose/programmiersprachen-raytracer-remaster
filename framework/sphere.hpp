#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#define GLM_ENABLE_EXPERIMENTAL

#include "shape.hpp"
#include "ray.hpp"
#include "hitpoint.hpp"

#include <iostream>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

class Sphere : public Shape{
    private:
        glm::vec3 center_{};
        double radius_{};
    public:
        Sphere();
        Sphere(glm::vec3 const& center, double radius);
        Sphere(glm::vec3 const& center, double radius, Material const& mat, std::string const& name);
        Sphere(glm::vec3 const& center, double radius, std::string const& name, Material const& mat);
        double area() const override;
        double volume() const override;
        std::ostream& print(std::ostream& os) const override;
        HitPoint intersect(Ray const& ray) override;
};

#endif