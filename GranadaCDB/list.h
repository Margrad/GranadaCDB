/***
    void add_to_list( list* lista, int value);
    list* NewList();
***/
#include <stdlib.h>
#include <stdio.h>
#ifndef LISTA
#define LISTA
#define FOREACH(node_,lista) \
        for(Node* node_=lista->head;node_!=NULL;node_=node_->next)


typedef struct _NODE_{
    int value;
    struct _NODE_ *next;
} Node;

typedef struct _LIST_{
     Node* head;
     Node* tail;
}list;

list* NewList();

void add_to_list( list* lista, int value);

#endif //LISTA
