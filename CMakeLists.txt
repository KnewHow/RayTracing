cmake_minimum_required(VERSION 3.20)
project(RayTracing)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(SOURCES "${SRC_DIR}/main.cpp")
file(GLOB SOURCES
    "${SRC_DIR}/*.hpp"
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/geometry/*.hpp"
    "${SRC_DIR}/geometry/*.cpp"
    "${SRC_DIR}/camera/*.hpp"
    "${SRC_DIR}/camera/*.cpp"
    "${SRC_DIR}/scene/*.hpp"
    "${SRC_DIR}/scene/*.cpp"
    "${LIB_DIR}/stb/*.h"
    # "${SRC_DIR}/common/*.cpp"
    # "${SRC_DIR}/accelerator/*.hpp"
    # "${SRC_DIR}/accelerator/*.cpp"
)
INCLUDE_DIRECTORIES ( "${SRC_DIR}" )
INCLUDE_DIRECTORIES ( "${LIB_DIR}" )
# INCLUDE_DIRECTORIES ( SRC_DIR )
add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME}  PRIVATE cxx_std_20)