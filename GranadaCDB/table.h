/***
Currently have:
    column* NewColumn(string* name,type tipo);
    void DeleteColumn(column*);
    void SequentialEntryDelete(entry *entry0);
    Table * NewTable(string * name);
    void DeleteTable(Table *table);
Currently needs:
    void CheckColumnsNames(Table *table);
Must have a
name
arrey to all columns
arrey to all index entries
number of rows
number of columns

***/
#ifndef _TABLE
#define _TABLE
#include <stdlib.h>
#include <stdio.h>
#include "entry.h"

typedef struct _Column_{
    string *name;    // column name
    type tipo;      // type of value in this column
    entry *entry0;  // pointer to the first value in this column
    entry *last_entry;  // new variable to make it easier the creation of new rows
} column;

typedef struct _table_{
    string *name;           // DB name

    int number_of_rows;     //
    int number_of_columns;  //

    column **Columns;       // array of pointers to columns
} Table;


column* NewColumn(string* name,type tipo);
void DeleteColumn(column*);
void SequentialEntryDelete(entry *entry0);

Table * NewTable(string * name);
void CheckColumnsNames(Table *table);
void DeleteTable(Table *table);

#endif //_TABLE
