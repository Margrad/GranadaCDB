
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

///
// DEFAULT -> used for search of not interesting stuff, looks for
//            numbers in case of INT or REAL and PARTIAL on strings
// ABSOLUTE ->search for the exact string or value
// PARTIAL -> search of a piece of string
// CASE_SENSITIVE -> the search is case sensitive
// HISTORIC -> Search the historic records, always case sensitive
typedef enum{DEFAULT, ABSOLUTE,PARTIAL,CASE_SENSITIVE,HISTORIC}SearchTypes;

list* ColumnSearch(column *Column,void* data, SearchTypes WHAT);



#endif // SEARCH
