/**
this header defines a DataBase. The main program will have have a array of this;
**/

#ifndef _DATABASE
#define _DATABASE
#include "string.h"
#include "table.h"


typedef struct _db_{
    string *name;            // DB name

    int number_of_tables;  //
    Table **Tables;
    //column **Columns;          // pointer to  the index column
} DataBase;

DataBase* NewDB(string *);
void AddTable(DataBase *SourceDB,string * Name);
void DeleteDB(DataBase*);

#endif // _DATABASE
