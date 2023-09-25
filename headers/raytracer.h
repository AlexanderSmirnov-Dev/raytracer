#pragma once

#include "Eigen/Dense"
#include "ppmFileGen.h"

using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;

class Ray {
public:
    Vector3d ori;
    Vector3d dir;

    Vector3d eval(double t);
    rgb rayColour();
};

struct screen_info{
    uint64_t screenWidth;
    uint64_t screenHeight;
    Vector3d cameraCentre;
    Vector3d pixelUpperLeft;
    Vector3d pixelDeltaHor;
    Vector3d pixelDeltaVer;
};

void render(std::vector<std::vector<rgb>> pixelVec, screen_info screenInfo);
