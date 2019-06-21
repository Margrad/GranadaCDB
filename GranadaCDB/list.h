/***
    void add_to_list( list* lista, int value);
    list* NewList();
***/
#include <stdlib.h>
#include <stdio.h>
#ifndef LISTA
#define LISTA

typedef struct _NODE_{
    int value;
    struct _NODE_ *next;
} Node;

typedef struct _LIST_{
     Node* head;
     Node* tail;
}list;

void add_to_list( list* lista, int value);
list* NewList();

#endif //LISTA
