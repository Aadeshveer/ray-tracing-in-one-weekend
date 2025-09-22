#include "visual_obj_list.hpp"

visual_obj_list::visual_obj_list() {}
visual_obj_list::visual_obj_list(visual_obj* obj) {
    this->add(obj);
}
visual_obj_list::~visual_obj_list() {
    this->clear();
}

void visual_obj_list::clear() {
    for(auto &ptr: objects) {
        if(ptr){
            delete ptr;
            ptr = nullptr;
        }
    }
    objects.clear();
}

void visual_obj_list::add(visual_obj* ptr) {
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