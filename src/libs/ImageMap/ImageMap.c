#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ImageMap.h"
#include "../misc/Miscelaneous.h"
#include "../Stack/Stack.h"
#include "../DinamicStack/DinamicStack.h"

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

int cc(Image *image, char* destinefile) {
  int label = 2;
  int aux = 0;
  int *m, *origem;
  int nlin, ncol, x[4] = {-1,0,0,1},y[4] = {0,-1,1,0};
  Stack* pilha;

  nlin = getHeight(image);
  ncol = getWidth(image);

  origem = returnArray(image);
  m = malloc(nlin*ncol*sizeof(int));

  for (int i=0; i<ncol*nlin; i++)
      m[i] = 0;

  pilha = stackCreate();
  Pixel p, p_atual;

  for(int l=0;l<ncol;l++){
      for(int k=0;k<nlin;k++){
          p.x=l;
          p.y=k;
          if (origem[p.y*ncol+p.x]==1 && m[p.y*ncol+p.x]==0)
          {
              m[p.y*ncol+p.x]=label;
              aux=stackPush(pilha, p);
              while(stackSize(pilha)!=0)
              {
                  aux = stackTop(pilha, &p_atual);
                  aux = stackPop(pilha);

                  for(int i=0;i<4;i++)
                  {
                      p.x = p_atual.x+x[i];
                      p.y = p_atual.y+y[i];
                      if (origem[p.y*ncol+p.x]==1 && m[p.y*ncol+p.x]==0)
                      {
                          m[p.y*ncol+p.x]=label;
                          aux=stackPush(pilha, p);
                      }
                  }
              }
              label++;
          }
      }
  }

  for (int i=0; i<ncol*nlin; i++)
      insertMatriz(image,m[i],i);


  int fileFormat = checkFileFormat(destinefile);
  switch (fileFormat) {
    case 0:
      convertImageIntoText(image, destinefile);
    break;

    case 1:
      convertImageIntoBinary(image, destinefile);
    break;

    default:
      addFormat(destinefile, 1);
      convertImageIntoBinary(image, destinefile);
  }

  return 1;
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

int maze(Image *image, char* filenameimm) {
    int ans = 0;
    int *mat;

    int nlin = getHeight(image);
    int ncol = getWidth(image);

    struct ponto p;
    struct ponto cord;
    cord.x=0;
    cord.y=1;
    while(mat[cord.y*ncol] != 1)
        cord.y++;
    mat[cord.y*ncol+cord.x]=2;
    Stack* st;
    st=stack_create();
    ans=stack_push(st,cord);
    cord.x=1;
    ans=stack_push(st,cord);
    mat[cord.y*ncol+cord.x]=2;
    while(cord.x!=ncol-1){
        ans= stack_top(st,&p);
        cord.x = p.x;
        cord.y = p.y;
        if(mat[(cord.y-1)*ncol+cord.x]==1){
            cord.y--;
            ans=stack_push(st,cord);
            mat[cord.y*ncol+cord.x] = 2;
        }
        else if(mat[(cord.y+1)*ncol+cord.x]==1){
            cord.y++;
            ans=stack_push(st,cord);
            mat[cord.y*ncol+cord.x] = 2;
        }
        else if(mat[cord.y*ncol+cord.x-1]==1){
            cord.x--;
            ans=stack_push(st,cord);
            mat[cord.y*ncol+cord.x] = 2;
        }
        else if(mat[cord.y*ncol+cord.x+1]==1){
            cord.x++;
            ans=stack_push(st,cord);
            mat[cord.y*ncol+cord.x] = 2;
            }
        else{
            ans = stack_top(st,&p);
            cord.x = p.x;
            cord.y = p.y;
            mat[cord.y*ncol+cord.x] = 3;
            ans=stack_pop(st);
        }
    }

    while(stack_size(st) != 0){
        ans = stack_top(st,&p);
        printf("%d %d\n",p.y, p.x);
        ans=stack_pop(st);
    }

    ans = stack_free(st);


    return SUCCESS;
}
