//
// Created by John on 2025/10/17.
//

#ifndef RTPRACTICE_CAMERA_H
#define RTPRACTICE_CAMERA_H

#include "hittable.h"

class camera{
public:

    void render(const hittable& world){
        Initialize();

        std::cout<< "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for(int j = 0; j < image_height; j++){
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for(int i = 0; i < image_width; i++){
                vec3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
                vec3 raydirection = pixel_center - center;
                ray r(center, raydirection);
                color pixel_color = ray_color(r, world);
                write_color(std::cout, pixel_color);
            }
        }
        std::clog << "\rDone.               \n";
    }

    double aspect_ratio = 1.0;
    int image_width = 100;
private:
    int image_height;
    point3 center;
    point3 pixel00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;

    void Initialize(){
        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;
        center = point3(0, 0, 0);

        double focal_lenght = 1.0f;
        double viewport_height = 2.0f;
        double viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);

        vec3 viewport_u = vec3(viewport_width, 0, 0);
        vec3 viewport_v = vec3(0, -viewport_height, 0);

        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        vec3 viewport_upper_left = center - vec3(0, 0, focal_lenght) - viewport_u / 2 - viewport_v / 2;
        vec3 pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }
    color ray_color(const ray& r, const hittable& world) const{
        hit_record rec;
        if(world.hit(r, interval(0, infinity), rec)){
            return 0.5 * (rec.normal + color(1, 1, 1));
        }
        vec3 unit_direction = unit_vector(r.direction());
        double alpha = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - alpha) * color(1.0f, 1.0f, 1.0f) + alpha * color(0.5f, 0.7f, 1.0f);
    }

};


#endif //RTPRACTICE_CAMERA_H
