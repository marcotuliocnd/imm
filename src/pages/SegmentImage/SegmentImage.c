#include <stdlib.h>
#include <stdio.h>

#include "../../libs/ImageMap/ImageMap.h"

int SegmentImage(char *thr, char *sourcePath, char *destinePath) {
  int thresholdLimit = atoi(thr);
  if (thresholdLimit > 255) {
    printf("Error! Thresholding cannot be bigger than 255\n");
    exit(1);
  } else if (thresholdLimit <= 0) {
    printf("Error! Thresholding cannot be lower than 1\n");
    exit(1);
  }

  Image *sourceImage = readImageTextFormat(sourcePath, 1);
  makeTresholding(sourceImage, thresholdLimit, destinePath);

  printf("Segment was successfuly done\n");
}
