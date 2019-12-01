#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/misc/Miscelaneous.h"
#include "./libs/ImageMap/ImageMap.h"

void redirectFunction(int numberOfArguments, char functionality[8], char imageRelativePath[50]) {
  if (numberOfArguments < 3 && numberOfArguments >= 2) {
      printf("Error, No files passed! Usage: ./imm -option file\n");
  } else if (strcmp(functionality, "-open") == 0) {
      Image *image = readImageTextFormat(imageRelativePath);
      printImage(image);
  } else if (strcmp(functionality, "-convert") == 0) {
      printf("Convert an image %s\n", imageRelativePath);
  } else if (strcmp(functionality, "-segment") == 0) {
      printf("Segment an image %s\n", imageRelativePath);
  } else if (strcmp(functionality, "-cc") == 0) {
      printf("Detect conected components in an image %s\n", imageRelativePath);
  } else if (strcmp(functionality, "-lab") == 0) {
      printf("Show the path to be traveled %s\n", imageRelativePath);
  } else {
      printf("Error! Usage: ./imm -option file\n");
  }
}

int main(int argc, char *argv[]) {
        printSoftwareTitle();
        redirectFunction(argc, argv[1], argv[2]);
    return 0;
}
