#include "BChannelQuantizator.h"


int BChannelQuantizator::getQuantMax() {
    return this->QUANT_MAX;
}


int BChannelQuantizator::quantizePixel(int y, int x) {
    return this->image.at<Vec3b>(y, x)[0];
}


void BChannelQuantizator::assignPixelFromQuantization(Mat* resultImage, int y, int x, int value) {
}
