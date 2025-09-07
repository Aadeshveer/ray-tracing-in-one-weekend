#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>
#include <cmath>

class vec3 {
private:
    double V[3];
public:
    // constructors
    vec3();
    vec3(double, double, double);
    
    // getter functions
    double x() const;
    double y() const;
    double z() const;

    // operators
    vec3 operator- () const;
    double operator[] (int) const;
    double &operator[] (int);

    // in place vector operations
    vec3 &operator+= (const vec3&);

    // in place constant vector operations
    vec3 &operator*= (double);
    vec3 &operator/= (double);

    // util functions
    double norm() const;
    double norm_squared() const;

};

// point3 as an alias for vec3 for clarity
using point3 = vec3;


// More utility functions
// defined here as they are inline
inline std::ostream &operator<< (std::ostream& out, const vec3 u) {
    out << u.x() << ' ' << u.y() << ' ' << u.z() ;
    return out;
}

inline vec3 operator+ (const vec3& u, const vec3& v) {
    return vec3(
        u.x() + v.x(),
        u.y() + v.y(),
        u.z() + v.z()
    );
}
inline vec3 operator- (const vec3& u, const vec3& v) {
    return vec3(
        u.x() + v.x(),
        u.y() + v.y(),
        u.z() + v.z()
    );
}
inline vec3 operator* (const vec3& u, const vec3& v) {
    return vec3(
        u.x() * v.x(),
        u.y() * v.y(),
        u.z() * v.z()
    );
}
inline vec3 operator* (double t, const vec3& u) {
    return vec3(
        u.x() * t,
        u.y() * t,
        u.z() * t
    );
}
inline vec3 operator* (const vec3& u, double t) {
    return vec3(
        u.x() * t,
        u.y() * t,
        u.z() * t
    );
}
inline vec3 operator/ (const vec3& u, double t) {
    return vec3(
        u.x() / t,
        u.y() / t,
        u.z() / t
    );
}    
inline double dot (const vec3& u, const vec3& v) {
    return (u.x()*v.x() + u.y()*v.y() + u.z()*v.z());
}
inline vec3 cross (const vec3& u, const vec3& v) {
    return vec3(
        v.z()*u.y() - v.y()*u.z(),
        v.x()*u.z() - v.z()*u.x(),
        v.y()*u.x() - v.x()*u.y()
    );
}
inline vec3 unit_vector(const vec3& u) {
    return vec3(u/u.norm());
}
#endif