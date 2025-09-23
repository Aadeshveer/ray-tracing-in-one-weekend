#include "common.hpp"
#include "visual_obj.hpp"
#include "visual_obj_list.hpp"
#include "shapes.hpp"
#include "camera.hpp"

int main() {
    // world
    visual_obj_list world;
    sphere* s1 = new sphere(point3(0,0,-1), 0.5);
    world.add(s1);
    sphere* s2 = new sphere(point3(0,-100.5,-1), 100);
    world.add(s2);
    
    camera cam;
    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;

    cam.render(world);
}