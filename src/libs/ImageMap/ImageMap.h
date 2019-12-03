#include <stdio.h>
#include "../Matriz/Matriz.h"

typedef Matriz Image;

Image *readImageTextFormat(char *pathToImage, int type);
void freeImage(Image *image);
int printImage(Image *image);
int convertImageIntoBinary(char *sourcePath, char *savePath);
int getWidth(Image *image);
int getHeight(Image *image);
int makeTresholding(Image *image, int thr, char *destinePath);
int saveImage(Image *image, char *destinePath);
