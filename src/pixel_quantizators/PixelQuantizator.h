#ifndef PIXELQUANTIZATOR_INCLUDED
#define PIXELQUANTIZATOR_INCLUDED

#include "../common.h"


class PixelQuantizator {
private:
protected:
    Mat image;
public:
    PixelQuantizator(Mat image);
    virtual int getQuantMax() = 0;																// Get number of bins for the histogram
    virtual int quantizePixel(int y, int x) = 0;												// Quantize pixel at (y, x) as an integer (bin)
    virtual void assignPixelFromQuantization(Mat* resultImage, int y, int x, int value) = 0;	// Assign quantized value of resultImage 
																								// at pixel (y, x) as value
};

#endif

