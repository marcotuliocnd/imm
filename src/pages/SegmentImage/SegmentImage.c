#include <stdlib.h>
#include <stdio.h>

#include "../../libs/ImageMap/ImageMap.h"
#include "../../libs/misc/Miscelaneous.h"

int SegmentImage(char *thr, char *sourcePath, char *destinePath) {
  int thresholdLimit = atoi(thr);
  if (thresholdLimit > 255) {
    printf("Error! Thresholding cannot be bigger than 255\n");
    exit(1);
  } else if (thresholdLimit <= 0) {
    printf("Error! Thresholding cannot be lower than 1\n");
    exit(1);
  }

  Image *image;
  int checkFileFormatResult = checkFileFormat(sourcePath);
  switch(checkFileFormatResult) {
    case 0:
      image = readImageTextFormat(sourcePath);
    break;

    case 1:
      image = readImageBinaryFormat(sourcePath);
    break;

    case -1:
      printf("\nError:\n");
      printf("The image provided has an unsupported format\n");
      exit(1);
    break;
  }

  addFormat(destinePath, checkFileFormatResult);
  makeTresholding(image, thresholdLimit, destinePath, checkFileFormatResult);

  printf("Segment was successfuly done in %s\n", checkFileFormatResult, destinePath);
}
