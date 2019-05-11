/**
Defines the functions for the DataBase
->NewDB(string*);           //needs further testing RANDOM ISUES solved
->DeleteDB(DataBase*);      //needs further testing RANDOM ISUES solved
->AddColumn();              //needs testing
->AddRow();                 //not started
**/
#include <stdio.h>
#include <stdlib.h>
#include "DataBase.h"
//#include <time.h>
//#include "entry.h"
//#include "column.h"
#include "string.h"

DataBase* NewDB(string *name){
    if(name == 0){
        printf("pointer to name string is null");
        return NULL;
    }
    DataBase *DB;
    if ((DB = (DataBase *)malloc(sizeof(DataBase))) == 0)
    {
        printf("fail to allocate memory for DataBase");
        return NULL;
    }
    if ((DB->Tables=(Table **)malloc(sizeof(Table *)))==0)
    {
        printf("fail to allocate memory for Column");
        return 0;
    }
    DB->name=copy_string(name);
    DB->number_of_tables=0;

    return DB;
}


void DeleteDB(DataBase* DB){
    int i;
    if(DB == NULL) return;
    for(i=0;i<DB->number_of_tables;i++){
        DeleteTable(DB->Tables[i]);}
    if(DB->Tables != 0)
        free(DB->Tables);

    DeleteString(DB->name);
    free(DB);
}

void AddTable(DataBase *SourceDB,string * Name){
    SourceDB->Tables[SourceDB->number_of_tables] = (Table *)malloc(sizeof(Table));
    SourceDB->Tables[SourceDB->number_of_tables]->name=copy_string(Name);
    SourceDB->number_of_tables++;
}
