#ifndef COLOR_HPP
#define COLOR_HPP

#include "vec3.hpp"
#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color);

#endif