#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "visual_obj.hpp"

class sphere : public visual_obj {
    point3 center;
    double radius;
public:
    sphere(const point3&, double);
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
};

#endif