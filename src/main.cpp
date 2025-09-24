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
    lambertian material_ground = lambertian(color(0.5, 0.5, 0.5));
    sphere* s0 = new sphere(point3( 0.0,  -1000, 0.0), 1000, &material_ground);
    world.add(s0);

    std::vector<material*> materials;
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).norm() > 0.9) {
                sphere* s;

                if (choose_mat < 0.8) {
                    // diffuse
                    color albedo = color::random() * color::random();
                    materials.push_back(new lambertian(albedo));
                    s = new sphere(center, 0.2, materials.back());
                    world.add(s);
                } else if (choose_mat < 0.95) {
                    // metal
                    color albedo = color::random(0.5, 1);
                    double fuzz = random_double(0, 0.5);
                    materials.push_back(new metal(albedo, fuzz));
                    s = new sphere(center, 0.2, materials.back());
                    world.add(s);
                } else {
                    // glass
                    materials.push_back(new dielectric(1.5));
                    s = new sphere(center, 0.2, materials.back());
                    world.add(s);
                }
            }
        }
    }

    auto material1 = dielectric(1.5);
    sphere* s1 = new sphere(point3(0, 1, 0), 1.0, &material1);
    
    auto material2 = lambertian(color(0.4, 0.2, 0.1));
    sphere* s2 = new sphere(point3(-4, 1, 0), 1.0, &material2);
    
    auto material3 = metal(color(0.7, 0.6, 0.5), 0.0);
    sphere* s3 = new sphere(point3(4, 1, 0), 1.0, &material3);

    world.add(s1); world.add(s2); world.add(s3);

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

    for(material* m:materials) {
        delete m;
    }
}