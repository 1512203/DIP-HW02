#ifndef HCHANNELQUANTIZATOR_INCLUDED
#define HCHANNELQUANTIZATOR_INCLUDED

#include "../common.h"
#include "PixelQuantizator.h"


class HChannelQuantizator: public PixelQuantizator {
private:
protected:
    static const int QUANT_MAX = 360;
    Mat image;
public:
    HChannelQuantizator(Mat image): PixelQuantizator(image) {}
    int getQuantMax();
    int quantizePixel(int y, int x);
    void assignPixelFromQuantization(Mat* resultImage, int y, int x, int value);
};

#endif

