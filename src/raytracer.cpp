#include "raytracer.h"

void render(std::vector<std::vector<rgb>> pixelVec, screen_info screenInfo) {
    Vector3d pixelCentre{};
    Vector3d rayDirection{};
    rgb pixelColour{};
    for (int j{}; j < screenInfo.screenHeight; ++j) {
        for (int i{}; i < screenInfo.screenWidth; ++i) {
            //vec.emplace_back(rgb {j / static_cast<double>(screenInfo.screenWidth), 0, 0});
            pixelCentre = screenInfo.pixelUpperLeft + (i * screenInfo.pixelDeltaHor) + (j * screenInfo.pixelDeltaVer);
            rayDirection = pixelCentre - screenInfo.cameraCentre;
            Ray r{screenInfo.cameraCentre, rayDirection};

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
