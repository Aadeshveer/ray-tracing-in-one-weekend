#include <iostream>
#include <cmath>

int main() {

    int image_width = 1024;
    int image_height = 512;

    std::cout << "P3\n" << image_width << ' ' << image_height << '\n' << 255 << std::endl;
    for(int i=0 ; i<image_height; i++) {
        std::clog << "\rLines remaining: " << (image_height-i) << ' ' << std::flush;
        for(int j=0; j<image_width; j++) {
            auto r=1.0*j/(image_width-1);
            auto b=1.0*i/(image_height-1);
            auto g=0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            
            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
        }
    }
    std::clog << "   Done   \n" << std::endl;
}