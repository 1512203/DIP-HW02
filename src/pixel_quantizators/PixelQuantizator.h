#ifndef PIXELQUANTIZATOR_INCLUDED
#define PIXELQUANTIZATOR_INCLUDED

#include "../common.h"


class PixelQuantizator {
private:
protected:
    Mat image;
public:
    PixelQuantizator(Mat image);
    virtual int getQuantMax() = 0;
    virtual int quantizePixel(int y, int x) = 0;
    virtual void assignPixelFromQuantization(Mat* resultImage, int y, int x, int value) = 0;
};

#endif

