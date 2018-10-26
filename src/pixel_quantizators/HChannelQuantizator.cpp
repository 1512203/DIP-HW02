#include "HChannelQuantizator.h"


int HChannelQuantizator::quantizePixel(int y, int x) {
    double normCol[3], cMax = -0.1, cMin = 1.1;
    for (int c = 0; c < 3; ++c) {
        normCol[c] = this->image.at<Vec3b>(y, x)[c] / 255.0;
        cMax = max(cMax, normCol[c]);
        cMin = min(cMin, normCol[c]);
    }
    double delta = cMax - cMin;
    double hueLevel = 0.0;
    if (isEqualDouble(delta, 0.0)) {
        hueLevel = 0.0;
    }
    else if (isEqualDouble(cMax, normCol[2])) {
        hueLevel = 
    }
    return int(hueLevel);
}

