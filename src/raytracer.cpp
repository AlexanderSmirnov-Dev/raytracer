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
    Vector3d unitDir{dir / dir.norm()};
    double a{0.5 * unitDir.y() + 1.0};
    double b{1.0 - a};
    return rgb(1.0 * b + 0.5 * a, 1.0 * b + 0.7 * a, 1.0 * b + 1.0 * a);
}
