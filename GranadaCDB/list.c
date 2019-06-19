#include "list.h"

void add_to_list( list* lista, int value){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value=value;
    new_node->next=NULL;
    if(lista->head == NULL)
        lista->head = new_node;
    lista->tail=new_node;
}

list* NewList(){
    list* lista = (list *)malloc(sizeof(list));
    lista->head=NULL;
    lista->tail=NULL;
    return lista;
}
