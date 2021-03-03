//Project 1
/*
 * Name: pipe.c
 * Author: Ruben Suarez
 * Class: Operating Systems (CS 4328)
 * Instructor: Dr. Xiao Chen
 */

 /*
Write a c program to set up a parent-TO-child pipe; the parent
should 'exec' to perform a "./pre" process and its outputs should be
connected to the pipe connected to the child, which should 'exec' to
perform a "./sort" process. Think about which exec() function to use.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
   int pid;
   int fd[2];
   char *args[]={"./pre","./sort", NULL};

   pipe(fd);

   switch (pid = fork()) {
      case -1:
               perror("fork call");
               exit(2);
      case 0:
               close(0);
               dup(fd[0]);
               close(fd[0]);
               close(fd[1]);
               execv(args[1], args);
               break;
      default:
               close(1);
               dup(fd[1]);
               close(fd[0]);
               close(fd[1]);
               execv(args[0], args);
               break;
   }
   return 0;
}
