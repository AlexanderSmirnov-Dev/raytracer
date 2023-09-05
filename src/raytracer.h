#pragma once

#include "../../libs/eigen/Eigen/Dense"

using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;

class Ray {
public:
    Vector3d ori;
    Vector3d dir;

    Vector3d evalute(double t);
};
