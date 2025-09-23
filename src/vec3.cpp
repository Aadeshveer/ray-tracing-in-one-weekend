#include "vec3.hpp"
#include "common.hpp"

// constructors
vec3::vec3() {
    V[0] = 0;
    V[1] = 0;
    V[2] = 0;
}
vec3::vec3(double x, double y, double z) {
    V[0] = x;
    V[1] = y;
    V[2] = z;
}

// getter functions
double vec3::x() const {
    return V[0];
}
double vec3::y() const {
    return V[1];
}
double vec3::z() const {
    return V[2];
}

// operators
vec3 vec3::operator- () const {
    return vec3(-V[0], -V[1], -V[2]);
}
double vec3::operator[] (int i) const {
    return V[i];
}
double &vec3::operator[] (int i) {
    return V[i];
}

// in place vector operations
vec3 &vec3::operator+= (const vec3& u) {
    V[0] += u.x();
    V[1] += u.y();
    V[2] += u.z();
    return *this;
}

// in place constant vector operations
vec3 &vec3::operator*= (double t) {
    V[0] *= t;
    V[1] *= t;
    V[2] *= t;
    return *this;
}
vec3 &vec3::operator/= (double t) {
    V[0] /= t;
    V[1] /= t;
    V[2] /= t;
    return *this;
}

// util functions
double vec3::norm() const {
    return sqrt(norm_squared());
}
double vec3::norm_squared() const {
    return V[0]*V[0] + V[1]*V[1] + V[2]*V[2];
}
vec3 vec3::random() {
    return vec3(
        random_double(),
        random_double(),
        random_double()
    );
}
vec3 vec3::random(vec3 min, vec3 max) {
    return vec3(
        random_double(min[0], max[0]),
        random_double(min[1], max[1]),
        random_double(min[2], max[2])
    );
}
vec3 vec3::random(double min, double max) {
    return random(
        vec3(min, min, min),
        vec3(max, max, max)
    );
}