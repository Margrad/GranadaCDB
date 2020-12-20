#include "time.h"
union _t1_{
    time_t time;
    char text[9];
};

union _t2_{
    time_t time;
    char text[5];
};


string* convert_time_to_String(time_t value)
{
    string * time_to_string = (string *)malloc(sizeof(string));
    int i;
    if (sizeof(time_t)== 8){
        union _t1_ time;
        time.time = value;
        time.text[8] = '\0';
        time_to_string->len=9;
        time_to_string->text = (char *)malloc(sizeof(char)*9);
        for(i=0;i<time_to_string->len;i++){
            time_to_string->text[i]=time.text[i];
        }

    }else if(sizeof(time_t)== 4){
        union _t1_ time;
        time.time = value;
        time.text[5] = '\0';
        time_to_string->len=5;
        time_to_string->text = (char *)malloc(sizeof(char)*5);
        for(i=0;i<time_to_string->len;i++){
            time_to_string->text[i]=time.text[i];
        }

    }else{
        printf("Error: time_t has unusual size");
}


return time_to_string;
}
