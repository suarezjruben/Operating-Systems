//Project 1
/*
 * Name: pre.c
 * Author: Ruben Suarez
 * Class: Operating Systems (CS 4328)
 * Instructor: Dr. Xiao Chen
 */

#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[]) {

    int count = 0;
    int c;

    struct State_Pop{
        char st[2];
        int pop;
    };

    struct State_Pop sp_Array[10];

    do{
        char s[2] = "";
        int p = 0;
        c = scanf("%s %d", s, &p );
        if(s != "" && p >= 0){
            strcpy(sp_Array[count].st, s);
            sp_Array[count].pop = p;
            count ++;
        }
    }while (c  != EOF);

    printf("\nStates with populations > 10 million: \n");
    for(int i = 0; i < count; i++){
        if(sp_Array[i].pop > 9){
            printf("%s \n",sp_Array[i].st);
        }
    }

    return 0;
}