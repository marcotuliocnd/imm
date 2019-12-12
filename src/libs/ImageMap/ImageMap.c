#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ImageMap.h"

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
  int j = 0;
  char linha[width*height];
  char *pixelString;
  int pixelInt;
  int pos;
  for (i = 0; i < height; i++) {
    fgets(linha, sizeof(linha), filePointer);
    pixelString = strtok(linha,"\t");
    for (j = 0; j < width; j++) {
      pixelInt = atoi(pixelString);
      pos = j * height + i;
      insertMatriz(image, pixelInt, pos);
      pixelString = strtok(NULL, "\t");
    }
  }
  fclose(filePointer);
  return image;
}

Image *readImageBinaryFormat(char *pathToImage) {
  FILE *filePointer;
  filePointer = fopen(pathToImage, "rb");
  checkNullPointer(filePointer);

  int width;
  int height;
  int pixelCanvas;
  fread(&width, sizeof(int), 1, filePointer);
  fread(&height, sizeof(int), 1, filePointer);
  Image *image = createMatriz(height, width);

  int i = 0;
  int j = 0;
  int pos;
  for (i = 0; i < height + 2; i++) {
    for(j = 0; j < width; j++) {
      fread(&pixelCanvas, sizeof(int), 1, filePointer);
      pos = j * height + i;
      insertMatriz(image, pixelCanvas, pos);
    }
  }
  fclose(filePointer);
  return image;
}

int convertImageIntoText(Image *image, char *destinePath) {
  checkNullPointer(image);

  FILE *filePointerDestine;
  filePointerDestine = fopen(destinePath, "wb");
  checkNullPointer(filePointerDestine);

  int width = getWidth(image);
  int height = getHeight(image);

  int i;
  int j;
  int element;
  int pos;
  fprintf(filePointerDestine, "%i\n%i\n", width, height);
  for (i = 0; i < height + 2; i++) {
    for (j = 0; j < width; j++) {
      pos = j * height + i;
      element = getElementInPoint(image, pos);
      fprintf(filePointerDestine, "%i", element);
      if(j+1 == width)
        fprintf(filePointerDestine, "\n");
      else
        fprintf(filePointerDestine, "\t");
    }
  }

  fclose(filePointerDestine);
  return 0;
}

int convertImageIntoBinary(Image *image, char *savePath) {
  checkNullPointer(image);

  FILE *filePointerDestine;
  filePointerDestine = fopen(savePath, "wb");
  checkNullPointer(filePointerDestine);

  int width = getWidth(image);
  int height = getHeight(image);

  int i;
  int j;
  int element;
  int pos;
  fwrite(&width, sizeof(int), 1, filePointerDestine);
  fwrite(&height, sizeof(int), 1, filePointerDestine);
  for (i = 0; i < height + 2; i++) {
    for(j = 0; j < width; j++) {
      pos = j * height + i;
      element = getElementInPoint(image, pos);
      fwrite(&element, sizeof(int), 1, filePointerDestine);
    }
  }

  fclose(filePointerDestine);
  return 0;
}

int getWidth(Image *image) {
  checkNullPointer(image);

  return getColumns(image);
}

int getHeight(Image *image) {
  checkNullPointer(image);

  return  getRows(image);
}

int getPixelInPoint(Image *image, int i, int j) {
  int pos = j * getHeight(image) * i;
  return getElementInPoint(image, pos);
}

int printPixel(Image *image, int pos) {
  checkNullPointer(image);
  printOne(image, pos);

  return 0;
}

int printImage(Image *image) {
  checkNullPointer(image);
  printMatriz(image);
  printf("\n");
  return 0;
}

int makeTresholding(Image *image, int thr, char *destinePath, int fileFormat) {
  checkNullPointer(image);
  replaceMatriz(image, thr);

  if (fileFormat == 0)
    convertImageIntoText(image, destinePath);
  else
    convertImageIntoBinary(image, destinePath);
  return 0;
}

void freeImage(Image *image) {
  checkNullPointer(image);
  freeMatriz(image);
}
