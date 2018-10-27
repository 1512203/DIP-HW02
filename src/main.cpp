#include "common.h"
#include "BaseProcessor.h"
#include "HistogramEqualizator.h"

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
    }
    else if (strcmp(command, COMMAND_HISTOGRAM_EQUALIZATION_RGB) == 0) {
        kwargs[LIST_CHANNELS_FIELD] += R_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
        kwargs[LIST_CHANNELS_FIELD] += G_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
        kwargs[LIST_CHANNELS_FIELD] += B_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
    }
    else if (strcmp(command, COMMAND_HISTOGRAM_EQUALIZATION_HSV) == 0) {
        kwargs[LIST_CHANNELS_FIELD] += H_CHANNEL;
        kwargs[LIST_CHANNELS_FIELD] += DELIMITER_CHAR;
    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }
	cout << kwargs[LIST_CHANNELS_FIELD] << endl;
    proc->execute(kwargs);
    return 0;
}
