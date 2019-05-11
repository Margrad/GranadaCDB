

#include "table.h"
void DeleteTable(Table *table){
    int i;
    for(i=0;i<table->number_of_columns;i++){
        DeleteColumn(table->Columns[i]);
    }
}
