#include "ImageMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void checkNullPointer(void *pointer) {
  if (pointer == NULL){
    printf("\nThe specified file could not be opened\n");
    exit(EXIT_FAILURE);
  }
}

Image *readImageTextFormat(char *pathToImage) {
  FILE *filePointer;
  filePointer = fopen(pathToImage, "r");
  checkNullPointer(filePointer);

  int width;
  int height;
  fscanf(filePointer, "%i\n%i\n", &width, &height);

  Image *image = createMatriz(height, width);

  int i = 0;
  char linha[width*height];
  char *pixelString;
  int pixelInt;
  for (i = 0; i < height + 2; i++) {
    if (i > 1) {
      fgets(linha, sizeof(linha), filePointer);
      pixelString = strtok(linha,"	");
      while (pixelString != NULL) {
        if (pixelString[strlen(pixelString)-1] == '\n')
          pixelString[strlen(pixelString)-1] = 0;

        pixelInt = atoi(pixelString);

        insertMatriz(image, pixelInt);
        pixelString = strtok(NULL, "	");
        j++;
      }
    }
  }

  fclose(filePointer);
  return image;
}

void freeImage(Image *image) {
  checkNullPointer(image);
  freeMatriz(image);
}

int printImage(Image *image) {
  checkNullPointer(image);
  printMatriz(image);
  return 0;
}
