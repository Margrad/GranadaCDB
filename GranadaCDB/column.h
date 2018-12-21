/**
this header defines a column for the DB
**/
#ifndef _COLUMN
#define _COLUMN
#include "entry.h"
#include <time.h>
#include "entry.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct _Column_{
    string *name;    // column name
    type tipo;      // type of value in this column
    entry *entry0;  // pointer to the first value in this column
    entry *last_entry;  // new variable to make it easier the creation of new rows
} column;

column* NewColumn(string* name,type tipo);
void DeleteColumn(column*);
void SequentialEntryDelete(entry *entry0);
#endif // _COLUMN
