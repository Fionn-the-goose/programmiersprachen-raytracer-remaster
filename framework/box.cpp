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

Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Material const& mat):
    Shape::Shape{name,mat},
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

//void Box::intersect_plane( bool& has_hit, HitPoint& hit, float p_0, float p_1){
//
//}

HitPoint Box::intersect(Ray const& ray){
    HitPoint hit_final{};
    bool has_hit = false;
    Ray ray_local{ray};
    float tmin = __FLT_MAX__;
    
    float tmin_x = (min_.x-ray.origin.x)/ray.direction.x;
    float tmax_x = (max_.x-ray.origin.x)/ray.direction.x;
    glm::vec3 p_x_min = ray.origin + tmin_x * ray_local.direction;
    glm::vec3 p_x_max = ray.origin + tmax_x * ray.direction;

    float tmin_y = (min_.y-ray.origin.y)/ray.direction.y;
    float tmax_y = (max_.y-ray.origin.y)/ray.direction.y;
    glm::vec3 p_y_min = ray.origin + tmin_y * ray.direction;
    glm::vec3 p_y_max = ray.origin + tmax_y * ray.direction;   

    float tmin_z = (min_.z-ray.origin.z)/ray.direction.z;
    float tmax_z = (max_.z-ray.origin.z)/ray.direction.z;
    glm::vec3 p_z_min = ray.origin + tmin_z * ray.direction;
    glm::vec3 p_z_max = ray.origin + tmax_z * ray.direction;

    if(p_x_min.y <= max_.y && p_x_min.y >= min_.y && p_x_min.z <= max_.z && p_x_min.z >= min_.z){
        has_hit = true;
        hit_final.hit_point = p_x_min;
        tmin = tmin_x;
    }    

    if(p_x_max.y <= max_.y && p_x_max.y >= min_.y && p_x_max.z <= max_.z && p_x_max.z >= min_.z){
        has_hit = true;
        if(tmin_x > tmax_x){
            hit_final.hit_point = p_x_max;
            tmin = tmax_x;
        }
    }

    if(p_y_min.x <= max_.x && p_y_min.x >= min_.x && p_y_min.z <= max_.z && p_y_min.z >= min_.z){
        has_hit = true;
        if(tmin > tmin_y){
            hit_final.hit_point = p_y_min;
            tmin = tmin_y;
        }
    }

    if(p_y_max.x <= max_.x && p_y_max.x >= min_.x && p_y_max.z <= max_.z && p_y_max.z >= min_.z){
        has_hit = true;
        if(tmin > tmax_y){
            hit_final.hit_point = p_y_max;
            tmin = tmax_y;
        }
    }

    if(p_z_min.x <= max_.x && p_z_min.x >= min_.x && p_z_min.y <= max_.y && p_z_min.y >= min_.y){
        has_hit = true;
        if(tmin > tmin_z){
            hit_final.hit_point = p_z_min;
            tmin = tmin_z;
        }
    }

    if(p_z_max.x <= max_.x && p_z_max.x >= min_.x && p_z_max.y <= max_.y && p_z_max.y >= min_.y){
        has_hit = true;
        if(tmin > tmax_z){
            hit_final.hit_point = p_z_max;
            tmin = tmax_z;
        } 
    }

    if(has_hit == true){
        hit_final.hit_name = name_;
        hit_final.is_intersecting = true;
        hit_final.ray_direction = ray.direction;
        hit_final.distance = tmin;
    } 

    return hit_final;
}