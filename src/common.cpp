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


void rgb2hsv(int r, int g, int b, int &h, int &s, int &v) {
    h = 0;
    double cMax = r > g ? (r > b ? r : b) : (g > b ? g : b);
    double cMin = r < g ? (r < b ? r : b) : (g < b ? g : b);
    double delta = cMax - cMin;

    if (delta == 0) 
        h = 0;
    else if (cMax == r) 
        h = cvRound(60.0 * (g - b)/delta);
    else if (cMax == g) 
        h = cvRound(60.0 * ((b - r)/delta + 2.0));
    else if (cMax == b) 
        h = cvRound(60.0 * ((r - g)/delta + 4.0));

    if (h < 0) 
        h += 360;

    if (cMax == 0) 
        s = 0;
    else
        s = cvRound(100.0 * delta / cMax);

    v = cvRound(100.0 * cMax / 255);
}


void hsv2rgb(int h, int s, int v, int &r, int &g, int &b) {
    double v_ = v / 100.0;
    double s_ = s / 100.0;
    double hh = h / 60.0;
    int i = int(hh);
    double ff = hh - i;
    double p = v_ * (1.0 - s_);
    double q = v_ * (1.0 - s_*ff);
    double t = v_ * (1.0 - s_*(1.0 - ff));
    if (i == 0) 
        r = cvRound(v_ * 255), g = cvRound(t * 255), b = cvRound(p * 255);
    else if (i == 1) 
        r = cvRound(q * 255), g = cvRound(v_ * 255), b = cvRound(p * 255);
    else if (i == 2) 
        r = cvRound(p * 255), g = cvRound(v_ * 255), b = cvRound(t * 255);
    else if (i == 3)
        r = cvRound(p * 255), g = cvRound(q * 255), b = cvRound(v_ * 255);
    else if (i == 4)
        r = cvRound(t * 255), g = cvRound(p * 255), b = cvRound(v_ * 255);
    else 
        r = cvRound(v_ * 255), g = cvRound(p * 255), b = cvRound(q * 255);
}
