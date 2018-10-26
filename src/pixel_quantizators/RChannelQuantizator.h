#ifndef RCHANNELQUANTIZATOR_INCLUDED
#define RCHANNELQUANTIZATOR_INCLUDED

#include "../common.h"
#include "PixelQuantizator.h"


class RChannelQuantizator: public PixelQuantizator {
private:
protected:
    Mat image;
public:
    RChannelQuantizator(Mat image): PixelQuantizator(image) {}
    int quantizePixel(int y, int x);
};

#endif

