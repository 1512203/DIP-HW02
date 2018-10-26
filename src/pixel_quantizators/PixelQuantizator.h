#ifndef PIXELQUANTIZATOR_INCLUDED
#define PIXELQUANTIZATOR_INCLUDED

#include "../common.h"


class PixelQuantizator {
private:
protected:
    Mat image;
public:
    PixelQuantizator(Mat image);
    virtual int quantizePixel(int y, int x) = 0;
};

#endif

