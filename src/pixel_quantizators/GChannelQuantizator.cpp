#include "GChannelQuantizator.h"


int GChannelQuantizator::getQuantMax() {
    return this->QUANT_MAX;
}


int GChannelQuantizator::quantizePixel(int y, int x) {
    return this->image.at<Vec3b>(y, x)[1];
}


void GChannelQuantizator::assignPixelFromQuantization(Mat* resultImage, int y, int x, int value) {
    resultImage->at<Vec3b>(y, x)[1] = value;
}
