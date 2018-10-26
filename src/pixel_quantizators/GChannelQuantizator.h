#ifndef GCHANNELQUANTIZATOR_INCLUDED
#define GCHANNELQUANTIZATOR_INCLUDED

#include "../common.h"
#include "PixelQuantizator.h"


class GChannelQuantizator: public PixelQuantizator {
private:
protected:
    Mat image;
public:
    GChannelQuantizator(Mat image): PixelQuantizator(image) {}
    int quantizePixel(int y, int x);
};

#endif

