
#include <stdio.h>
#include <stdlib.h>
#include "DataBase.h"
#include "string.h"
#include "list.h"
#include "time.h"
#include "search.h"
#define DEBUG_STR
/**
** This main.c file is used for testing purposes
** I need to create the basic structures and functions
** I need to make it server/client
** I need to make it searchable
** I need to make it multi threat
**/

int main(){

    string* DBName = NewString("DB");
    string* TableName = NewString("Tabela");
    string* ColumnName1 = NewString("Idade");


    DataBase* DB=NewDB(DBName);

    AddTable(DB, TableName);
    MoveToTable(DB,TableName);

    CheckColumnsNames(DB->CurrentTable);
    AddColumn(DB->CurrentTable, ColumnName1, INTERGER);
    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);

    int tet = 123;
    EditEntry(INTERGER,DB->CurrentTable->Columns[1]->entries[0],&tet);
    EditEntry(INTERGER,DB->CurrentTable->Columns[1]->entries[2],&tet);
    EditEntry(INTERGER,DB->CurrentTable->Columns[1]->entries[3],&tet);
    EditEntry(INTERGER,DB->CurrentTable->Columns[1]->entries[4],&tet);
    tet = 321;
    EditEntry(INTERGER,DB->CurrentTable->Columns[1]->entries[1],&tet);
    printf("populated table\n");

    int toFind = 123;
    list *Found = ColumnSearch(DB->CurrentTable->Columns[1],&toFind,DEFAULT);

    printf("Found the values in: ");
    Node *node = Found->head;
    while(node != NULL){
        printf("%d ",node->value,node->next);
        node=node->next;
    }


    return 0;
}
