#include <stdio.h>
#include <stdlib.h>

#include "../ImageMap/ImageMap.h"

typedef struct node Node;
struct pixel {
    int x;
    int y;
    int direction; //0 - left 1 - top 2 - right 4 - bottom
};
typedef struct pixel Pixel;
typedef struct stack Stack;

Stack* stackCreate();
int stackPush(Stack* p, Pixel element);
int stackTop(Stack *st, Pixel *pt);
Pixel* stackPop(Stack* p);
void stackFree(Stack* p);
void stackPrint(Stack* p);
int stackSize(Stack* p);
Pixel* findPoints(Image* labyrinth);
