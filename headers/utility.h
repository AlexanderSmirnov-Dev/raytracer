#pragma once

bool surrounds(double x, double min, double max) {
    return min < x && x < max;
}

double clamp(double x, double min, double max) {
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}
