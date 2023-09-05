#include "raytracer.h"

Vector3d Ray::evalute(double t) {
    return ori + t * dir;
}
