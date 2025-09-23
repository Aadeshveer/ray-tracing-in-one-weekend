#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "visual_obj_list.hpp"

class camera {
    int image_height;
    point3 camera_center;
    point3 pixel_00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;

    void initialize();
    color ray_color(const ray& r, const visual_obj& world) const;
public:
    double aspect_ratio = 1.0;
    int image_width = 100;

    void render(const visual_obj_list& world);
};

#endif