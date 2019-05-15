
#ifndef _STRING
#define _STRING

typedef struct _string_{
char* text;
int len;
}string;


string* NewString(char*);
char   compare_strings(string *, string *);
string* lower_case(string*);
void DeleteString(string *);
int getLenght(char *);
string *copy_string(string *s2);
#endif
