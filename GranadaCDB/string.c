/**
Defines the functions for the string
->string* lower_case(string* old_text)          //needs further testing
returns the address of a lower case version of
the input string
->char compare_strings(string *s1, string *s2); //needs further testing
compares two string to see if they are the same
returns 1 if they are or zero otherwise
->string* newString(char *text, int len)        //needs further testing
returns the address to a new string of lenght
len and pointing to text (!!!!! UNUSED? !!!!!)
->void DeleteString(string *s)                  //needs further testing
frees the memory for a string  s
->int getLenght(char *text)                     //needs further testing
checks the length of a string terminated with
'\0'
**/
#include "string.h"
#include "entry.h"
#include "column.h"
#include "DataBase.h"
#include <stdlib.h>
#include <stdio.h>

string* lower_case(string* old_text){
    int i;
    char dif='a'-'A';
    string *new_text;
    new_text = (string*)malloc(sizeof(string));
    new_text->text = (char*)malloc(sizeof(char)*old_text->len);
    for(i=0;i<old_text->len;i++)
    {
        if(old_text->text[i]>='A' && old_text->text[i]<='Z')
            new_text->text[i]=old_text->text[i]+dif;
        else
            new_text->text[i]=old_text->text[i];
    }
    return new_text;
}

char compare_strings(string *s1, string *s2){
    int i,len;
    if(s1->len != s2->len) return 0;
    for (i=0,len=s1->len;i<len;i++)
        if(s1->text[i] != s2->text[i]) return 0;
    return 1;
}

string *copy_string(string *s2){
    string *s1;
    if ((s1 = (string *)malloc(sizeof(string)))==0)
    {
        printf("fail to allocate memory for a copy string");
        return 0;
    }
    int i,len;
    s1->len=s2->len;
    if( (s1->text=(char *)malloc(sizeof(char)*s1->len)) == 0)
    {
        printf("fail to allocate memory for a copy string");
        return 0;
    }
    for (i=0,len=s1->len;i<len;i++)
        s1->text[i] = s2->text[i];
    return s1;
}

void DeleteString(string *s)
{
    if(s == 0) return;
    if(s->text !=0 )
        free(s->text);
    free(s);
}


/**
Mini functions
**/
int getLenght(char *text){
int i=0;
while(text[i]!='\0')
    i++;
return i+1;
}
