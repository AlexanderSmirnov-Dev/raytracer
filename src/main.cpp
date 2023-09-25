#include "main.h"


int main() {
    Timer stopWatch{};

    uint64_t screenWidth{1920};
    uint64_t screenHeight{1080};
    screen_info screenInfo{screenWidth, screenHeight};

    std::vector<std::vector<rgb>> temp{};
    temp.resize(screenHeight, std::vector<rgb>(screenWidth));

    // --- temp code refactor later --- //

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

    screenInfo.pixelDeltaVer = pixelDeltaVer;
    screenInfo.pixelDeltaHor = pixelDeltaHor;
    screenInfo.pixelUpperLeft = pixelUpperLeft;    
    screenInfo.cameraCentre = cameraCentre;    

    // --- end --- //


    render(temp, screenInfo);
}
