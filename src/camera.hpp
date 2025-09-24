#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "visual_obj_list.hpp"
#include "material.hpp"

class camera {
    int     image_height;
    double  pixel_sample_scale;
    point3  camera_center;
    point3  pixel_00_loc;
    vec3    pixel_delta_u;
    vec3    pixel_delta_v;
    vec3    u, v, w;
    vec3    defocus_disk_u;
    vec3    defocus_disk_v;

    void initialize();
    ray get_ray(int i, int j) const;
    vec3 sample_square() const;
    color ray_color(const ray& r, int depth, const visual_obj& world) const;
    point3 defocus_disk_sample() const;
public:
    double  aspect_ratio        = 1.0;
    int     image_width         = 100;
    int     samples_per_pixel   = 10;
    int     max_depth           = 10;

    double  vfov                = 90;               // field of view(vertical)
    point3  origin              = point3(0, 0, 0);  // point camera is looking from
    vec3    look_dir            = vec3(0, 0, 1);    // direction camera is looking in
    vec3    up_vec              = vec3(0, 1, 0);    // camera's relative up

    double defocus_angle = 0;
    double focus_dist = 10;

    void render(const visual_obj_list& world);
};

#endif