#ifndef RCHANNELQUANTIZATOR_INCLUDED
#define RCHANNELQUANTIZATOR_INCLUDED

#include "../common.h"
#include "PixelQuantizator.h"


class RChannelQuantizator: public PixelQuantizator {
private:
protected:
    static const int QUANT_MAX = 255;
public:
	RChannelQuantizator(Mat image): PixelQuantizator(image) {}
    int getQuantMax();
    int quantizePixel(int y, int x);
    void assignPixelFromQuantization(Mat* resultImage, int y, int x, int value);
};

#endif

