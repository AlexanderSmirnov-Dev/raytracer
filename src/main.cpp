#include "main.h"

int main() {
    Timer stopWatch{};

    uint64_t screenWidth{1920};
    uint64_t screenHeight{1080};
    scene_info sceneInfo{};
    sceneInfo = generateScene(screenWidth, screenHeight);

    std::vector<std::vector<rgb>> temp{};
    temp.resize(screenHeight, std::vector<rgb>(screenWidth));

    // --- temp code refactor later --- //


    // --- end --- //

    render(temp, sceneInfo);
}
