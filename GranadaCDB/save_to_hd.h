
/***
This part will be responsible for codification of the data when recorded on the hard drive
Empty for now and just return what they get
***/

#include "string.h"
#include "DataBase.h"

int save_db_to_hd(DataBase* DB);
int save_column_to_hd(column* Col_to_save);

int load_db_from_hd(string *name);
int load_column_from_hd(string *name);
