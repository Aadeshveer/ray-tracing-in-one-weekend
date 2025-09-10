#ifndef VISUAL_OBJ_LIST
#define VISUAL_OBJ_LIST

#include "visual_obj.hpp"

#include <vector>

class visual_obj_list : public visual_obj {
public:
    std::vector<visual_obj*> objects;

    visual_obj_list();
    visual_obj_list(visual_obj*);
    ~visual_obj_list();

    void clear();
    void add(visual_obj*);

    bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const override;
};

#endif