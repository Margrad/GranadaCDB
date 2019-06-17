/***
Currently have:
    support function:
        column* NewColumn(string* name,type tipo);
    void DeleteColumn(column*);
    void SequentialEntryDelete(entry *entry0);
    Table * NewTable(string * name);
    void DeleteTable(Table *table);
    void CheckColumnsNames(Table *table);
    void AddColumn(Table *table, string *name);
    void AddRow(Table *table);
Currently needs:

***/
#ifndef _TABLE
#define _TABLE
#include <stdlib.h>
#include <stdio.h>
#include "entry.h"

typedef struct _Column_{
    string *name;           // column name
    type tipo;              // type of value in this column
    entry **entries;        // array of entry pointers
    int number_of_entries;  //keep check of the number of entries
} column;

typedef struct _table_{
    string *name;           // Table name

    int number_of_rows;     //
    int number_of_columns;  //

    column **Columns;       // array of pointers to columns
} Table;


Table * NewTable(string * name);
void DeleteTable(Table *table);


column* NewColumn(string* name,type tipo);
void AddColumn(Table *table, string *name, type Tipo);
void CheckColumnsNames(Table *table);
void DeleteColumn(column*);

void AddRow(Table *table);



#endif //_TABLE
