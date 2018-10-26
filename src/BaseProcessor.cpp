#include "BaseProcessor.h"


BaseProcessor::BaseProcessor(const string pathToImage) {
    this->image = readImage(pathToImage);
}


void BaseProcessor::execute(argv_t kwargs) {
    this->processImage(kwargs);
}


BaseProcessor::~BaseProcessor() {
    //
}

