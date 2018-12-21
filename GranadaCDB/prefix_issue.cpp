#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct cost{
    int n;
    int a;
    int b;
} COST;
typedef struct sr{
    int val;
    int n;
} SR;

int check_prefix(SR* sli, int n){
    int i;

}


SR* calc_pref(COST* cost){
    int total=0;
    int max_bin_size=0;
    SR* results;
    results = (SR*)malloc(sizeof(SR));

    while(total < n){


    }


}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int j,n,a,b;
    COST *costs;

    cin >> j;
    costs=(COST *)malloc(sizeof(COST)*j);
    for(int i=0;i<j;i++){
        cin >> costs[i].n;
        cin >> costs[i].a;
        cin >> costs[i].b;
    }






    return 0;
}

