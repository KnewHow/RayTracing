#include "camera.hpp"
#include <numbers>
#include <fstream>
#include "rt.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include <omp.h>
#include <thread>
#include <chrono>
namespace raytracing {
camera::camera(Vector3 origin, double aspect_ratio, double fov, double focus, unsigned int width)
    : origin(origin), aspect_ratio(aspect_ratio), fov(fov), focus(focus), pixel_width(width)
{
    double pi = std::numbers::pi;
    pixel_height = static_cast<unsigned int>(width / aspect_ratio);
    height_world = 2.0 * focus * tan((fov * 0.5) * (pi / 180.0));
    width_world = aspect_ratio * height_world;
    framebuffer.resize(pixel_width * pixel_height * 4); // Assuming 4 bytes per pixel (RGBA)
}

void camera::tracing(const Scene& scene)
{
    

    // 获取硬件支持的线程数（默认4个）
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 4;

    std::vector<std::thread> threads;
    unsigned int rows_per_thread = pixel_height / num_threads;
    unsigned int remaining_rows = pixel_height % num_threads;

    for (unsigned int t = 0; t < num_threads; ++t) {
        // 计算当前线程处理的行范围
        unsigned int start_row = t * rows_per_thread;
        unsigned int end_row = start_row + rows_per_thread;
        if (t == num_threads - 1) end_row += remaining_rows; // 最后一个线程处理剩余行

        // 创建线程，捕获局部变量（按值避免竞争）
        threads.emplace_back([&, start_row, end_row]() {
            for (unsigned int j = start_row; j < end_row; ++j) {
                for (unsigned int i = 0; i < pixel_width; ++i) {
                    double x = (i + 0.5) * width_world / pixel_width - width_world / 2.0;
                    double y = (j + 0.5) * height_world / pixel_height - height_world / 2.0;
                    double z = origin.z + focus;
                    Vector3 pixel_position(x, y, z);
                    unsigned int index = (j * pixel_width + i) * 4;

                    framebuffer[index + 0] = 255; // R
                    framebuffer[index + 1] = 0;   // G
                    framebuffer[index + 2] = 0;   // B
                    framebuffer[index + 3] = 255; // A
                    for(int k = 0; k < 1000; ++k) {} // 模拟计算工作
                }
            }
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void camera::save_image(const std::string& path)
{
    int result = stbi_write_png(path.c_str(), pixel_width, pixel_height, 4,framebuffer.data(), 4);
}




camera::~camera()
{

}
}
