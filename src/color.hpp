#ifndef COLOR_HPP
#define COLOR_HPP

#include "vec3.hpp"

using color = vec3;

inline double linear_to_gamma(double linear_component);

void write_color(std::ostream& out, const color& pixel_color);

#endif