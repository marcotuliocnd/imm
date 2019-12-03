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

Image *readImageTextFormat(char *pathToImage, int type) {
  FILE *filePointer;
  filePointer = fopen(pathToImage, "r");
  checkNullPointer(filePointer);

  int width;
  int height;
  fscanf(filePointer, "%i\n%i\n", &width, &height);

  Image *image = createMatriz(height, width);

  if (type == 1) {
    int i = 0;
    char linha[width*height];
    char *pixelString;
    int pixelInt;
    for (i = 0; i < height + 2; i++) {
      if (i > 1) {
        fgets(linha, sizeof(linha), filePointer);
        pixelString = strtok(linha,"  ");
        while (pixelString != NULL) {
          if (pixelString[strlen(pixelString)-1] == '\n')
            pixelString[strlen(pixelString)-1] = 0;

          pixelInt = atoi(pixelString);

          insertMatriz(image, pixelInt);
          pixelString = strtok(NULL, "	");
        }
      }
    }
  }

  if (type == 2) {
    int i = 0;
    char linha[width*height];
    char *pixelString;
    int pixelInt;
    for (i = 0; i < height + 2; i++) {
      if (i > 1) {
        fread(linha, sizeof(linha), 2,filePointer);
        pixelString = strtok(linha,"	");
        while (pixelString != NULL) {
          if (pixelString[strlen(pixelString)-1] == '\n')
            pixelString[strlen(pixelString)-1] = 0;

          pixelInt = atoi(pixelString);

          insertMatriz(image, pixelInt);
          pixelString = strtok(NULL, "	");
        }
      }
    }
  }


  fclose(filePointer);
  return image;
}

int convertImageIntoBinary(char *sourcePath, char *savePath) {
  strcat(savePath, ".imm");

  FILE *filePointerSource;
  filePointerSource = fopen(sourcePath, "r");
  checkNullPointer(filePointerSource);

  FILE *filePointerDestine;
  filePointerDestine = fopen(savePath, "wb");
  checkNullPointer(filePointerDestine);

  int imageText;
  int num;
  while (!feof(filePointerSource)) {
         fread(&imageText, sizeof(int), 1, filePointerSource);
         num = imageText;
         fwrite(&num, sizeof(int), 4, filePointerDestine);
  }

  fclose(filePointerSource);
  fclose(filePointerDestine);

  return 0;
}

int makeTresholding(Image *image, int thr, char *destinePath) {
  checkNullPointer(image);
  replaceMatriz(image, thr);


  saveImage(image, destinePath);
  return 0;
}

int saveImage(Image *image, char *destinePath) {
  checkNullPointer(image);

  FILE *filePointerDestine;
  filePointerDestine = fopen(destinePath, "w");
  checkNullPointer(filePointerDestine);
  int width = getWidth(image);
  int height = getHeight(image);

  fprintf(filePointerDestine, "%i\n%i\n", width, height);
  int endOfLine = 1;
  for (int counter = 0; counter < width*height; counter++) {
    fprintf(filePointerDestine, "%i	", getEachElementInOrder(image));
    if (endOfLine == width) {
      fprintf(filePointerDestine, "\n");
      endOfLine = 0;
    }
    endOfLine++;
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

void freeImage(Image *image) {
  checkNullPointer(image);
  freeMatriz(image);
}

int printImage(Image *image) {
  checkNullPointer(image);
  printMatriz(image);
  return 0;
}
