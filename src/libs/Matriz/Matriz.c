#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct Matriz {
  int next;
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
  return matriz;
}

void freeMatriz(Matriz *matriz) {
  free(matriz->data);
  free(matriz);
}

int insertMatriz(Matriz *matriz, int num) {
  if (matriz == NULL)
    return -1;

  int pos = matriz->next;
  int *pointer = (matriz->data)+pos;

  *pointer = num;
  matriz->next++;
  return 0;
}

int printMatriz(Matriz *matriz) {
  if (matriz == NULL)
    return -1;

  int i, j;
  int pos;
  for (i = 0; i < matriz->rows; i++) {
    for (j = 0; j < matriz->columns; j++) {
      pos = j * matriz->rows + i;
      printf("%i\t", *((matriz->data)+pos));

      if (j == matriz->columns)
        printf("\n");
    }
  }

  return 0;
}
