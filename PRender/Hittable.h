//
//  Hittable.h
//  PRender
//
//  Created by Peter Sandquist on 9/29/20.
//

#ifndef Hittable_h
#define Hittable_h

#include "aabb.h"
#include "common.h"
#include <memory>

class material;

class hit_record{
public:
    vec3 p;
    vec3 normal;
    shared_ptr<material> mat;
    double t;
    bool front_face;
    
    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
        virtual bool bounding_box(double t0, double t1, aabb& output_box) const = 0;
};

#endif /* Hittable_h */
