//Project 1
/*
 * Name: sort.c
 * Author: Ruben Suarez
 * Class: Operating Systems (CS 4328)
 * Instructor: Dr. Xiao Chen
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char states[10][3];
    int count = 0, c;

    do{
        char s[2] = "";
        c = scanf("%s", s);
        if(c != EOF){
            strcpy(states[count], s);
            count ++;
        }
    }while (c  != EOF);

    char temp[3];
    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(states[i][0] > states[j][0]){
                strcpy(temp, states[i]);
                strcpy(states[i], states[j]);
                strcpy(states[j], temp);
            }
            if(states[i][0] == states[j][0]){
                if(states[i][1] > states[j][1]){
                    strcpy(temp, states[i]);
                    strcpy(states[i], states[j]);
                    strcpy(states[j], temp);
                }
            }
        }
    }

    printf("\nOrdered list: \n");
    for(int i = 0; i < count; i++){
        puts(states[i]);
    }

    return 0;
}
