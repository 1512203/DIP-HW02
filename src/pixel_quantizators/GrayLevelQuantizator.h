#ifndef GRAYLEVELQUANTIZATOR_INCLUDED
#define GRAYLEVELQUANTIZATOR_INCLUDED

#include "../common.h"
#include "PixelQuantizator.h"


class GrayLevelQuantizator: public PixelQuantizator {
private:
protected:
    Mat image;
public:
    GrayLevelQuantizator(Mat image): PixelQuantizator(image) {}
    int quantizePixel(int y, int x);
};

#endif

