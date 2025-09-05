#include "vec3.hpp"

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

// More utility functions
inline std::ostream &operator<< (std::ostream&, const vec3);
inline vec3 operator+ (const vec3&, const vec3&);
inline vec3 operator- (const vec3&, const vec3&);
inline vec3 operator* (const vec3&, const vec3&);
inline vec3 operator* (double, const vec3&);
inline vec3 operator* (const vec3&, double);
inline vec3 operator/ (const vec3&, double);
inline double dot (const vec3&, const vec3&);
inline vec3 cross (const vec3&, const vec3&);
inline vec3 unit_vector(const vec3&);