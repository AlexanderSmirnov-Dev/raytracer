#include "sceneInfo.h"

scene_info generateScene(uint64_t screenWidth, uint64_t screenHeight) {
    scene_info sceneInfo{};

    sceneInfo.screenWidth = screenWidth;
    sceneInfo.screenHeight = screenHeight;

    double viewportHeight{2.0};
    double viewportWidth = viewportHeight * static_cast<double>(screenWidth / static_cast<double>(screenHeight));
    double focalLength{2.0};
    Vector3d cameraCentre{0, 0, 0};

    Vector3d viewportHorVec{viewportWidth, 0, 0};
    Vector3d viewportVerVec{0, -viewportWidth, 0};

    Vector3d pixelDeltaHor = viewportHorVec / screenWidth;
    Vector3d pixelDeltaVer = viewportVerVec / screenHeight;

    Vector3d viewportUpperLeft = cameraCentre - Vector3d{0, 0, focalLength} - viewportHorVec / 2 - viewportVerVec / 2;
    Vector3d pixelUpperLeft = viewportUpperLeft + 0.5 * (pixelDeltaHor + pixelDeltaVer);

    sceneInfo.pixelDeltaVer = pixelDeltaVer;
    sceneInfo.pixelDeltaHor = pixelDeltaHor;
    sceneInfo.pixelUpperLeft = pixelUpperLeft;    
    sceneInfo.cameraCentre = cameraCentre;    

    return sceneInfo;
};
