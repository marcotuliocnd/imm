#include <stdio.h>

#include "../../libs/ImageMap/ImageMap.h"

int ConvertImage(char *imageRelativePath, char *imageRelativePathConverted) {
  convertImageIntoBinary(imageRelativePath, imageRelativePathConverted);

  printf("\nImage successfuly converted to %s", imageRelativePathConverted);

  return 0;
}
