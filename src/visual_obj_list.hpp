#ifndef VISUAL_OBJ_LIST
#define VISUAL_OBJ_LIST

#include "visual_obj.hpp"

#include <vector>

class visual_obj_list : public visual_obj {
public:
    std::vector<std::shared_ptr<visual_obj>> objects;

    visual_obj_list();
    visual_obj_list(std::shared_ptr<visual_obj>);
    ~visual_obj_list();

    void clear();
    void add(std::shared_ptr<visual_obj>);

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override;
};

#endif