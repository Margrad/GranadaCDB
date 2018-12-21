/**
Defines the functions for the DataBase
->entry* NewEntry(type,void*);          //needs further testing ->lacks complex recognition
->void EditEntry(type, entry*,void*);   //needs further testing ->lacks complex recognition
->void DeleteEntry(entry*);             //needs further testing
**/
#include <time.h>
#include "entry.h"
#include <stdlib.h>
#include <stdio.h>
#include "column.h"
#include "string.h"


void EditEntry(type tipo, entry* Entry, void* data)
{
    if(Entry->lock == 1)
    {
        printf("Entry currently locked, please try again later");
        return;
    }
    Entry->lock=1;
    timed_entry *temp_Entry;
    if((temp_Entry=(timed_entry*)malloc(sizeof(timed_entry))) == NULL){
                    printf("failed to allocate memory for time_entry");
                    return ;
            }  //and differential search
    switch(tipo){
        case(TEXT):{
            DeleteString(Entry->dif_search);
            if((Entry->dif_search=(string*)malloc(sizeof(string))) == NULL){
                    printf("failed to allocate memory for differential string");
                    return ;
            }  //and differential search
            temp_Entry->next=Entry->current_entry;
            Entry->current_entry=temp_Entry;
            temp_Entry->value=data;             //get data to current_entry->data
            temp_Entry->change_time=time(NULL);     //get time to current_entry->time
            Entry->dif_search=lower_case(data);  //get lower_case to dif_search->data and ignor the remaining sets in this struck
            Entry->lock=0;
            break;
        };
        case(INTERGER):{
            temp_Entry->next=Entry->current_entry;
            Entry->current_entry=temp_Entry;
            temp_Entry->value=data;             //get data to current_entry->data
            temp_Entry->change_time=time(NULL);     //get time to current_entry->time
            Entry->lock=0;
            break;
            };
        case(REAL):{
            temp_Entry->next=Entry->current_entry;
            Entry->current_entry=temp_Entry;
            temp_Entry->value=data;             //get data to current_entry->data
            temp_Entry->change_time=time(NULL);     //get time to current_entry->time
            Entry->lock=0;
            break;
            };
        default:{printf("Cannot initialize entry:");return ;};
    }
}

entry* NewEntry(type tipo, void* data){
    entry *newEntry;
    timed_entry *temp_Entry;
    newEntry = (entry*)malloc(sizeof(entry));
    if( data == NULL)
        {
            switch(tipo){
            case(TEXT):{
                newEntry->current_entry=(timed_entry*)malloc(sizeof(timed_entry));//allocate memory for current entry
                newEntry->dif_search=NULL;  //and differential search
                newEntry->next_entry=NULL;
                temp_Entry = newEntry->current_entry;    //get time to current_entry->time
                temp_Entry->next = NULL;         //get lower_case to dif_search->data and ignor the remaining sets in this struck
                newEntry->lock=0;
                break;
            };
            case(INTERGER):{
                newEntry->current_entry=(timed_entry*)malloc(sizeof(timed_entry));//allocate memory for current entry
                newEntry->dif_search=NULL;  //intergers are nod differentiated
                temp_Entry = newEntry->current_entry;
                temp_Entry->value=NULL;     //get time to current_entry->time
                temp_Entry->next = NULL;               //set current_entry->next to void
                newEntry->lock=0;
                break;
                };
            case(REAL):{
                newEntry->current_entry=(timed_entry*)malloc(sizeof(timed_entry));//allocate memory for current entry
                newEntry->dif_search=NULL;  //intergers are nod differentiated
                temp_Entry = newEntry->current_entry;
                temp_Entry->value=NULL;             //get data to current_entry->data
                temp_Entry->change_time=time(NULL);     //get time to current_entry->time
                temp_Entry->next = NULL;               //set current_entry->next to void
                newEntry->lock=0;
                break;
                };
            };
            return newEntry;
        }

    switch(tipo){
        case(TEXT):{
            newEntry->current_entry=(timed_entry*)malloc(sizeof(timed_entry));//allocate memory for current entry
            newEntry->dif_search=(string*)malloc(sizeof(string));  //and differential search
            newEntry->next_entry=NULL;
            temp_Entry = newEntry->current_entry;
            temp_Entry->value=copy_string(data);             //get data to current_entry->data
            temp_Entry->change_time=time(NULL);     //get time to current_entry->time
            temp_Entry->next = NULL;               //set current_entry->next to void
            newEntry->dif_search=lower_case(data);  //get lower_case to dif_search->data and ignor the remaining sets in this struck
            newEntry->lock=0;
            break;
        };
        case(INTERGER):{
            newEntry->current_entry=(timed_entry*)malloc(sizeof(timed_entry));//allocate memory for current entry
            newEntry->dif_search=NULL;  //intergers are nod differentiated
            temp_Entry = newEntry->current_entry;
            int *ptr_data=(int *)malloc(sizeof(int));
            *ptr_data=*(int *)data;
            temp_Entry->value=ptr_data;             //get data to current_entry->data
            temp_Entry->change_time=time(NULL);     //get time to current_entry->time
            temp_Entry->next = NULL;               //set current_entry->next to void
            newEntry->lock=0;
            break;
            };
        case(REAL):{
            newEntry->current_entry=(timed_entry*)malloc(sizeof(timed_entry));//allocate memory for current entry
            newEntry->dif_search=NULL;  //intergers are nod differentiated
            temp_Entry = newEntry->current_entry;
            double *ptr_data=(double *)malloc(sizeof(double));
            *ptr_data=*(double *)data;
            temp_Entry->value=ptr_data;             //get data to current_entry->data
            temp_Entry->change_time=time(NULL);     //get time to current_entry->time
            temp_Entry->next = NULL;               //set current_entry->next to void
            newEntry->lock=0;
            break;
            };
        default:{printf("Cannot initialize entry:");return 0;};
    }
return newEntry;
}

void DeleteTimedEntry(timed_entry *timeEntry){
    if(timeEntry->next!=0)
        DeleteTimedEntry(timeEntry->next);
    free(timeEntry->value);
    free(timeEntry);
}

void DeleteEntry(entry *Entry)
{
    if(Entry->current_entry!=NULL)
        DeleteTimedEntry(Entry->current_entry);
    if(Entry->dif_search!=NULL)
        DeleteString(Entry->dif_search);
}


