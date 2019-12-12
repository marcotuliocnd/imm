#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../libs/ImageMap/ImageMap.h"
#include "../../libs/misc/Miscelaneous.h"

int OpenImage(char *imageRelativePath) {
  Image *image;
  int checkFileFormatResult = checkFileFormat(imageRelativePath);
  switch(checkFileFormatResult) {
    case 0:
      image = readImageTextFormat(imageRelativePath);
    break;

    case 1:
      image = readImageBinaryFormat(imageRelativePath);
    break;

    case -1:
      printf("\nError:\n");
      printf("The image provided has an unsupported format\n");
      exit(1);
    break;
  }
  printImage(image);
}
