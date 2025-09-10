#include "visual_obj.hpp"

void hit_record::set_face_normal(const ray &r, const vec3 &outward_normal) {
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = (front_face ? 1:-1) * outward_normal;
}