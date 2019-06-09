/**
this header defines a DataBase. The main program will have have a array of this;
current functions:
  DataBase* NewDB(string *Name);
  void AddTable(DataBase *SourceDB, string *Name);
  void DeleteDB(DataBase*);
  void GetTablesNames(DataBase*);
functions to add:
void MoveToTable(DataBase* SourceDB,string * Name);
**/

#ifndef _DATABASE
#define _DATABASE
#include "string.h"
#include "table.h"


typedef struct _db_{
    string *name;            // DB name

    int number_of_tables;  //
    Table **Tables;
    Table *CurrentTable;
    //column **Columns;          // pointer to  the index column
} DataBase;

DataBase* NewDB(string *Name);
void AddTable(DataBase *SourceDB, string *Name);
void DeleteDB(DataBase*);
void GetTablesNames(DataBase*);
void MoveToTable(DataBase* SourceDB,string * Name);

#endif // _DATABASE
