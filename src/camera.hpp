#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "visual_obj_list.hpp"

class camera {
    int image_height;
    double pixel_sample_scale;
    point3 camera_center;
    point3 pixel_00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;

    void initialize();
    ray get_ray(int i, int j) const;
    vec3 sample_square() const;
    color ray_color(const ray& r, int depth, const visual_obj& world) const;
public:
    double  aspect_ratio        = 1.0;
    int     image_width         = 100;
    int     samples_per_pixel   = 10;
    int     max_depth           = 10;
    void render(const visual_obj_list& world);
};

#endif