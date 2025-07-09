#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

#include "material.hpp"

struct Scene{
    std::map<std::string, std::shared_ptr<Material>> mat_map;
};

Scene read_sdf(std::string const& file);

#endif