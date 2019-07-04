

#include "table.h"
void DeleteTable(Table *table){
    int i;
    for(i=0;i<table->number_of_columns;i++){
        DeleteColumn(table->Columns[i]);
    }
    free(table);
}
column* NewColumn(string* name, type tipo){
    if(name == NULL){
        printf("pointer to name string is null");
        return 0;
    }
    column *new_column;
    if((new_column=(column *)malloc(sizeof(column))) == NULL )
    {
        printf("Could not allocate memory for the column %s", name->text);
        return 0;
    }
    new_column->entries = NULL;
    new_column->tipo = tipo;
    new_column->name = copy_string(name);
    new_column->number_of_entries = 0;
    return new_column;
}

void DeleteColumn(column* Coluna){
    int i=0;
    for (i=0;i<Coluna->number_of_entries;i++){
        DeleteEntry(Coluna->entries[i]);
    }
    if(Coluna->name!=0)
        DeleteString(Coluna->name);
    if(Coluna!=0)
        free(Coluna);
}
/*
void SequentialEntryDelete(entry *entry0){
    if(entry0->next_entry !=0)
        SequentialEntryDelete(entry0->next_entry);
    DeleteEntry(entry0);
}*/


Table * NewTable(string * name){
/*
allocate memory for table
allocate memory for Columns array
get a column for indexs
set number of rows and columns
*/
    if(name == NULL){
        printf("pointer to name string is null");
        return 0;
    }
    Table *new_table;
    if((new_table=(Table *)malloc(sizeof(Table))) == NULL )
    {
        printf("Could not allocate memory for the table %s", name->text);
        return 0;
    }

    new_table->Columns=(column **) malloc(sizeof(column *) *1);

    // Set index
    string *ID = NewString("ID");
    column* index = NewColumn(ID,INTERGER);//(column *) malloc(sizeof(column ));
    DeleteString(ID);

    //check for empty pointers
    if ( new_table->Columns == NULL || index == NULL){
            free(new_table->Columns);
            DeleteColumn(index);
            free(new_table);
            printf("Failed to allocate memory for initial index Columns of %s", name->text);
            return 0;
    }

    //set tables name
    new_table->name=copy_string(name);

    //Set index to the first column
    new_table->Columns[0]=index;

    new_table->number_of_columns=1;
    new_table->number_of_rows=0;

    return new_table;
}


void CheckColumnsNames(Table *table){
      int numbCols=table->number_of_columns;
      if(numbCols == 0){
        printf(">no columns present-> should have at least ID.\n");
        return;
      }
      printf("Columns present:\n");
      int i=0;
      for(i=0;i<numbCols;i++){
        printf(" %s\n",table->Columns[i]->name->text);
      }
}


void AddColumn(Table *table, string *name, type Tipo){
    int i=0;
    // first check if the column name already exists
    for(i = 0; i<table->number_of_columns;i++){
        if(bcompare_strings(name,table->Columns[i]->name))
            {
                printf("%s already exist at %s\n",name->text,table->name->text);
                return;
            }
        }
    // create column
    column * new_column=NewColumn(name, Tipo);
    // get the same number of rows as there are in the table
    new_column->number_of_entries=table->number_of_rows;
    if(new_column->number_of_entries!=0)
        {
            new_column->entries = (entry **)malloc(sizeof(entry*)*new_column->number_of_entries);
            // populate the rows with empty entries
            for(i=0;i<new_column->number_of_entries;i++)
                {
                    new_column->entries[i]=NewEntry(Tipo, NULL);
                }
        }

    table->Columns=(column **)realloc(table->Columns,sizeof(column*)*(table->number_of_columns+1));
    table->Columns[table->number_of_columns]=new_column;
    table->number_of_columns++;
    printf("column %s created at %s\n",name->text,table->name->text);
}

void AddRow(Table *table){
    int i=0;
    table->number_of_rows++;
    for(i=0; i<table->number_of_columns; i++){
        table->Columns[i]->entries = (entry **) realloc(table->Columns[i]->entries, sizeof(entry*)*table->number_of_rows);
        table->Columns[i]->entries[table->number_of_rows-1]= NewEntry(table->Columns[i]->tipo, NULL);
        table->Columns[i]->number_of_entries=table->number_of_rows;
    }
}
