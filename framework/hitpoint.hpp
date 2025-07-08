#ifndef BUW_HITPOINT
#define BUW_HITPOINT

#include <string>
#include <glm/vec3.hpp>

#include "color.hpp"
#include <cmath>

struct HitPoint
{
    bool is_intersecting{false};
    double distance{INFINITY};
    std::string hit_name{" "};
    Color hit_color{0.0, 0.0, 0.0};
    glm::vec3 hit_point{0.0, 0.0, 0.0};
    glm::vec3 ray_direction{1.0f, 1.0f, 1.0f};
};


#endif