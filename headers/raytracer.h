#pragma once

#include "Eigen/Dense"
#include "ppmFileGen.h"
#include "sceneInfo.h"
#include "rand.h"

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


void render(std::vector<std::vector<rgb>> pixelVec, const scene_info& sceneInfo);
double sphereCollision(const vec3& centre, double radius, const Ray& ray);
Ray getRay(u64 i, u64 j, const scene_info& sceneInfo);
vec3 pixelSampleSquare(const scene_info& sceneInfo);
