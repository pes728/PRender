#ifndef Sphere_h
#define Sphere_h

#include "common.h"

#include "Hittable.h"


class sphere : public hittable {
public:
    sphere() {}

    sphere(vec3 cen, double r, shared_ptr<material> m) : center(cen), radius(r), mat(m) {};

    virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override;

    virtual bool bounding_box(double t0, double t1, aabb& output_box) const override;

public:
    vec3 center;
    double radius;
    shared_ptr<material> mat;
};





#endif /* Sphere_h */
