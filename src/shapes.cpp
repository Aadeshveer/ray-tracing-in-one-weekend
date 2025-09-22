#include "shapes.hpp"

sphere::sphere(const point3& center, double radius) {
    this->center = center;
    this->radius = (radius>0 ? radius : 0);
}

bool sphere::hit(const ray& r, interval ray_t, hit_record& hit_rec) const {
    double a = dot(r.direction(), r.direction());
    double h = dot(r.direction(), center-r.origin());
    double c = (center-r.origin()).norm_squared() - radius*radius;
    double dis = h*h-a*c;

    if(dis < 0) {
        return false;
    }

    double sqrtd = std::sqrt(dis);

    // finding the closest solution in range
    double root = (h-sqrtd)/a;
    if(!ray_t.surrounds(root)) {
        root = (h+sqrtd)/a;
        if(!ray_t.surrounds(root)) {
            return false;
        }
    }

    // fill in the record of the hit
    hit_rec.p = r.at(root);
    hit_rec.t = root;
    hit_rec.set_face_normal(r, (hit_rec.p - center)/radius);

    return true;
}
