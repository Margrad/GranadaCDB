/**
Defines the functions for the DataBase
->NewColumn(string*);               //needs further testing -> possible change
->DeleteColumn(DataBase*);          //needs further testing
->SequentialEntryDelete(entry*);    //needs further testing
**/


#include "column.h"


column* NewColumn(string* name, type tipo){
    if(name == 0){
        printf("pointer to name string is null");
        return 0;
    }
    column *new_column;
    if((new_column=(column *)malloc(sizeof(column))) ==0 )
    {
        printf("Could not allocate memory for the column %s", name->text);
        return 0;
    }
    new_column->entry0=NULL;
    new_column->tipo=tipo;
    new_column->name=copy_string(name);
    return new_column;
}

void DeleteColumn(column* Coluna){
    if(Coluna->entry0!=NULL){
        SequentialEntryDelete(Coluna->entry0);}
    if(Coluna->name!=0)
        DeleteString(Coluna->name);
    if(Coluna!=0)
        free(Coluna);
}
void SequentialEntryDelete(entry *entry0){
    if(entry0->next_entry !=0)
        SequentialEntryDelete(entry0->next_entry);
    DeleteEntry(entry0);
}

