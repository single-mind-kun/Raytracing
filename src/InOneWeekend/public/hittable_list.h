//
// Created by John on 2025/10/16.
//

#ifndef RTPRACTICE_HITTABLE_LIST_H
#define RTPRACTICE_HITTABLE_LIST_H

#include "hittable.h"
#include<memory>
#include<vector>

class hittable_list : public hittable{
public:
    hittable_list(){}
    hittable_list(std::shared_ptr<hittable> object){add(object);}
    ~hittable_list(){}
    void clear(){objects.clear();}

    void add(std::shared_ptr<hittable> object){
        objects.push_back(object);
    }

    bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override{
        hit_record temp_rec;
        bool hit_anything = false;
        double closest_so_far = tmax;

        for(const auto& object : objects){
            if(object->hit(r, tmin, closest_so_far, temp_rec)){
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }
        return hit_anything;
    }

public:
    std::vector<std::shared_ptr<hittable>> objects;
};

#endif //RTPRACTICE_HITTABLE_LIST_H
