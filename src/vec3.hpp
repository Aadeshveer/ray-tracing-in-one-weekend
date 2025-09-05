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

#endif