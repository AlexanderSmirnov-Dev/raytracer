#include "main.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

int main() {
    Timer stopWatch{};

    std::vector<std::vector<rgb>> temp{};
    temp.resize(SCREEN_HEIGHT);

    for (auto& vec : temp) {
        for (int j{}; j < SCREEN_WIDTH; ++j) {
            vec.emplace_back(rgb {j / 1000.0, 0, 0});
        }
    }

    rgbToStandardOutput(temp);
}
