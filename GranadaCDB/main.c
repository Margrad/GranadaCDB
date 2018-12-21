
#include <stdio.h>
#include <stdlib.h>
#include "DataBase.h"
#include "time.h"
#define DEBUG_STR
/**
** This main.c file is used for testing purposes
** I need to create the basic structures and functions
** I need to make it server/client
** I need to make it searchable
** I need to make it multi threat
**/

int main(){
    int number_of_DBs;

    char teste1[]="DB 1";
    char teste2[]="DB 2";
    string *s1;
    string *s2;
    s1 = (string *)malloc(sizeof(string));
    s2 = (string *)malloc(sizeof(string));
    s1->text=teste1;
    s1->len=getLenght(teste1);
    s2->text=teste2;
    s2->len=getLenght(teste2);

    printf("%s\n", teste2);
    printf("%s\n", *s2);
    //Testing DB
    DataBase *DB = NewDB(s1);
    AddColumn(DB, s2,TEXT);
    AddColumn(DB, s1,TEXT);

    int i;
    for(i=0;i<DB->number_of_columns;i++)
        printf("%s\n",DB->Columns[i]->name->text);


    return 0;
}
