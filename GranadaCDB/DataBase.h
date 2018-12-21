/**
this header defines a DataBase. The main program will have have a array of this;
**/

#ifndef _DATABASE
#define _DATABASE
#include "column.h"
#include "string.h"

typedef struct _db_{
    string *name;            // DB name
    int number_of_columns;  //
    int number_of_entries;  //
    column **Columns;          // pointer to  the index column
} DataBase;

DataBase* NewDB(string *);
void AddColumn(DataBase *,string *, type);
void DeleteDB(DataBase*);

#endif // _DATABASE
