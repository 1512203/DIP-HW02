#include "GrayLevelQuantizator.h"


int GrayLevelQuantizator::quantizePixel(int y, int x) {
    double grayLevel = 0.0;
    for (int c = 0; c < 3; ++c)
        grayLevel += TO_GRAYSCALE_COEFF[c] * this->image.at<Vec3b>(y, x)[c];
    return int(grayLevel);
}

