#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct Matriz {
  int next;
  int i;
  int j;
  int nextEach;
  int rows;
  int columns;
  int *data;
};

Matriz* createMatriz(int rows, int columns) {
  Matriz *matriz = malloc(sizeof(struct Matriz));
  matriz->data = malloc(sizeof(int) * (rows * columns));
  matriz->rows = rows;
  matriz->columns = columns;
  matriz->next = 0;
  matriz->i = 0;
  matriz->j = 0;
  matriz->nextEach = 0;
  return matriz;
}

void freeMatriz(Matriz *matriz) {
  free(matriz->data);
  free(matriz);
}

int insertMatriz(Matriz *matriz, int num, int pos) {
  if (matriz == NULL)
    return -1;

  int *pointer = (matriz->data)+pos;

  *pointer = num;

  return 0;
}

int *returnArray(Matriz *matriz) {
  if (matriz == NULL)
    return NULL;

  return matriz->data;
}

int getColumns(Matriz *matriz) {
  if (matriz == NULL)
    return -1;

  return matriz->columns;
}

int getRows(Matriz *matriz) {
  if (matriz == NULL)
    return -1;

  return matriz->rows;
}

int printMatriz(Matriz *matriz) {
  if (matriz == NULL)
    return -1;

  int i, j;
  int pos;
  int *pointer;
  for (i = 0; i < matriz->rows; i++) {
    for (j = 0; j < matriz->columns; j++) {
      pos = j * matriz->rows + i;
      pointer = (matriz->data)+pos;
      printf("%i\t", *pointer);

      if (j == matriz->columns)
        printf("\n");
    }
  }

  return 0;
}

int printOne(Matriz *matriz, int pos) {
  if (matriz == NULL)
    return -1;

  int *pointer = matriz->data+pos;
  printf("%i\n", *pointer);
  return 0;
}

int replaceMatriz(Matriz *matriz, int base) {
  int *number;
  int i;
  int j;
  int pos;
  for (i = 0; i < matriz->rows; i++) {
    for (j = 0; j < matriz->columns; j++) {
      pos = j * matriz->rows + i;
      number = matriz->data+pos;
      if (*number < base)
        *number = 0;
      else
        *number = 1;
    }
  }

  return 0;
}

int *getLine(Matriz *matriz, int line) {
  int width = getColumns(matriz);
  int *lineVector = malloc(sizeof(int) * width);
  int *posLineVector;
  int pos;
  for (int j = 0; j < matriz->columns; j++) {
    pos = j * matriz->rows + line;
    posLineVector = lineVector + j;
    posLineVector = matriz->data+pos;
  }

  return lineVector;
}

int getEachElementInOrder(Matriz *matriz) {
  if (matriz == NULL)
    return -1;

  int pos = matriz->nextEach;
  if (matriz->nextEach < matriz->rows*matriz->columns)
    matriz->nextEach++;
  if (matriz->nextEach == matriz->rows*matriz->columns)
    matriz->nextEach = 0;
  return *(matriz->data+pos);
}


int getElementInPoint(Matriz *matriz, int pos) {
  return *(matriz->data+pos);
}
