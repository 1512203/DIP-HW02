#include "common.h"

void displayImage(string windowName, Mat img) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, img);
}


Mat readImage(string pathToImage) {
    return imread(pathToImage, IMREAD_COLOR);
}


bool isGrayscale(Mat img) {
    for (int y = 0; y < img.rows; ++y)
        for (int x = 0; x < img.cols; ++x)
            for (int c = 0; c < 2; ++c)
                if (img.at<Vec3b>(y, x)[c] != img.at<Vec3b>(y, x)[c+1])
                    return false;
    return true;
}


bool isEqualDouble(double a, double b) {
    double delta = a-b;
    return delta <= EPSILON && delta >= -EPSILON;
}
