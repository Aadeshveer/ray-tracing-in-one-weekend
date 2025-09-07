#include "vec3.hpp"
#include "ray.hpp"
#include "color.hpp"

double hit_sphere(const vec3 &center, double radius, const ray& r) {
    double a = dot(r.direction(), r.direction());
    double b = 2*dot(r.direction(), r.origin()-center);
    double c = (center-r.origin()).norm() - radius*radius;
    double det = b*b-4*a*c;
    if(det >=0 ) {
        return (-b-sqrt(det))/(2*a);
    }
    else {
        return -1.0;
    }
}

color ray_color(const ray &r) {
    vec3 unit_dir = unit_vector(r.direction());
    vec3 center = vec3(0,0,-1);
    double hit = hit_sphere(center, 0.5, r);
    if(hit >= 0) {
        vec3 N = unit_vector(r.at(hit)-center);
        return 0.5*color(N.x() + 1, N.y() + 1, N.z() + 1);
    }
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

            color pixel_clr = ray_color(r);
            write_color(std::cout, pixel_clr);
        }
    }
    std::clog << "\r         Done         \n" << std::endl;
}