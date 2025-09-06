#include "vec3.hpp"
#include "color.hpp"

int main() {

    int image_width = 512;
    int image_height = 512;

    std::cout << "P3\n" << image_width << ' ' << image_height << '\n' << 255 << std::endl;
    for(int i=0 ; i<image_height; i++) {
        std::clog << "\rLines remaining: " << (image_height-i) << ' ' << std::flush;
        for(int j=0; j<image_width; j++) {
            color pixel_clr = color(1.0*i/(image_height-1), 1.0*j/(image_width-1), 0.0);
            write_color(std::cout, pixel_clr);
        }
    }
    std::clog << "\r         Done         \n" << std::endl;
}