#include <stdio.h>
#include <stdlib.h>

#include "../ImageMap/ImageMap.h"

typedef struct node Node;

typedef struct pixel Pixel;
typedef struct stack Stack;

Stack* stackCreate();
int stackPush(Stack* p, Pixel element);
Pixel* stackPop(Stack* p);
void stackFree(Stack* p);
void stackPrint(Stack* p);
int stackSize(Stack* p);
Pixel* findPoints(Image* labyrinth);