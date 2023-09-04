#pragma once

#include <vector>
#include <iostream>

struct rgb {
    double r;
    double g;
    double b;
};

void rgbToStandardOutput(const std::vector<std::vector<rgb>>& normalRGBArray); // accepts rgb array with values between 0 and 1
