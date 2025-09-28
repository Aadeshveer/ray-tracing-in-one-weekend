#include "visual_obj_list.hpp"

visual_obj_list::visual_obj_list() {}
visual_obj_list::visual_obj_list(std::shared_ptr<visual_obj> obj) {
    this->add(obj);
}
visual_obj_list::~visual_obj_list() {
    this->clear();
}

void visual_obj_list::clear() {
    objects.clear();
}

void visual_obj_list::add(std::shared_ptr<visual_obj> ptr) {
    objects.push_back(ptr);
}

bool visual_obj_list::hit(const ray &r, interval ray_t, hit_record &rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    double closest = ray_t.max;

    for (const auto &object: objects) {
        if(object->hit(r, interval(ray_t.min, closest), temp_rec)) {
            hit_anything = true;
            if(closest > temp_rec.t){
                closest = temp_rec.t;
                rec = temp_rec;
            }
        }
    }

    return hit_anything;
}