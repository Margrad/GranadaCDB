#include "search.h"

list* ColumnSearch(column *Column,void* data, SearchTypes WHAT){
list* PossitiveResults = NewList();
int i;
// Options on WHAT
// DEFAULT, ABSOLUTE,PARTIAL,CASE_SENSITIVE,HISTORIC
switch(Column->tipo){
    case (INTERGER):
        {
            switch(WHAT)
                {
                    case(DEFAULT):
                        {
                            int searched_data = *(int *)data;
                            for(i=0;i<Column->number_of_entries;i++)
                                {
                                    if ( Column->entries[i]->current_entry->value == NULL)
                                        {
                                            continue;
                                        }
                                    int current_data= *(int *)Column->entries[i]->current_entry->value;
                                    if( current_data == searched_data)
                                    {
                                         add_to_list(PossitiveResults,i);
                                    }
                                }
                            return PossitiveResults;
                        }
                    case(HISTORIC):
                        {
                            int searched_data = *(int *)data;
                            for(i=0;i<Column->number_of_entries;i++)
                                {
                                    timed_entry * current_entry = Column->entries[i]->current_entry;
                                    while (current_entry != NULL)
                                        {
                                            if ( Column->entries[i]->current_entry->value == NULL)
                                            {
                                                continue;
                                            }
                                            int current_data= *(int *)current_entry->value;
                                            if( current_data == searched_data)
                                                {
                                                     add_to_list(PossitiveResults,i);
                                                     break;
                                                }
                                            current_entry=current_entry->next;
                                        }
                                }
                            return PossitiveResults;
                        }
                    case(ABSOLUTE):{}
                    case(PARTIAL):{}
                    case(CASE_SENSITIVE):
                        {
                            printf("Option not supported on column %s", Column->name->text);
                            return PossitiveResults;
                        }

                }
        }
    // Options on WHAT
    // DEFAULT, ABSOLUTE,PARTIAL,CASE_SENSITIVE,HISTORIC
    case (REAL):
        {
            switch(WHAT)
                {
                    case(DEFAULT):
                        {
                            double searched_data = *(double *)data;
                            for(i=0;i<Column->number_of_entries;i++)
                                {
                                   if ( Column->entries[i]->current_entry->value == NULL)
                                        {
                                            continue;
                                        }
                                    double current_data= *(double *)Column->entries[i]->current_entry->value;
                                    if( current_data == searched_data)
                                    {
                                         add_to_list(PossitiveResults,i);
                                    }
                                }
                            return PossitiveResults;
                        }
                    case(HISTORIC):
                        {
                            double searched_data = *(double *)data;
                            for(i=0;i<Column->number_of_entries;i++)
                                {
                                    timed_entry * current_entry = Column->entries[i]->current_entry;
                                    while (current_entry != NULL)
                                        {
                                        if ( Column->entries[i]->current_entry->value == NULL)
                                            {
                                                continue;
                                            }
                                            double current_data= *(double *)current_entry->value;
                                            if( current_data == searched_data)
                                                {
                                                     add_to_list(PossitiveResults,i);
                                                     break;
                                                }
                                            current_entry=current_entry->next;
                                        }
                                }
                            return PossitiveResults;
                        }
                    case(ABSOLUTE):{}
                    case(PARTIAL):{}
                    case(CASE_SENSITIVE):
                        {
                            printf("Option not supported on column %s", Column->name->text);
                            return PossitiveResults;
                        }

                }
        }
    case (TEXT):
        {
            switch(WHAT)
                {
                    case(DEFAULT):{} // Same as PARTIAL
                    case(PARTIAL):
                        {

                        }
                    case(HISTORIC):
                        {

                        }
                    case(ABSOLUTE):
                        {

                        }
                    case(CASE_SENSITIVE):
                        {

                        }
                }
        }
    }

    return PossitiveResults;
}
