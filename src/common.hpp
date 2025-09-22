#ifndef COMMON_HPP
#define COMMON_HPP

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// utility functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// common headers
#include "color.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include "interval.hpp"

#endif