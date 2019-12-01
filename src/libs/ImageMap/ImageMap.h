#include <stdio.h>
#include "../Matriz/Matriz.h"

typedef Matriz Image;

Image *readImageTextFormat(char *pathToImage);
void freeImage(Image *image);
int printImage(Image *image);
