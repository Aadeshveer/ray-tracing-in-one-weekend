#include "color.hpp"
#include "interval.hpp"

inline double linear_to_gamma(double linear_component) {
    if(linear_component > 0) {
        return std::sqrt(linear_component);
    }
    return 0;
}

void write_color(std::ostream& out, const color& pixel_color) {
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();
    
    // converting to gamma form
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);
    
    // Translate the [0,1] components to [0,255] for color mapping
    static const interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << std::endl;
}