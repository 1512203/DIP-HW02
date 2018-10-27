#ifndef HISTOGRAMEQUALIZATOR_INCLUDED
#define HISTOGRAMEQUALIZATOR_INCLUDED

#include "common.h"
#include "BaseProcessor.h"
#include "pixel_quantizators/PixelQuantizator.h"
#include "pixel_quantizators/BChannelQuantizator.h"
#include "pixel_quantizators/GChannelQuantizator.h"
#include "pixel_quantizators/RChannelQuantizator.h"
#include "pixel_quantizators/HChannelQuantizator.h"
#include "pixel_quantizators/GrayLevelQuantizator.h"


class HistogramEqualizator: public BaseProcessor {
private:
protected:
    void calculateHistogram(double* hist, PixelQuantizator* pixelQuantizator);
    void equalizeHistogram(double* hist, PixelQuantizator* pixelQuantizator);
    void getImageFromEqualizedHistogram(double* hist, PixelQuantizator* pixelQuantizator, Mat* resultImage);
    Mat processImage(argv_t kwargs);
public:
    HistogramEqualizator(const string pathToImage): BaseProcessor(pathToImage) {}
};


#endif
