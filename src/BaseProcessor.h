#ifndef BASEPROCESSOR_INCLUDED
#define BASEPROCESSOR_INCLUDED

#include "common.h"

class BaseProcessor {
private:
protected:
    Mat image;
    virtual void calculateHistogram(double* hist) = 0;
    virtual Mat processImage(argv_t kwargs) = 0;
public:
    BaseProcessor(const string pathToImage);
    void execute(argv_t kwargs);
    virtual ~BaseProcessor();
};

#endif

