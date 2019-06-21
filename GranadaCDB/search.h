
/***
    void add_to_list( list* lista, int value);
    list* ColumnSearch(column *Column,void* data);
***/
#include <stdlib.h>
#include <stdio.h>
#include "table.h"
#include "list.h"
#ifndef SEARCH
#define SEARCH

// ABSOLUTE ->search for the exact string or value
// PARTIAL -> search of a piece of string
// CASE_SENSITIVE -> the search is case sensitive
// HISTORIC -> Search the historic records, always case sensitive
typedef enum{ABSOLUTE,PARTIAL,CASE_SENSITIVE,HISTORIC}SearchTypes;

list* ColumnSearch(column *Column,void* data, SearchTypes WHAT);



#endif // SEARCH
