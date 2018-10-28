#include "HChannelQuantizator.h"


int HChannelQuantizator::getQuantMax() {
    return this->QUANT_MAX;
}


int HChannelQuantizator::quantizePixel(int y, int x) {
    int r = this->image.at<Vec3b>(y, x)[2];
    int g = this->image.at<Vec3b>(y, x)[1];
    int b = this->image.at<Vec3b>(y, x)[0];
    int h, s, v;
    rgb2hsv(r, g, b, h, s, v);
    return h;
}


void HChannelQuantizator::assignPixelFromQuantization(Mat* resultImage, int y, int x, int value) {
    int r = this->image.at<Vec3b>(y, x)[2];
    int g = this->image.at<Vec3b>(y, x)[1];
    int b = this->image.at<Vec3b>(y, x)[0];
    int h, s, v;
    rgb2hsv(r, g, b, h, s, v);
    h = value;
    hsv2rgb(h, s, v, r, g, b);
    resultImage->at<Vec3b>(y, x)[2] = r;
    resultImage->at<Vec3b>(y, x)[1] = g;
    resultImage->at<Vec3b>(y, x)[0] = b;
}
