#include "common.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
        return -1;
    }

    char* pathToImage = argv[1];
    char* command = argv[2];

    if (strcmp(command, COMMAND_HISTOGRAM_EQUALIZATION_GRAYSCALE) == 0) {

    }
    else if (strcmp(command, COMMAND_HISTOGRAM_EQUALIZATION_RGB) == 0) {

    }
    else if (strcmp(command, COMMAND_HISTOGRAM_EQUALIZATION_GRAYSCALE) == 0) {

    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }
    return 0;
}
