
#include <stdio.h>
#include <stdlib.h>
#include "DataBase.h"
#include "string.h"
#include "time.h"
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
    string* ColumnName1 = NewString("Column1");
    string* ColumnName2 = NewString("Column2");
    string* ColumnName3 = NewString("Column3");

    DataBase* DB=NewDB(DBName);

    AddTable(DB, TableName);
    MoveToTable(DB,TableName);

    CheckColumnsNames(DB->CurrentTable);
    AddColumn(DB->CurrentTable,ColumnName1, TEXT);

    CheckColumnsNames(DB->CurrentTable);

    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);
    AddRow(DB->CurrentTable);
    AddColumn(DB->CurrentTable,ColumnName2, INTERGER);
    AddColumn(DB->CurrentTable,ColumnName3, REAL);

    CheckColumnsNames(DB->CurrentTable);


    return 0;
}
