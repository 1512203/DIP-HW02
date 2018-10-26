#include "GChannelQuantizator.h"


int GChannelQuantizator::quantizePixel(int y, int x) {
    return this->image.at<Vec3b>(y, x)[1];
}

