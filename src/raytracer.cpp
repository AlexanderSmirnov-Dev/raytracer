#include "raytracer.h"
#include "sceneInfo.h"

void render(std::vector<std::vector<rgb>> pixelVec, const scene_info& sceneInfo) {
    vec3 pixelCentre{};
    vec3 rayDirection{};
    rgb pixelColour{};
    for (int j{}; j < sceneInfo.screenHeight; ++j) {
        for (int i{}; i < sceneInfo.screenWidth; ++i) {
            pixelColour = {0, 0, 0};
            for (int sample{}; sample < sceneInfo.samplesPerPixel; ++sample) {
                //pixelCentre = sceneInfo.pixelUpperLeft + (i * sceneInfo.pixelDeltaHor) + (j * sceneInfo.pixelDeltaVer);
                //rayDirection = pixelCentre - sceneInfo.cameraCentre;
                //Ray r{sceneInfo.cameraCentre, rayDirection};

                Ray r{};
                r = getRay(i, j, sceneInfo);
                pixelColour += r.rayColour();
            }
            double scale{1.0 / sceneInfo.samplesPerPixel}; // anti aliasing
            pixelColour *= scale;
            pixelVec.at(j).at(i) = pixelColour;
        }
    }

    rgbToStandardOutput(pixelVec);
}


vec3 Ray::eval(double t) {
    return ori + t * dir;
}

rgb Ray::rayColour() {
    double t{sphereCollision(vec3{0, 0, -1}, 0.5, *this)};
    vec3 preN{this->eval(t) - vec3{0, 0, -1}};

    if (t > 0.0) {
        vec3 N{preN / preN.norm()};
        return (0.5 * rgb{N.x() + 1,N.y() + 1,N.z() + 1});
    }

    vec3 unitDir{dir / dir.norm()};
    double a{0.5 * unitDir.y() + 1.0};
    double b{1.0 - a};
    return rgb(1.0 * b + 0.5 * a, 1.0 * b + 0.7 * a, 1.0 * b + 1.0 * a);
}


double sphereCollision(const vec3& centre, double radius, const Ray& ray) {
    vec3 oc{ray.ori - centre};
    double a{std::pow(ray.dir.norm(), 2)};
    double halfB{oc.dot(ray.dir)};
    double c{std::pow(oc.norm(), 2) - radius * radius};
    double discriminant{halfB*halfB - a*c};

    if (discriminant < 0) 
        return -1.0;
    else 
        return (-halfB - sqrt(discriminant)) / a;
}


Ray getRay(u64 i, u64 j, const scene_info& sceneInfo) {
    // Get a randomly sampled camera ray for the pixel at location i,j
    vec3 pixelCentre{sceneInfo.pixelUpperLeft + i * sceneInfo.pixelDeltaHor + j * sceneInfo.pixelDeltaVer};
    vec3 pixelSample{pixelCentre + pixelSampleSquare(sceneInfo)};
    vec3 rayDirection{pixelSample - sceneInfo.cameraCentre};

    return Ray{sceneInfo.cameraCentre, rayDirection};
    
}


vec3 pixelSampleSquare(const scene_info& sceneInfo) {
    double px{-0.5 + randDouble()};
    double py{-0.5 + randDouble()};
    return (px * sceneInfo.pixelDeltaHor) + (py * sceneInfo.pixelDeltaVer); 
}
