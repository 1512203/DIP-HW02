#include "RChannelQuantizator.h"


int RChannelQuantizator::getQuantMax() {
    return this->QUANT_MAX;
}


int RChannelQuantizator::quantizePixel(int y, int x) {
    return this->image.at<Vec3b>(y, x)[2];
}


void RChannelQuantizator::assignPixelFromQuantization(Mat* resultImage, int y, int x, int value) {
    resultImage->at<Vec3b>(y, x)[2] = value;
}
