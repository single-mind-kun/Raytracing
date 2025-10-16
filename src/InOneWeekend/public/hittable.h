//
// Created by John on 2025/10/16.
//

#ifndef RTPRACTICE_HITTABLE_H
#define RTPRACTICE_HITTABLE_H

#include "ray.h"

struct hit_record{
    vec3 p;
    vec3 normal;
    double t;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal){
        //Sets the hit record normal vector.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable{
public:
    virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const = 0;
    virtual ~hittable(){}
};

#endif //RTPRACTICE_HITTABLE_H
