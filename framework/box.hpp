#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape{
    private:
        glm::vec3 min_{};
        glm::vec3 max_{};
    public:
        Box();
        Box(glm::vec3 const& min, glm::vec3 const& max);
        Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Material const& mat);
        double area() const override;
        double volume() const override;
        std::ostream& print(std::ostream& os) const override;
        HitPoint intersect(Ray const& ray) override;
};

#endif