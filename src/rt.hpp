#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef rt_h
#define rt_h
#include <chrono>
#include <cstdint>


uint64_t get_current_timestamp_ms() {
    auto now = std::chrono::system_clock::now();
    auto duration_since_epoch = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch).count();
}

#endif
