//
//  aabb.h
//  PRender
//
//  Created by Peter Sandquist on 10/21/20.
//

#ifndef aabb_h
#define aabb_h

class aabb{
public:
    aabb(){}
    aabb(const vec3& a, const vec3& b){ _min = a; _max = b; }
    
    bool hit(const ray& r, double tmin, double tmax) const{
        for (int a = 0; a < 3; a++) {
            auto invD = 1.0f / r.direction()[a];
            auto t0 = (min()[a] - r.origin()[a]) * invD;
            auto t1 = (max()[a] - r.origin()[a]) * invD;
            if (invD < 0.0f)
                std::swap(t0, t1);
            tmin = t0 > tmin ? t0 : tmin;
            tmax = t1 < tmax ? t1 : tmax;
            if (tmax <= tmin)
                return false;
        }
        return true;
    }
    
    vec3 _min, _max;
};

aabb surrounding_box(aabb box0, box1) {
    vec3 small(fmin(box0.min().x(), box1.min().x()),
        fmin(box0.min().y(), box1.min().y()),
        fmin(box0.min().z(), box1.min().z()));

    vec3 big(fmax(box0.max().x(), box1.max().x()),
        fmax(box0.max().y(), box1.max().y()),
        fmax(box0.max().z(), box1.max().z()));
    return aabb(small, big);
}

#endif /* aabb_h */
