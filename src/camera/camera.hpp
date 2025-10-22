#pragma once
#if defined(_MSC_VER)
#define NOMINMAX
#endif

#ifndef camera_camera_h
#define camera_camera_h
#include "geometry/vector3.hpp"
#include "scene/scene.hpp"
#include <vector>
#include <filesystem>
#include <string>
namespace raytracing
{
class camera
{
public:
    camera(Vector3 origin, double aspect_ratio, double fov, double focus, unsigned int pixel_width);
    ~camera();
    void tracing(const Scene& scene);
    void save_image(const std::string& path);
    Vector3 origin;
    double focus;
    double aspect_ratio;
    /**
     * @brief Vertical Field of view in degrees
     */
    double fov;
    unsigned int pixel_width;
    unsigned int pixel_height;
    double width_world;
    double height_world;
    std::vector<unsigned char> framebuffer;
};
}






#endif // camera_camera_h