//
// Created by John on 2025/10/16.
//

#ifndef RTPRACTICE_RTWEEKEND_H
#define RTPRACTICE_RTWEEKEND_H

#include<cmath>
#include<iostream>
#include<limits>
#include<memory>

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees){
    return degrees * pi / 180.0;
}

#endif //RTPRACTICE_RTWEEKEND_H
