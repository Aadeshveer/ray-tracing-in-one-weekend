#include "common.hpp"
#include "visual_obj.hpp"
#include "visual_obj_list.hpp"
#include "shapes.hpp"
#include "camera.hpp"
#include "material.hpp"

int main() {
    // world
    visual_obj_list world;

    // materials
    auto material_ground = std::make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(std::make_shared<sphere>(point3( 0.0,  -1000, 0.0), 1000, material_ground));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).norm() > 0.9) {
                std::shared_ptr<material> sph_mat;

                if (choose_mat < 0.8) {
                    // diffuse
                    color albedo = color::random() * color::random();
                    sph_mat = std::make_shared<lambertian>(albedo);
                    world.add(std::make_shared<sphere>(center, 0.2, sph_mat));
                } else if (choose_mat < 0.95) {
                    // metal
                    color albedo = color::random(0.5, 1);
                    double fuzz = random_double(0, 0.5);
                    sph_mat = std::make_shared<metal>(albedo, fuzz);
                    world.add(std::make_shared<sphere>(center, 0.2, sph_mat));
                } else {
                    // glass
                    sph_mat = std::make_shared<dielectric>(1.5);
                    world.add(std::make_shared<sphere>(center, 0.2, sph_mat));
                }
            }
        }
    }

    auto material1 = std::make_shared<dielectric>(1.5);
    world.add(std::make_shared<sphere>(point3(0, 1, 0), 1.0, material1));
    
    auto material2 = std::make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(std::make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));
    
    auto material3 = std::make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1200;
    cam.samples_per_pixel = 500;
    cam.max_depth         = 50;

    cam.vfov     = 20;
    cam.origin = point3(13,2,3);
    cam.look_dir   = -cam.origin;
    cam.up_vec      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;
    
    cam.render(world);

}