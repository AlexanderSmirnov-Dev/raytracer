#include "sceneInfo.h"

scene_info generateScene(u64 screenWidth, u64 screenHeight) {
    scene_info sceneInfo{};

    sceneInfo.screenWidth = screenWidth;
    sceneInfo.screenHeight = screenHeight;

    double viewportHeight{2.0};
    double viewportWidth = viewportHeight * static_cast<double>(screenWidth / static_cast<double>(screenHeight));
    double focalLength{2.0};
    vec3 cameraCentre{0, 0, 0};

    vec3 viewportHorVec{viewportWidth, 0, 0};
    vec3 viewportVerVec{0, -viewportHeight, 0};

    vec3 pixelDeltaHor = viewportHorVec / screenWidth;
    vec3 pixelDeltaVer = viewportVerVec / screenHeight;

    vec3 viewportUpperLeft = cameraCentre - vec3{0, 0, focalLength} - viewportHorVec / 2 - viewportVerVec / 2;
    vec3 pixelUpperLeft = viewportUpperLeft + 0.5 * (pixelDeltaHor + pixelDeltaVer);

    sceneInfo.pixelDeltaVer = pixelDeltaVer;
    sceneInfo.pixelDeltaHor = pixelDeltaHor;
    sceneInfo.pixelUpperLeft = pixelUpperLeft;    
    sceneInfo.cameraCentre = cameraCentre;    

    return sceneInfo;
};
