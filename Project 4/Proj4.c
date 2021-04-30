//Project 4
/*
 * Name:       Proj4.c
 * Author:     Ruben Surez
 * Class:      Operating Systems (CS 4328)
 * Instructor: Dr. Xiao Chen
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define SIZE 20

static int REF_STR[SIZE];
static int FRAMES = 0;
static int OPT_FAULTS = 0;
static int LRU_FAULTS = 0;
static int LRU();
static int OPTIMAL();
static int CALC_FARST(int[], int);

int main(){
    int c;
    do{
        c = 0;
        FRAMES = 0;

        printf("\nEnter number of frames between 1 and 5 (Ctrl + D to exit): ");

        c = scanf("%d", &FRAMES);

        if(FRAMES >= 1 && FRAMES <= 5) {
            printf("\nReference string: {");
            for (int i = 0; i < SIZE; i++) {      // Generating random numbers for reference string
                REF_STR[i] = rand() % 5 + 1;
                printf(" %d", REF_STR[i]);
            }
            printf(" }\n\n");
            printf("LRU Page Replacement Algorithm\n");
            LRU();
            printf("Total Faults: %d\n", LRU_FAULTS);

            printf("\nOptimal Page Replacement Algorithm\n");
            OPTIMAL();
            printf("Total Faults: %d\n", OPT_FAULTS);

            if(OPT_FAULTS < LRU_FAULTS){
                printf("\nOptimal page replacement algorithm took %d steps less than LRU. \n", LRU_FAULTS - OPT_FAULTS);
            }else if(OPT_FAULTS == LRU_FAULTS){
                printf("\nOptimal page replacement algorithm took the same number of steps as LRU. \n");
            }else printf("\nOptimal page replacement algorithm took %d steps more than LRU. \n", OPT_FAULTS - LRU_FAULTS);

        }else if (c == 0) while((getchar())!='\n');
    }while(c != EOF);

}
int LRU(){
    LRU_FAULTS = 0;
    int lru = 0;
    int frame_array[FRAMES];
    int age_counter[FRAMES];
    for(int i = 0; i < FRAMES; i++){
        frame_array[i] = 0;
        age_counter[i] = 0;
    }
    for(int i = 0; i < SIZE; i++){
        int fault = 1;
        for(int i = 0; i < FRAMES; i++){
            age_counter[i]++;
        }
        for(int j = 0; j < FRAMES; j++){
            if(REF_STR[i] == frame_array[j]){
                age_counter[j]=0;
                fault = 0;
                break;
            }
            else if( j == FRAMES -1){
                for(int i = 0; i < FRAMES; i++){
                    if(age_counter[lru] < age_counter[i]) lru = i;
                }
                frame_array[lru] = REF_STR[i];
                age_counter[lru]=0;
            }
        }
        if(fault == 1) LRU_FAULTS++;
        for(int i = 0; i < FRAMES; i++){
            printf("%d\t", frame_array[i]);
        }
        printf("\n");
    }

}

int OPTIMAL(){
    OPT_FAULTS = 0;
    int farthest;
    int frame_array[FRAMES];
    int near_future[FRAMES];
    for(int i = 0; i < FRAMES; i++){
        frame_array[i] = 0;
        near_future[i] = 0;
    }
    for(int i = 0; i < SIZE; i++){
        int fault = 1;
        int empty_found = 0;

        for(int j = 0; j < FRAMES; j++){

            if(REF_STR[i] == frame_array[j]){
                fault = 0;
                break;
            }
            else if( j == FRAMES -1){
                for(int l = 0; l < FRAMES; l++){
                    if(frame_array[l] == 0){
                        frame_array[l] = REF_STR[i];
                        empty_found = 1;
                        break;;
                    }
                }
                if(!empty_found){
                    farthest = CALC_FARST(frame_array, i);
                    frame_array[farthest] = REF_STR[i];
                }

            }
        }
        if(fault == 1) OPT_FAULTS++;
        for(int i = 0; i < FRAMES; i++){
            printf("%d\t", frame_array[i]);
        }
        printf("\n");
    }
}

int CALC_FARST(int frame_array[], int i){
    int counter = 0;
    int farthest = 0;
    int k = i + 1;
    int near_future[FRAMES];
    for(int i = 0; i < FRAMES; i++){
        near_future[i] = 0;
    }
    while(counter < FRAMES - 1 && k < SIZE ){
        for(int l = 0; l < FRAMES; l++){
            if(frame_array[l] == REF_STR[k]){
                if(near_future[l] == 0){
                    near_future[l]++;
                    counter++;
                    break;
                }
            }
        }
        k++;
    }
    for(int i = 0; i < FRAMES; i++){
        if(near_future[i]==0) farthest = i;
    }
    return farthest;
}