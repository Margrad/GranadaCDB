#define BUFFER_SIZE 1024
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "entry.h"
//#include "column.h"
#include "DataBase.h"

void* get_value_from_terminal(type tipo)
{
    char buffer[BUFFER_SIZE];
    char current_char;
    int i;
    while((current_char=getchar()) == ' '); //remove spaces from the string

    switch(tipo){
            case(TEXT):{
                if (current_char != '\"'){                   //check if first element  is '"'
                    printf("String not properly formated");
                    return 0;
                }
                for(i=0;i<BUFFER_SIZE;i++){
                    current_char=getchar();        //check if new element is \ {\n \t \"} for now
                    if(current_char == '\\')        //get value until a new '"' appears
                        {
                            current_char=getchar();
                            switch(current_char)
                                {
                                case('n'):{
                                        buffer[i]='\n';
                                        break;
                                    }
                                case('t'):{
                                        buffer[i]='\t';
                                        break;
                                    }
                                case('"'):{
                                        buffer[i]='\"';
                                        break;
                                    }
                                default: {
                                        printf("ERROR: Miss formatation of string\n");
                                        return 0;
                                    }
                                }
                        }
                    else{
                        if (current_char == '"')
                            break;
                        buffer[i]=current_char;
                    }
                }
                string *value= (string *)malloc(sizeof(string));            //allocate the necessary memory
                value->len  =  i+1;
                value->text = (char *)malloc(sizeof(char)*i+1);            //copy to the new memory
                for(i=0;i<value->len;i++)
                    value->text[i]=buffer[i];
                value->text[value->len-1]='\0';
                return value;            //return;
        };
        case(INTERGER):{};
        case(REAL):{};
        default:{printf("Cannot initialize entry:");return 0;};
    }
}
