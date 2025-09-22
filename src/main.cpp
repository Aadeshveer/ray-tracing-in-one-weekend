#include "common.hpp"
#include "visual_obj.hpp"
#include "visual_obj_list.hpp"
#include "shapes.hpp"

color ray_color(const ray &r, const visual_obj_list &world) {
    hit_record rec;
    if(world.hit(r, interval(0, infinity), rec)) {
        return 0.5*(rec.normal + color(1,1,1));
    }

    vec3 unit_dir = unit_vector(r.direction());
    // implementing lerp
    double a = 0.5*(unit_dir.y() + 1.0);
    return (1.0 - a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}


int main() {
    // image parmeters
    double aspect_ratio = 16.0/9.0;
    int image_width = 400;
    int image_height = image_width/aspect_ratio;
    if(image_height < 1) image_height = 1;
    
    // world
    visual_obj_list world;
    sphere* s1 = new sphere(point3(0,0,-1), 0.5);
    world.add(s1);
    sphere* s2 = new sphere(point3(0,-100.5,-1), 100);
    world.add(s2);

    // camera parameters
    double focal_length = 1;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (1.0*image_width) / image_height;
    point3 camera_center = point3(0, 0, 0);

    // edge vectors
    vec3 viewport_u = vec3(viewport_width, 0, 0);
    vec3 viewport_v = vec3(0, -viewport_height, 0);

    // delta vectors
    vec3 pixel_delta_u = viewport_u/image_width;
    vec3 pixel_delta_v = viewport_v/image_height;

    // locating the origin of viewport i.e. upperleft
    vec3 viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    vec3 pixel_00_loc = viewport_upper_left + pixel_delta_u*0.5 + pixel_delta_v*0.5;

    // Rendering
    std::cout << "P3\n" << image_width << ' ' << image_height << '\n' << 255 << std::endl;
    for(int i=0 ; i<image_height; i++) {
        std::clog << "\rLines remaining: " << (image_height-i) << ' ' << std::flush;
        for(int j=0; j<image_width; j++) {
            vec3 pixel_center = pixel_00_loc + pixel_delta_u*j + pixel_delta_v*i;
            vec3 ray_dir = pixel_center - camera_center;
            ray r(camera_center, ray_dir);

            color pixel_clr = ray_color(r, world);
            write_color(std::cout, pixel_clr);
        }
    }
    std::clog << "\r         Done         \n" << std::endl;
}