#include <stdio.h>
#include <string.h>
#include "../libs/misc/Miscelaneous.h"

void redirectFunction(int numberOfArguments, char **functionality) {
    if (numberOfArguments < 3) {
        printf("Error, No files passed! Usage: ./imm -option file\n");
    } else if (strcmp(*(functionality + 1), "-open") == 0) {
        printf("Open an image %s\n", *(functionality + 2));
    } else if (strcmp(*(functionality + 1), "-convert") == 0) {
        printf("Convert an image %s\n", *(functionality + 2));
    } else if (strcmp(*(functionality + 1), "-segment") == 0) {
        printf("Segment an image %s\n", *(functionality + 2));
    } else if (strcmp(*(functionality + 1), "-cc") == 0) {
        printf("Detect conected components in an image %s\n", *(functionality + 2));
    } else if (strcmp(*(functionality + 1), "-lab") == 0) {
        printf("Show the path to be traveled %s\n", *(functionality + 2));
    } else {
        printf("Error! Usage: ./imm -option file\n");
    }
}

int main(int argc, char *argv[]) {
        printSoftwareTitle();
        redirectFunction(argc, argv);
    return 0;
}

