//
// Created by John on 2025/10/16.
//

#ifndef RTPRACTICE_SPHERE_H
#define RTPRACTICE_SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable{
public:
    sphere(){}
    sphere(vec3 cen, double r) : center(cen), radius(r){}
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
    ~sphere(){}
private:
    point3 center;
    double radius;
};

bool sphere::hit(const ray &r, interval ray_t, hit_record &rec) const {
    vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius * radius;
    double discriminant = half_b * half_b - a * c;

    if(discriminant < 0.0f){
        return false;
    }

    double sqrtd = std::sqrt(discriminant);
    double t = (-half_b - sqrtd) / a;

    if(!ray_t.surrounds(t)){
        t = (-half_b + sqrtd) / a;
        if(!ray_t.surrounds(t)){
            return false;
        }
    }

    rec.t = t;
    rec.p = r.at(t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    return true;
}

#endif //RTPRACTICE_SPHERE_H
