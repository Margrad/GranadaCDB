/**
Defines the functions for the string
->string* lower_case(string* old_text)          //needs further testing
        returns the address of a lower case version of the input string
->char compare_strings(string *s1, string *s2); //needs further testing
        compares two string to see if they are the same returns 1 if they are or zero otherwise
->string* newString(char *text, int len)        //needs further testing
        returns the address to a new string of lenght len and pointing to text (!!!!! UNUSED? !!!!!)
->void DeleteString(string *s)                  //needs further testing
        frees the memory for a string  s
->int getLenght(char *text)                     //needs further testing
        checks the length of a string terminated with  '\0'
-> bool string_has_string(string* a, string* b)
        // checks if a string a has string b in it;
**/
#ifndef _STRING
#define _STRING

typedef struct _string_{
char* text;
int len;
}string;


string* NewString(char*);
void DeleteString(string *);
int getLenght(char *);

int   bcompare_strings(string *, string *);
int bstring_has_string(string* a, string* b);
string* to_lower_case(string*);
string *copy_string(string *s2);

#endif
