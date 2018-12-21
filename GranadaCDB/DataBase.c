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
#include <time.h>
#include "entry.h"
#include "column.h"
#include "string.h"

DataBase* NewDB(string *name){
    if(name == 0){
        printf("pointer to name string is null");
        return 0;
    }
    DataBase *DB;
    string index;
    char text[]="Index";
    index.text=text;
    index.len=getLenght(text);
    if ((DB = (DataBase *)malloc(sizeof(DataBase))) == 0)
    {
        printf("fail to allocate memory for DataBase");
        return 0;
    }
    if ((DB->Columns=(column**)malloc(sizeof(column *)))==0)
    {
        printf("fail to allocate memory for Column");
        return 0;
    }
    DB->name=copy_string(name);
    DB->number_of_columns=1;
    DB->number_of_entries=0;
    DB->Columns[0]=NewColumn(&index,INTERGER); // create the Index column column
    return DB;
}

void AddColumn(DataBase *DB, string *name, type TIPO){
    if(name == 0){
        printf("pointer to name string is null");
        return;
    }
    DB->Columns=(column**)realloc(DB->Columns,sizeof(column *)*(DB->number_of_columns+1));
    DB->Columns[DB->number_of_columns]=NewColumn(name,TIPO);
    DB->number_of_columns++;
    int i;

    entry *temp=DB->Columns[DB->number_of_columns-1]->entry0;
    for(i=1;i<DB->number_of_entries;i++)
    {
        temp->next_entry=NewEntry(TIPO, NULL);
        temp=temp->next_entry;
    }

}

void DeleteDB(DataBase* DB){
    int i;
    if(DB == NULL) return;
    for(i=0;i<DB->number_of_columns;i++){
        DeleteColumn(DB->Columns[i]);}
    if(DB->Columns != 0)
        free(DB->Columns);

    DeleteString(DB->name);
    free(DB);
}
