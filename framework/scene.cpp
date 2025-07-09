#include "scene.hpp"

Scene read_sdf(std::string const& file){
    std::ifstream read_file;
    read_file.open(file);
    
    std::string line_buffer;
    std::string identifier;
    std::string class_name;
    
    Scene scene;
    
    while(std::getline(read_file, line_buffer)){
         std::istringstream in_sstream(line_buffer);
         in_sstream >> identifier;
         if("define" == identifier){
            in_sstream >> class_name;
            if("material" == class_name){

                std::string material_name;
                float ka_r, ka_g, ka_b;
                float kd_r, kd_g, kd_b;
                float ks_r, ks_g, ks_b;
                float m;

                in_sstream >> material_name;
                in_sstream >> ka_r >> ka_g >> ka_b; 
                in_sstream >> kd_r >> kd_g >> kd_b;
                in_sstream >> ks_r >> ks_g >> ks_b;
                in_sstream >> m;

                Material mat{material_name,{ka_r,ka_g,ka_b},{kd_r,kd_g,kd_b},{ks_r,ks_g,ks_b},m};
                auto mat_ptr = std::make_shared<Material>(mat);
                scene.mat_map.insert({material_name, mat_ptr}); 
            }
         } 
    }
    return scene;
}