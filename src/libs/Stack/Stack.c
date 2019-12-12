#include "./Stack.h"
#include "../ImageMap/ImageMap.h"

struct pixel {
    int x;
    int y;
    int direction; //0 - left 1 - top 2 - right 4 - bottom
};

struct node {
    Pixel pixel;
    struct node* next;
};

struct stack {
    Node* top;
    int quantity;
};

Stack* stackCreate(){
    Stack* saida = (Stack *)malloc(sizeof(Stack));
    saida->quantity=0;
    saida->top=NULL;
    return saida;
}

void stackFree(Stack* p){
    Node* aux = p->top;
    Node* old;
    while(aux != NULL){
        old = aux;
        aux = aux->next;
        free(old);
    }
    free(p);
}

int stackPush(Stack* p, Pixel element){
    Node* node = (Node *)malloc(sizeof(Node));
    node->pixel = element;

    node->next=p->top;
    p->top=node;
    p->quantity++;
    return 1;
}

Pixel* stackPop(Stack* p){
    Node* temp = p->top;
    if(temp != NULL){
        Pixel* out = (Pixel *)malloc(sizeof(Pixel));
        *out = temp->pixel;
        p->top = temp->next;
        p->quantity--;
        free(temp);
        return out;
    }
    return NULL;
}

int stackSize(Stack* p){
    return p->quantity;
}