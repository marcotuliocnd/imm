#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../libs/ImageMap/ImageMap.h"
#include "../../libs/misc/Miscelaneous.h"

int ConvertImage(char *imageRelativePath, char *imageRelativePathConverted) {
  int checkFileFormatResult = checkFileFormat(imageRelativePath);
  switch(checkFileFormatResult) {
    case 1:
      printf("\nError\n");
      printf("Cannot convert a binary image into another binary image\n");
      exit(1);
    break;
    case -1:
      printf("\nError:\n");
      printf("The image provided has an unsupported format\n");
      exit(1);
    break;
  }

  checkFileFormatResult = checkFileFormat(imageRelativePathConverted);
  if (checkFileFormatResult != 1)
    addFormat(imageRelativePathConverted, 1);


  Image *image = readImageTextFormat(imageRelativePath);
  convertImageIntoBinary(image, imageRelativePathConverted);

  printf("\nImage successfuly converted to %s", imageRelativePathConverted);

  return 0;
}
