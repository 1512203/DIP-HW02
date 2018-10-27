#include "HChannelQuantizator.h"


int HChannelQuantizator::getQuantMax() {
    return this->QUANT_MAX;
}


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
    else {
        for (int c = 0; c < 2; ++c) {
            if (isEqualDouble(cMax, normCol[c])) {
                hueLevel = (normCol[(c+2)%3]-normCol[(c+1)%3]) / delta;
                hueLevel += 2.0 * c;
            }
        }
        hueLevel *= 60.0;
        if (hueLevel < EPSILON) {
            hueLevel += 360.0;
        }
    }
    return int(hueLevel);
}


void HChannelQuantizator::assignPixelFromQuantization(Mat* resultImage, int y, int x, int value) {
}
