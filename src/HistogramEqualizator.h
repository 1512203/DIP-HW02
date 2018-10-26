#ifndef HISTOGRAMEQUALIZATOR_INCLUDED
#define HISTOGRAMEQUALIZATOR_INCLUDED

#include "common.h"
#include "BaseProcessor.h"


class HistogramEqualizator: public BaseProcessor {
private:
protected:
    void calculateHistogram(double* hist);
    Mat processImage(argv_t kwargs);
public:
    HistogramEqualizator(const string pathToImage): BaseProcessor(pathToImage) {}
};


#endif
