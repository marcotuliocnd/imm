#include "DinamicStack.h"

typedef struct node Node;

struct stack {
    Node *head;
    int size;
};

struct node {
    struct ponto data;
    Node *next;
};

Stack* stack_create(){
    Stack *st;
    st = malloc(sizeof(Stack));
    if (st != NULL) {
       st->head = NULL;
       st->size = 0;
    }
    return st;
}

int stack_free(Stack *st){
   if (st == NULL)
      return INVALID_NULL_POINTER;
    Node *p;
    p = st->head;
    while (p != NULL){
        st->head = p->next;
        free(p);
        st->size-=1;
        p = st->head;
    }
    free(st);
    return SUCCESS;
}

int stack_push(Stack *st, struct ponto pt){
    if (st == NULL)
        return INVALID_NULL_POINTER;
    Node *node;
    node = malloc(sizeof(Node));
    if (node == NULL)
        return OUT_OF_MEMORY;
    node->data=pt;
    node->next=NULL;
    if(st->size==0)
        st->head=node;
    else{
        Node *p=st->head;
        while(p->next!=NULL)
            p=p->next;
        p->next=node;
    }
    st->size+=1;
    return SUCCESS;
}

int stack_pop(Stack *st){
    if (st == NULL)
        return INVALID_NULL_POINTER;
    if (st->size==0)
        return ELEM_NOT_FOUND;
    if (st->size == 1){
        free(st->head);
        st->head = NULL;
    } else {
        Node *p=st->head;
        while(p->next->next!=NULL)
            p=p->next;
        free(p->next);
        p->next=NULL;
    }
    st->size-=1;
    return SUCCESS;
}

int stack_top(Stack *st, struct ponto *pt){
    if(st==NULL)
        return INVALID_NULL_POINTER;
    if(st->head==NULL)
        return ELEM_NOT_FOUND;
    Node *p=st->head;
    while(p->next!=NULL)
        p=p->next;
    *pt=p->data;
    return SUCCESS;
}

int stack_empty(Stack* st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    return (st->size == 0);
}

int stack_size(Stack *st){
    if (st == NULL)
        return INVALID_NULL_POINTER;
    else
        return st->size;
}