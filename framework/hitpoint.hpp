#ifndef BUW_HITPOINT
#define BUW_HITPOINT

#include <string>
#include <glm/vec3.hpp>

#include "color.hpp"

struct HitPoint
{
    bool is_intersecting{};
    double distance{};
    std::string hit_name{};
    Color hit_color{};
    glm::vec3 hit_point{};
    glm::vec3 ray_direction{};
};


#endif