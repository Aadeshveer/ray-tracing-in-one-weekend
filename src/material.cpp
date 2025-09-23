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