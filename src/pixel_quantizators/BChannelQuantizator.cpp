#include "BChannelQuantizator.h"

int BChannelQuantizator::quantizePixel(int y, int x) {
    return this->image.at<Vec3b>(y, x)[0];
}
