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
    material* material_ground   = new labertain(color(0.8, 0.8, 0.0));
    material* material_center   = new labertain(color(0.1, 0.2, 0.5));
    material* material_left     = new metal(color(0.8, 0.8, 0.8), 0.3);
    material* material_right    = new metal(color(0.8, 0.6, 0.2), 0.1);

    sphere* s1 = new sphere(point3( 0.0, -100.5, -1.0), 100.0, material_ground);
    sphere* s2 = new sphere(point3( 0.0,    0.0, -1.2), 0.5, material_center);
    sphere* s3 = new sphere(point3(-1.0,    0.0, -1.2), 0.5, material_left);
    sphere* s4 = new sphere(point3( 1.0,    0.0, -1.2), 0.5, material_right);
    world.add(s1);
    world.add(s2);
    world.add(s3);
    world.add(s4);
    // world shapes are deleted by destructor of worlds
    
    camera cam;
    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.render(world);

    delete material_center;
    delete material_ground;
    delete material_left;
    delete material_right;
}