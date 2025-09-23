#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "visual_obj.hpp"

class material {
public:
    virtual ~material() = default;
    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scatterd
    ) const {
        return false;
    }
};

class labertain : public material {
    color albedo;
public:
    labertain(const color& albedo);
    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override;
};

class metal : public material {
    color albedo;
    double roughtness;
public:
    metal(const color& albedo, double roughness);
    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override;
};

#endif