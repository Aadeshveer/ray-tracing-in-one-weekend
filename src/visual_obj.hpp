#ifndef VISUAL_OBJ_HPP
#define VISUAL_OBJ_HPP

#include "common.hpp"

struct hit_record {
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    void set_face_normal(const ray &r, const vec3 &outward_normal);
};


class visual_obj {
public:
    virtual ~visual_obj() = default;
    virtual bool hit(const ray& r, interval ray_t, hit_record& hit_rec) const = 0;
};

#endif