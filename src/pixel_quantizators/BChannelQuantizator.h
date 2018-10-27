#ifndef BCHANNELQUANTIZATOR_INCLUDED
#define BCHANNELQUANTIZATOR_INCLUDED

#include "../common.h"
#include "PixelQuantizator.h"


class BChannelQuantizator: public PixelQuantizator {
private:
protected:
    static const int QUANT_MAX = 255;
    Mat image;
public:
    BChannelQuantizator(Mat image): PixelQuantizator(image) {}
    int getQuantMax();
    int quantizePixel(int y, int x);
    void assignPixelFromQuantization(Mat* resultImage, int y, int x, int value);
};

#endif

