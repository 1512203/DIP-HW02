#include "RChannelQuantizator.h"


int RChannelQuantizator::quantizePixel(int y, int x) {
    return this->image.at<Vec3b>(y, x)[2];
}

