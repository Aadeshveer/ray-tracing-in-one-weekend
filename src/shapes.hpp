#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "visual_obj.hpp"

class sphere : public visual_obj {
    point3 center;
    double radius;
    material* mat;
public:
    sphere(const point3& centeer, double radius, material* mat);
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
};

#endif