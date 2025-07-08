#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "color.hpp"
#include "hitpoint.hpp"
#include "ray.hpp"
#include <string>

class Shape{
    public:
        virtual double area() const = 0;
        virtual double volume() const = 0;
        virtual std::ostream& print(std::ostream& os) const;
        virtual HitPoint intersect(Ray const& ray) = 0;
        Shape();
        Shape(std::string const& name, Color const& color);
        virtual ~Shape();
    protected:
        std::string name_;
        Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif