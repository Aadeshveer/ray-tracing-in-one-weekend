#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

class ray {
    point3 orig;
    vec3 dir;
public:
    // constructors
    ray();
    ray(const point3 &, const vec3 &);

    // normal const getter functions
    const point3 &origin() const;
    const vec3 &direction() const;

    point3 at(double) const;
};

#endif