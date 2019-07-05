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

return 1;
}

int load_db_from_hd(string *name){


return 1;
}
int load_column_from_hd(string *name){


return 1;
}
