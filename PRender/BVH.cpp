#include "BVH.h"

bool bvh_node::bounding_box(double t0, double t1, aabb& output_box) const{
    output_box = box;
    return true;
}

bool bvh_node::hit(const ray& r, double tmin, double tmax, hit_record& rec) const {
    if(!box.hit(r, tmin, tmax)) return false;

    bool hit_left = left->hit(r, tmin, tmax, rec);
    bool hit_right = right->hit(r, tmin, hit_left ? rec.t : tmax, rec);

    return hit_left || hit_right;
}

