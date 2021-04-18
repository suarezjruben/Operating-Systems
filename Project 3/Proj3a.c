//Project 3
/*
 * Name:       Proj3a.c
 * Author:     Ruben Surez
 * Class:      Operating Systems (CS 4328)
 * Instructor: Dr. Xiao Chen
 */

 /*
  Three students are competing for a scholarship of $4,000. The
  scholarship is awarded in a FCFS fashion. Each time each a
  student can get 25% of the available fund.

  This program does NOT consider the mutual exclusion problem.
 */

 #include <math.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <pthread.h>

 static const float _25_percent = .25;
 static int SCHOLARSHIP_AMOUNT = 4000;
 static int TOTAL_GRANTED = 0;
 static void *grant();

 int main(){
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;

    char *student_id_a = "A";
    char *student_id_b = "B";
    char *student_id_c = "C";

    pthread_setconcurrency(2);

    pthread_create(&tid1, NULL, (void *(*)(void *))grant, student_id_a);
    pthread_create(&tid2, NULL, (void *(*)(void *))grant, student_id_b);
    pthread_create(&tid3, NULL, (void *(*)(void *))grant, student_id_c);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    usleep(100);

    printf("Total amount given out: %d\n", TOTAL_GRANTED);

    pthread_exit(0);
 }

 static void *grant(void *id){
    float amount_granted = 0;

    while(SCHOLARSHIP_AMOUNT > 0){
       amount_granted = SCHOLARSHIP_AMOUNT * _25_percent;
       amount_granted = ceil(amount_granted);
       TOTAL_GRANTED = TOTAL_GRANTED + amount_granted;
       sleep(1);
       SCHOLARSHIP_AMOUNT = SCHOLARSHIP_AMOUNT - amount_granted;
       if(amount_granted >= 1){
          printf("%s=%.0f\n",id, amount_granted);
       }
    }

 }
