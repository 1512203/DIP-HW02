#include "common.h"
#include "BaseProcessor.h"
#include "HistogramEqualizator.h"

void equalizeOnRGBUsingOpenCV(char* pathToImage) {
	Mat image = imread(pathToImage, IMREAD_COLOR);
	Mat channel[3], resultChannel[3];
	Mat resultImage;
	cv::split(image, channel);
	cv::equalizeHist(channel[0], resultChannel[0]);
	cv::equalizeHist(channel[1], resultChannel[1]);
	cv::equalizeHist(channel[2], resultChannel[2]);
	cv::merge(resultChannel, 3, resultImage);
	displayImage("OpenCV Result Image", resultImage);
}

void equalizeOnHUsingOpenCV(char* pathToImage) {
	Mat image = imread(pathToImage, IMREAD_COLOR);
	Mat hsvImage;
	Mat channel[3], resultChannel[3];
	Mat hsvResultImage, resultImage;
	cv::cvtColor(image, hsvImage, cv::COLOR_RGB2HSV);
	cv::split(hsvImage, channel);
	cv::equalizeHist(channel[0], resultChannel[0]);
	resultChannel[1] = channel[1];
	resultChannel[2] = channel[2];
	cv::merge(resultChannel, 3, hsvResultImage);
	cv::cvtColor(hsvResultImage, resultImage, cv::COLOR_HSV2RGB);
	displayImage("OpenCV Result Image", resultImage);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
        return -1;
    }

    char* pathToImage = argv[1];
    char* command = argv[2];

    BaseProcessor* proc = new HistogramEqualizator(pathToImage);
    argv_t kwargs;

    if (strcmp(command, COMMAND_HISTOGRAM_EQUALIZATION_GRAYSCALE) == 0) {
        kwargs[LIST_CHANNELS_FIELD] += GRAY_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
		equalizeOnRGBUsingOpenCV(pathToImage);
    }
    else if (strcmp(command, COMMAND_HISTOGRAM_EQUALIZATION_RGB) == 0) {
        kwargs[LIST_CHANNELS_FIELD] += R_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
        kwargs[LIST_CHANNELS_FIELD] += G_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
        kwargs[LIST_CHANNELS_FIELD] += B_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
		equalizeOnRGBUsingOpenCV(pathToImage);
    }
    else if (strcmp(command, COMMAND_HISTOGRAM_EQUALIZATION_HSV) == 0) {
        kwargs[LIST_CHANNELS_FIELD] += H_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
		equalizeOnHUsingOpenCV(pathToImage);
    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }
	cout << kwargs[LIST_CHANNELS_FIELD] << endl;
    proc->execute(kwargs);
    return 0;
}
