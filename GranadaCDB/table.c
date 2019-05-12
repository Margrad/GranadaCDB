

#include "table.h"
void DeleteTable(Table *table){
    int i;
    for(i=0;i<table->number_of_columns;i++){
        DeleteColumn(table->Columns[i]);
    }
    free(table);
}
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


Table * NewTable(string * name){
/*
allocate memory for table
allocate memory for Columns array
get a column for indexs
set number of rows and columns
*/
    if(name == NULL){
        printf("pointer to name string is null");
        return 0;
    }
    Table *new_table;
    if((new_table=(Table *)malloc(sizeof(Table))) == NULL )
    {
        printf("Could not allocate memory for the table %s", name->text);
        return 0;
    }
    new_table->Columns=(column **) malloc(sizeof(column *) *1);
    column* index = (column *) malloc(sizeof(column ));

    if ( new_table->Columns == NULL || index == NULL){
            free(new_table->Columns);
            free(index);
            free(new_table);
            printf("Failed to allocate memory for initial index Columns of %s", name->text);
            return 0;
    }

    new_table->Columns[0]=index;

    new_table->number_of_columns=0;
    new_table->number_of_rows=0;

    return new_table;
}
