#ifndef BVH_H
#define BVH_H

#include "common.h"
#include "Hittable.h"
#include "hittable_list.h"

class bvh_node : public hittable {
public:
	bvh_node();

	bvh_node(const hittable_list& list, double t0, double t1) : 
		bvh_node(list.objects, 0, list.objects.size(), t0, t1) {}

	bvh_node(const std::vector<shared_ptr<hittable>>& src_objects, size_t start, size_t end, double t0, double t1);

	virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override;

	virtual bool bounding_box(double t0, double t1, aabb& output_box) const override;

	shared_ptr<hittable> left, right;
	aabb box;

};
#endif