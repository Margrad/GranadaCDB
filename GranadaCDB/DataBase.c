/**
Defines the functions for the DataBase
->NewDB(string*);           //needs further testing RANDOM ISUES solved
->DeleteDB(DataBase*);      //needs further testing RANDOM ISUES solved
**/
#include <stdio.h>
#include <stdlib.h>
#include "DataBase.h"
#include "codify.h"

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
    //check if the Table already exists
    int numbTabs=SourceDB->number_of_tables;
    int i=0;
    for(i=0;i<numbTabs;i++){
        if(bcompare_strings(SourceDB->Tables[i]->name,Name)){
            printf("Table %s already exists. Aborting table creation\n",Name->text);
            return;
        }
      }
    //
    if(SourceDB->Tables!= NULL)
    {
         SourceDB->Tables = (Table **) realloc(SourceDB->Tables, sizeof(Table *)*(SourceDB->number_of_tables+1));
    }
    else
    {
        SourceDB->Tables = (Table **) malloc( sizeof(Table *)*(SourceDB->number_of_tables+1));
    }
    if(SourceDB->Tables == NULL){
        printf("Failed to allocate memory for a new table on %s",SourceDB->name->text);
        return;
    }
    SourceDB->Tables[SourceDB->number_of_tables] = NewTable(copy_string(Name));//(Table *)malloc(sizeof(Table));
    //SourceDB->Tables[SourceDB->number_of_tables]->name=copy_string(Name);
    SourceDB->number_of_tables++;
    printf("%s created sucefully!\n", Name->text);
}

  void GetTablesNames(DataBase* SourceDB){
      int numbTabs=SourceDB->number_of_tables;
      if(numbTabs == 0){
        printf(">no tables present");
        return;
      }
      printf("Tables present:\n");
      int i=0;
      for(i=0;i<numbTabs;i++){
        printf(" %s\n",SourceDB->Tables[i]->name->text);
      }
  }

void MoveToTable(DataBase* SourceDB,string * Name){
    int numbTabs=SourceDB->number_of_tables;
    int i=0;
    for(i=0;i<numbTabs;i++){
        if(bcompare_strings(SourceDB->Tables[i]->name,Name)){
            SourceDB->CurrentTable = SourceDB->Tables[i];
            printf("Moving to Table %s\n",Name->text);
            return;
        }
      }
    printf("Cannot find Table %s, current Table doesn't change\n",Name->text);
    return;
}
