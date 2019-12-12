#include <stdio.h>
#include "../Matriz/Matriz.h"

typedef Matriz Image;

Image *readImageTextFormat(char *pathToImage);
Image *readImageBinaryFormat(char *pathToImage);

int convertImageIntoText(Image *image, char *destinePath);
int convertImageIntoBinary(Image *image, char *savePath);

int getWidth(Image *image);
int getHeight(Image *image);

int getPixelInPoint(Image *image, int i, int j);
int printPixel(Image *image, int pos);

int printImage(Image *image);

int makeTresholding(Image *image, int thr, char *destinePath, int fileFormat);

void freeImage(Image *image);
