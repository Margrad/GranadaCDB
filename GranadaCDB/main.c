
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
    string* ColumnName2 = NewString("Texts");



    DataBase* DB = NewDB(DBName);

    AddTable(DB, TableName);
    MoveToTable(DB, TableName);

    CheckColumnsNames(DB->CurrentTable);
    AddColumn(DB->CurrentTable, ColumnName1, INTERGER);
    AddColumn(DB->CurrentTable, ColumnName2, TEXT);

    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);

    int tet = 123;

    EditEntry(INTERGER,DB->CurrentTable->Columns[1]->entries[0],&tet);
    EditEntry(INTERGER,DB->CurrentTable->Columns[1]->entries[2],&tet);
    tet = 321;
    EditEntry(INTERGER,DB->CurrentTable->Columns[1]->entries[1],&tet);
    printf("populated table\n");

    int toFind = 123;
    list *Found = ColumnSearch(DB->CurrentTable->Columns[1],&toFind,DEFAULT);

    printf("Found the values in: ");
    FOREACH(nodezsdf,Found){
        printf("%d ",nodezsdf->value);
    }




    string* texto_para_db1=NewString("Data de teste1");
    string* texto_para_db2=NewString("Data de teste2");
    EditEntry(INTERGER,DB->CurrentTable->Columns[2]->entries[0],texto_para_db1);
    EditEntry(INTERGER,DB->CurrentTable->Columns[2]->entries[1],texto_para_db1);
    EditEntry(INTERGER,DB->CurrentTable->Columns[2]->entries[2],texto_para_db1);

    EditEntry(INTERGER,DB->CurrentTable->Columns[2]->entries[0],texto_para_db2);
    EditEntry(INTERGER,DB->CurrentTable->Columns[2]->entries[1],texto_para_db2);
    EditEntry(INTERGER,DB->CurrentTable->Columns[2]->entries[2],texto_para_db2);
    printf("\nSaving column: %s\n",DB->CurrentTable->Columns[2]->name->text);

    save_column_to_hd(DB->CurrentTable->Columns[2]);
    return 0;
}
