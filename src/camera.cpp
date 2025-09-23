#include "camera.hpp"

color camera::ray_color(const ray& r, int depth, const visual_obj& world) const {
    if(depth <= 0) { // once given depth is exceeded the ray is absorbed
        return color(0,0,0);
    }
    hit_record rec;
    if(world.hit(r, interval(0.001, infinity), rec)) {
        ray scattered;
        color attenuation;
        if (rec.mat->scatter(r, rec, attenuation, scattered)) {
            return attenuation*ray_color(scattered, depth-1, world);
        }
        return color(0, 0, 0);
    }

    vec3 unit_dir = unit_vector(r.direction());
    // implementing lerp
    double a = 0.5*(unit_dir.y() + 1.0);
    return (1.0 - a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

void camera::initialize() {
    // image parmeters
    image_height = image_width/aspect_ratio;
    if(image_height < 1) image_height = 1;

    pixel_sample_scale = 1.0 / samples_per_pixel;

    camera_center = point3(0, 0, 0);
    
    // camera parameters
    double focal_length = 1;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (1.0*image_width) / image_height;

    // edge vectors
    vec3 viewport_u = vec3(viewport_width, 0, 0);
    vec3 viewport_v = vec3(0, -viewport_height, 0);

    // delta vectors
    pixel_delta_u = viewport_u/image_width;
    pixel_delta_v = viewport_v/image_height;

    // locating the origin of viewport i.e. upperleft
    vec3 viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    pixel_00_loc = viewport_upper_left + pixel_delta_u*0.5 + pixel_delta_v*0.5;
}

ray camera::get_ray(int i, int j) const {
    // Construct a camera ray originating from center to pixel at loc i,j
    vec3 offset         = sample_square();
    vec3 pixel_sample   = pixel_00_loc 
                        + ((i+offset.x())*pixel_delta_u)
                        + ((j+offset.y())*pixel_delta_v);
    vec3 ray_origin     = camera_center;
    vec3 ray_dir        = pixel_sample - ray_origin;

    return ray(ray_origin, ray_dir);
}

vec3 camera::sample_square() const {
    // returns vector to random point in [-0.5, 0.5]X[-0.5, 0.5] space
    return vec3(
        random_double() - 0.5,
        random_double() - 0.5,
        0
    );
}

void camera::render(const visual_obj_list& world) {
    initialize();
    // Rendering
    std::cout << "P3\n" << image_width << ' ' << image_height << '\n' << 255 << std::endl;
    for(int i=0 ; i<image_height; i++) {
        std::clog << "\rLines remaining: " << (image_height-i) << ' ' << std::flush;
        for(int j=0; j<image_width; j++) {
            color pixel_clr(0, 0, 0);
            for(int sample=0; sample<samples_per_pixel; sample++) {
                ray r = get_ray(j, i);
                pixel_clr += ray_color(r, max_depth, world);
            }
            write_color(std::cout, pixel_sample_scale * pixel_clr);
        }
    }
    std::clog << "\r         Done         \n" << std::endl;
}