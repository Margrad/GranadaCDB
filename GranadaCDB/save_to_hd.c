#include "save_to_hd.h"


int save_db_to_hd(DataBase* DB){
/**
create folder with name of DB
 ->create a db_setup file with name of tables
   ->create folders with name of tables
    ->create file table_setup with columns names, column types and number of rows.
      -> create folders with name of columns
        -> save columns in the respective folders
**/

return 1;
}
int save_column_to_hd(column* Col_to_save){
/**
save the column in a file with column name has it's name
->entry0->timed00->timed01->entry1->timed1...
->format:"data0":"time00":"data0":"timer01"::"data1":"timer10"...
**/
int i;
FILE* savefile;

string* FileName=concat_strings(Col_to_save->name,NewString(".gcdb"));

savefile = fopen(FileName->text,"wb");


switch (Col_to_save->tipo) {
    case (TEXT):{
        printf("number of entries: %d\n",Col_to_save->number_of_entries);
        for(i=0;i<Col_to_save->number_of_entries;i++){
            printf("current entry: %d",i);
            printf(":");
            fprintf(savefile,":");
            timed_entry* current_entry=Col_to_save->entries[i]->current_entry;
            while(current_entry!=NULL){
                printf(":");
                fprintf(savefile,":");
                string *data=(string *)current_entry->value;
                printf(data->text);
                fprintf(savefile,data->text);
                printf(":");
                fprintf(savefile,":");
                printf("%d",current_entry->change_time);
                fprintf(savefile,"%d",current_entry->change_time);
                current_entry=current_entry->next;
                printf("\n%d\n",current_entry);
            }
        }
        break;
    }
    default:{
        printf("not saveable yet!\n");
        break;
        }
}



return 1;
}

int load_db_from_hd(string *name){


return 1;
}
int load_column_from_hd(string *name){


return 1;
}
