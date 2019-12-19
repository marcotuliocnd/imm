#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../libs/ImageMap/ImageMap.h"
#include "../../libs/misc/Miscelaneous.h"
#include "./ComponenteConexo.h"

int ComponenteConexo(char *imageRelativePath, char *imageRelativePathConverted) {
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

  cc(image, imageRelativePathConverted);
  printf("\nReleated components was successfuly done", imageRelativePathConverted);
}
