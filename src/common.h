#ifndef COMMON_INCLUDED
#define COMMON_INCLUDED



/* Include libraries */

// C Library
#include <cstring>

// C++ Standard Libraries
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

// OpenCV Libraries
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



/* Include elements in namespace std */

// Std input/output
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

// Std data structures
using std::map;
using std::string;

// Std utility functions
using std::max;
using std::min;
using std::stof;



/* Include elements in namespace cv */

// OpenCV Constants 
using cv::IMREAD_COLOR;
using cv::WINDOW_AUTOSIZE;

// OpenCV data structures
using cv::Mat;
using cv::Point;
using cv::Scalar;
using cv::Vec3b;

// OpenCV utility functions
using cv::imshow;
using cv::imread;
using cv::imwrite;
using cv::namedWindow;
using cv::saturate_cast;
using cv::waitKey;



/* Define to pass argument */

typedef map<string, string> argv_t;
typedef map<string, void*> argv_json;



/* Define constants */

#define ERROR_MESS_INVALID_ARGUMENTS                "Invalid arguments!"
#define ERROR_MESS_INVALID_COMMANDS                 "Invalid command!"

#define COMMAND_HISTOGRAM_EQUALIZATION_GRAYSCALE    "--hqgray"
#define COMMAND_HISTOGRAM_EQUALIZATION_RGB          "--hqrgb"
#define COMMAND_HISTOGRAM_EQUALIZATION_HSV          "--hqhsv"

#define DELIMITER_CHAR                              ','
#define LIST_CHANNELS_FIELD                         "list-channel"
#define B_CHANNEL                                   "b_channel"
#define G_CHANNEL                                   "g_channel"
#define R_CHANNEL                                   "r_channel"
#define H_CHANNEL                                   "h_channel"
#define GRAY_CHANNEL                                "gray_channel"


const double TO_GRAYSCALE_COEFF[3] = { 0.11, 0.59, 0.30 };
const double EPSILON = 1E-9;



/* Some utility function */

Mat readImage(string pathToImage);
void displayImage(string windowName, Mat img);
bool isGrayscale(Mat img);
bool isEqualDouble(double a, double b);
void rgb2hsv(int r, int g, int b, int &h, int &s, int &v); // 0 <= r, g, b <= 255 ; 0 <= h <= 360 ; 0 <= s, v <= 100
void hsv2rgb(int h, int s, int v, int &r, int &g, int &b); // 0 <= r, g, b <= 255 ; 0 <= h <= 360 ; 0 <= s, v <= 100

#endif

