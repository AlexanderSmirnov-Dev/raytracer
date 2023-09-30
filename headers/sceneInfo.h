#pragma once

#include <cstdint>
#include "Eigen/Dense"

using vec2 = Eigen::Vector2d;
using vec3 = Eigen::Vector3d;
using rgb = Eigen::Vector3d;
using vec4 = Eigen::Vector4d;
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;
using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using i8 = int8_t;


class Ray {
public:
    vec3 ori;
    vec3 dir;

    vec3 eval(double t);
    rgb rayColour();
};


struct scene_info{
    u64 screenWidth;
    u64 screenHeight;
    vec3 cameraCentre;
    vec3 pixelUpperLeft;
    vec3 pixelDeltaHor;
    vec3 pixelDeltaVer;
};


void render(std::vector<std::vector<rgb>> pixelVec, scene_info sceneInfo);


double sphereCollision(const vec3& centre, double radius, const Ray& ray);


scene_info generateScene(u64 screenWidth, u64 screenHeight);
