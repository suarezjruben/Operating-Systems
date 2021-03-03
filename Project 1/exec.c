//Project 1
/*
 * Name: exec.c
 * Author: Ruben Suarez
 * Class: Operating Systems (CS 4328)
 * Instructor: Dr. Xiao Chen
 */

 /*
 Write a program to take a UNIX command from the command line
 and fork() a child to execute it. The command can be a simple
 command like: $ls or $ps, Or it can be a command with options such as
 $ls -t -l. Use argc and argv[] in the main function to pass parameters.
When the child process is executing the command, the parent process
simply waits for the termination of the child process. The process
id of the parent and the child should be printed out using getpid() and
getppid() functions.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

   char null[4] = "NULL";
   char *args[argc];
   char command[10];

   if(argc > 1){
      strcpy(command,argv[1]);
      for(int i = 0; i < argc - 1; i++){
         args[i] = (char *) malloc(strlen(argv[i+1]) + 1);
         strcpy(args[i], argv[i+1]);
      }
      args[argc - 1] = NULL;
   }

   int pid;
   pid = fork();
   if (pid < 0){
      printf("Fork failed. Error occured" );
      exit(2);
   }
   if(pid == 0){
      printf("Child pid: %d\n", getpid());
      printf("Parent pid: %d\n", getppid());
      //execvp(command,argv + 1); //Gave me a weird warning
      execvp(command,args);

   }
   if(pid > 0){
      wait(NULL);
      //printf("Child terminated.\n");
   }

   return 0;
}
