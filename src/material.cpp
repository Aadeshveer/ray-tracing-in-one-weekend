#include "material.hpp"

labertain::labertain(const color& albedo) {
    this->albedo = albedo;
}

bool labertain::scatter(
    const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
) const {
    vec3 scatter_dir = rec.normal + random_unit_vector();
    
    if(scatter_dir.near_zero()) {
        scatter_dir = rec.normal;
    }

    scattered = ray(rec.p, scatter_dir);
    attenuation = albedo;
    return true;
}

metal::metal(const color& albedo, double roughness) {
    this->albedo = albedo;
    this->roughtness = roughness;
}

bool metal::scatter(
    const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
) const {
    vec3 reflected = reflect(r_in.direction(), rec.normal);
    reflected = unit_vector(reflected) + roughtness*(random_unit_vector());
    scattered = ray(rec.p, reflected);
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}

dielectric::dielectric(double refractive_index) {
    this->refractive_index = refractive_index;
}

bool dielectric::scatter(
    const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
) const {
    attenuation = color(1.0, 1.0, 1.0);
    double ri = rec.front_face ? (1.0/refractive_index) : refractive_index;

    vec3 unit_direction = unit_vector(r_in.direction());
    double cos_theta = std::fmin(dot(-unit_direction, rec.normal), 1.0);
    double sin_theta = std::sqrt(1.0 - cos_theta*cos_theta);

    bool cannot_refract = (ri * sin_theta > 1.0);
    vec3 dir;

    if (cannot_refract || reflectance(cos_theta, ri) > random_double()) {
        dir = reflect(unit_direction, rec.normal);
    }
    else {
        dir = refract(unit_direction, rec.normal, ri);
    }

    scattered = ray(rec.p, dir);
    return true;
}

double dielectric::reflectance(double cosine, double refractive_idx) {
    // using Schlick's approximation
    double r0 = (1 - refractive_idx) / (1 + refractive_idx);
    r0 = r0*r0;
    return r0 + (1 - r0) * std::pow((1-cosine), 5);
}