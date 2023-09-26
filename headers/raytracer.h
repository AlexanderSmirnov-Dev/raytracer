#pragma once

#include "Eigen/Dense"
#include "ppmFileGen.h"
#include "sceneInfo.h"

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


void render(std::vector<std::vector<rgb>> pixelVec, scene_info sceneInfo);
