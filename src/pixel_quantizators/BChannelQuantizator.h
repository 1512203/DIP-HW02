#ifndef BCHANNELQUANTIZATOR_INCLUDED
#define BCHANNELQUANTIZATOR_INCLUDED

#include "../common.h"
#include "PixelQuantizator.h"


class BChannelQuantizator: public PixelQuantizator {
private:
protected:
    Mat image;
public:
    BChannelQuantizator(Mat image): PixelQuantizator(image) {}
    int quantizePixel(int y, int x);
};

#endif

