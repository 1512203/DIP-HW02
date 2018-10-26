#ifndef HCHANNELQUANTIZATOR_INCLUDED
#define HCHANNELQUANTIZATOR_INCLUDED

#include "../common.h"
#include "PixelQuantizator.h"


class HChannelQuantizator: public PixelQuantizator {
private:
protected:
    Mat image;
public:
    HChannelQuantizator(Mat image): PixelQuantizator(image) {}
    int quantizePixel(int y, int x);
};

#endif

