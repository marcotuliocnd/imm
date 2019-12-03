#include "../../libs/ImageMap/ImageMap.h"

int OpenImage(char *imageRelativePath) {
  Image *image = readImageTextFormat(imageRelativePath, 1);
  printImage(image);
}
