#pragma once

#include <cstdint>
#include "Eigen/Dense"

using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;

struct scene_info{
    uint64_t screenWidth;
    uint64_t screenHeight;
    Vector3d cameraCentre;
    Vector3d pixelUpperLeft;
    Vector3d pixelDeltaHor;
    Vector3d pixelDeltaVer;
};

scene_info generateScene(uint64_t screenWidth, uint64_t screenHeight);
