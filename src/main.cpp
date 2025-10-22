#include <iostream>

#include "camera/camera.hpp"
using namespace raytracing;
int main() {
    
    Vector3 camera_origin(0, 0, -20.0f);
    float aspect_ratio = 16.0f / 9.0f;
    float fov = 45.0f;
    float focus = 15.0f;
    unsigned int image_width = 1920;
    unsigned int image_height = 1080;
    Scene scene;
    raytracing::camera camera(camera_origin, aspect_ratio, fov, focus, image_width);
    camera.tracing(scene);
    camera.save_image("output.png");
    std::cout << "Hello, Ray tracing!" << std::endl;
    return 0;
}