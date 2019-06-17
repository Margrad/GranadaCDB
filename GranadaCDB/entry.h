/**
This header defines the entry for a column
**/
#ifndef _ENTRY
#define _ENTRY
#include "string.h"
#include <time.h>

typedef enum {TEXT, INTERGER, REAL} type;

typedef struct _timed_entry_{
    time_t change_time;         // time when this entry was created
    struct _timed_entry_ *next;                 // previows entry from this entry(null will be the first created)
    void *value;                // actual value in this timed_entry
} timed_entry;

typedef struct _Entry_{
    char lock;
    timed_entry *current_entry; // when edited the DB will save the last entry as a pointer in the latest entry to allow for search in time;
    string *dif_search;    // created from the current_entry to make search without case differentiation
    //struct _Entry_ *next_entry;
} entry;

entry* NewEntry(type tipo, void* data);
void EditEntry(type,entry*,void*);
void DeleteEntry(entry *Entry);
#endif // _ENTRY
