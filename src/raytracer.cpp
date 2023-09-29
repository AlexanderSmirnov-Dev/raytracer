#include "raytracer.h"
#include "sceneInfo.h"

void render(std::vector<std::vector<rgb>> pixelVec, scene_info sceneInfo) {
    Vector3d pixelCentre{};
    Vector3d rayDirection{};
    rgb pixelColour{};
    for (int j{}; j < sceneInfo.screenHeight; ++j) {
        for (int i{}; i < sceneInfo.screenWidth; ++i) {
            //vec.emplace_back(rgb {j / static_cast<double>(sceneInfo.screenWidth), 0, 0});
            pixelCentre = sceneInfo.pixelUpperLeft + (i * sceneInfo.pixelDeltaHor) + (j * sceneInfo.pixelDeltaVer);
            rayDirection = pixelCentre - sceneInfo.cameraCentre;
            Ray r{sceneInfo.cameraCentre, rayDirection};

            pixelColour = r.rayColour();
            pixelVec.at(j).at(i) = pixelColour;
        }
    }

    rgbToStandardOutput(pixelVec);
}


Vector3d Ray::eval(double t) {
    return ori + t * dir;
}

rgb Ray::rayColour() {
    double t{sphereCollision(Vector3d(0, 0, -1), 0.5, *this)};
    Vector3d preN{this->eval(t) - Vector3d{0, 0, -1}};

    if (t > 0.0) {
        Vector3d N{preN / preN.norm()};
        return rgb{0.5 * (N.x() + 1), 0.5 * (N.y() + 1), 0.5 * (N.z() + 1)};
    }

    Vector3d unitDir{dir / dir.norm()};
    double a{0.5 * unitDir.y() + 1.0};
    double b{1.0 - a};
    return rgb(1.0 * b + 0.5 * a, 1.0 * b + 0.7 * a, 1.0 * b + 1.0 * a);
}


double sphereCollision(const Vector3d& centre, double radius, const Ray& ray) {
    Vector3d oc{ray.ori - centre};
    double a{std::pow(ray.dir.norm(), 2)};
    double halfB{oc.dot(ray.dir)};
    double c{std::pow(oc.norm(), 2) - radius * radius};
    double discriminant{halfB*halfB - a*c};

    if (discriminant < 0) 
        return -1.0;
    else 
        return (-halfB - sqrt(discriminant)) / a;
}
