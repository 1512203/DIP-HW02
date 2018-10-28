#include "HistogramEqualizator.h"


void HistogramEqualizator::calculateHistogram(double* &hist, PixelQuantizator* pixelQuantizator) {
    hist = new double[pixelQuantizator->getQuantMax() + 1];
	for (int v = 0; v <= pixelQuantizator->getQuantMax(); ++v)
		hist[v] = 0;
    for (int y = 0; y < this->image.rows; ++y) {
        for (int x = 0; x < this->image.cols; ++x) {
            int v = pixelQuantizator->quantizePixel(y, x);
            hist[v]++;
        }
    }
}


void HistogramEqualizator::equalizeHistogram(double* hist, PixelQuantizator* pixelQuantizator) {
    for (int v = 1; v <= pixelQuantizator->getQuantMax(); ++v) {
        hist[v] += hist[v-1];
    }
    double sum = hist[pixelQuantizator->getQuantMax()];
    for (int v = 0; v <= pixelQuantizator->getQuantMax(); ++v) {
        hist[v] = (hist[v] * pixelQuantizator->getQuantMax() / sum);
    }
}


void HistogramEqualizator::getImageFromEqualizedHistogram(double* hist, PixelQuantizator* pixelQuantizator, Mat* resultImage) {
    for (int y = 0; y < this->image.rows; ++y) {
        for (int x = 0; x < this->image.cols; ++x) {
            int v = pixelQuantizator->quantizePixel(y, x);
            int new_v = cvRound(hist[v]);
            pixelQuantizator->assignPixelFromQuantization(resultImage, y, x, new_v);
        }
    }
}


Mat HistogramEqualizator::processImage(argv_t kwargs) {
    string listChannels = kwargs[LIST_CHANNELS_FIELD];
    size_t pos = 0;
    string token;
    Mat resultImage = Mat::zeros(this->image.size(), this->image.type());
    while ((pos = listChannels.find(DELIMITER_CHAR)) != string::npos) {
        token = listChannels.substr(0, pos);
        PixelQuantizator* pixelQuantizator = NULL;
		cout << "Equalizing on " << token << endl;
        if (token == B_CHANNEL) {
             pixelQuantizator = new BChannelQuantizator(this->image);
        }
        else if (token == G_CHANNEL) {
             pixelQuantizator = new GChannelQuantizator(this->image);
        }
        else if (token == R_CHANNEL) {
             pixelQuantizator = new RChannelQuantizator(this->image);
        }
        else if (token == GRAY_CHANNEL) {
             pixelQuantizator = new GrayLevelQuantizator(this->image);
        }
        else if (token == H_CHANNEL) {
             pixelQuantizator = new HChannelQuantizator(this->image);
        }

        if (pixelQuantizator) {
            double* hist = NULL;
			cout << "Calculating histogram!" << endl;
            this->calculateHistogram(hist, pixelQuantizator);
			cout << "Equalizating histogram!" << endl;
			this->equalizeHistogram(hist, pixelQuantizator);
			cout << "Getting image from histogram!" << endl;
			this->getImageFromEqualizedHistogram(hist, pixelQuantizator, &resultImage);
			delete[] hist;
			delete pixelQuantizator;
        }
       listChannels.erase(0, pos + 1);
    }
    return resultImage;
}


HistogramEqualizator::~HistogramEqualizator() {
    // 
}
