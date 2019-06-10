
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

    DataBase* DB=NewDB(DBName);

    AddTable(DB, TableName);
    AddTable(DB, DBName);
    MoveToTable(DB,TableName);



    CheckColumnsNames(DB->CurrentTable);



    return 0;
}
