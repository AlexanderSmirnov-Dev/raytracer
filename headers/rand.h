#pragma once

#include "Eigen/Dense"

#include <random>

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

inline double randDouble(double min = 0.0, double max = 1.0) {
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}


inline void vec3Rand(vec3& vec, double min = 0.0, double max = 1.0) {
    vec.x() = randDouble(min, max);
    vec.y() = randDouble(min, max);
    vec.z() = randDouble(min, max);
}


inline vec3 randVecInUnitSphere() {
    vec3 randVec{};
    while (true) {
        vec3Rand(randVec, -1, 1);
        if (std::pow(randVec.norm(), 2) < 1)
            return randVec;
    }
}


inline vec3 randUnitVec() {
    vec3 vec{};
    vec = randVecInUnitSphere();
    return (vec / vec.norm());
}


inline vec3 randVecHemisphere(const vec3& normal) {
    vec3 vecOnUnitSphere{randUnitVec()};
    if (vecOnUnitSphere.dot(normal) > 0.0)
        return vecOnUnitSphere;
    else
        return -vecOnUnitSphere;
}
