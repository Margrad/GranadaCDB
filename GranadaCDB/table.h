/***
Must have a
name
index arrey
number of rows
number of columns

***/
#ifndef _TABLE
#define _TABLE
#include "column.h"


typedef struct _table_{
    string *name;           // DB name

    int number_of_rows;     //
    int number_of_columns;  //

    column **Columns;       // sequence of columns
} Table;


void DeleteTable(Table *table);
#endif //_TABLE
