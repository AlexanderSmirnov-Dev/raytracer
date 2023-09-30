#include "ppmFileGen.h"

void rgbToStandardOutput(const std::vector<std::vector<rgb>>& normalRGBArray) { // accepts rgb array with values between 0 and 1
    std::cout << "P3\n";
    std::cout << normalRGBArray.at(0).size() << ' ' << normalRGBArray.size() << '\n';
    std::cout << 255 << '\n';

    int i{};

    for (const auto& outerVec : normalRGBArray) {
        std::clog << "\rScanlines remaining: " << (normalRGBArray.size() - i) << ' ' << std::flush;
        i += 1;
        for (const auto& innerVec: outerVec) {
            std::cout << static_cast<uint64_t>(255.999 * innerVec.x()) << ' ' << static_cast<uint64_t>(255.999 * innerVec.y()) << ' ' << static_cast<uint64_t>(255.999 * innerVec.z()) << '\n';
        }
    }

    std::clog << "\n";
    std::clog << "Done\n";
}
