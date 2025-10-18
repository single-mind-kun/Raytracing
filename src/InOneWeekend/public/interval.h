//
// Created by John on 2025/10/17.
//

#ifndef RTPRACTICE_INTERVAL_H
#define RTPRACTICE_INTERVAL_H

#include<cmath>

const double default_infinity = std::numeric_limits<double>::infinity();

class interval{
public:
    double min, max;

    interval() : min(+default_infinity), max(-default_infinity){}
    interval(double min, double max) : min(min), max(max){}

    double size() const{
        return max - min;
    }

    bool contains(double x) const{
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }

    static const interval empty, universe;
};

const interval interval::empty = interval(+default_infinity, -default_infinity);
const interval interval::universe = interval(-default_infinity, +default_infinity);


#endif //RTPRACTICE_INTERVAL_H
