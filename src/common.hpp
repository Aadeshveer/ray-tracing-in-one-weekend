#ifndef COMMON_HPP
#define COMMON_HPP

#include <cmath>
#include <random>
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

inline double random_double() {
    // return random real in [0, 1)
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    // return a random real in [min, max)
    return min + (max-min)*random_double();
}

// common headers
#include "color.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include "interval.hpp"

#endif