#include "string.h"
#include <stdlib.h>
#include <stdio.h>

string* to_lower_case(string* old_text){
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

int bcompare_strings(string *s1, string *s2){
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

string* NewString(char *Text)
{
    string* newString=(string *)malloc(sizeof(string));
    newString->text=Text;
    newString->len=getLenght(Text);
    return newString;
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
int bstring_has_string(string* a, string* b){
    if (b->len > a->len){
        return 0;
    }
    int i,j;
    for(i = 0; i < (a->len-b->len) ; i++){
        if(a->text[i] == b->text[0]){
            for(j=1 ; j<b->len; j++){
                if(b->text[j] == '\0')
                    return 1;
                if(a->text[i+j] == b->text[j])
                    continue;
                else
                    break;
            }
        }
    }
    return 0;
}
