//Project 2
/*
 * Name: shh.c
 * Author: Ruben Suarez
 * Class: Operating Systems (CS 4328)
 * Instructor: Dr. Xiao Chen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

main(){
    char *path, *argv[20], buf[80], n, *p;
    int m, status, inword, continu;

    while(1) {
        inword = 0;
        p = buf;
        m = 0;
        continu=0;
        printf( "\nshhh> ");
        while ( ( n = getchar() ) != '\n'  || continu ) {

            if ( n ==  ' ' ) {
                if ( inword ) {
                    inword = 0;
                    *p++ = 0;
                }
            }
            else if ( n == '\n' ) continu = 0;
            else if ( n == '\\' && !inword ) continu = 1;
            else {
                if ( !inword ) {
                    inword = 1;
                    argv[m++] = p;
                    *p++ = n;
                }
                else *p++ = n;
            }

        }

        *p++ = 0;
        argv[m] = 0;

        if ( strcmp(argv[0],"exit") == 0 ) exit(0);

        /* Your change starts from here */

        char *in_file, *out_file;
        int arg_index, start_index, pipes, in_flag, out_flag, pid;
        arg_index = start_index = pipes = in_flag = out_flag = 0;
        int r_fd[2], l_fd[2], start[20]= {0};

        /* Identifying special characters */
        while( argv[arg_index] != 0 ){
            if( strcmp(argv[arg_index], "<") == 0 ){
                argv[arg_index] = 0;
                in_file = argv[arg_index + 1];
                in_flag++;
                arg_index++;
            }
            if( strcmp(argv[arg_index], "|") == 0 ){
                argv[arg_index] = 0;
                pipes++;
                start[++start_index] = arg_index + 1;
                arg_index++;
            }
            if( strcmp(argv[arg_index], ">") == 0 ){
                argv[arg_index] = 0;
                out_file = argv[arg_index + 1];
                out_flag++;
                arg_index++;
            }
            else arg_index++;
        }
        /*for(int i = 0; i < arg_index; i++){ // will display start[]
            printf("%d\n", start[i]);
        }*/
        for( int i = 0; i <= pipes; i++){
            if(pipes > 0 && i != pipes){
                pipe(r_fd);
            }
            switch (pid = fork()) {
                case   -1:
                    perror("fork() call failed!");
                    exit(-1);

                case    0:
                    if(in_flag > 0 && i == 0){ //If there is a "in" flag and i is the 1st process
                        int n = open(in_file, O_RDONLY, 0754);
                        close(0);
                        dup(n);
                        close(n);
                    }
                    if(out_flag > 0 && i == pipes){ //if "out" flag and i is the last process
                        int n = open(out_file, O_WRONLY | O_CREAT, 0754);
                        close(1);
                        dup(n);
                        close(n);
                    }
                    if(pipes > 0){
                        if(i == 0){
                            close(1);
                            dup(r_fd[1]);
                            close((r_fd[1]));
                            close(r_fd[0]);
                        }
                        if(i > 0 && i < pipes){
                            close(0);
                            dup(l_fd[0]);
                            close(l_fd[0]);
                            close(l_fd[1]);
                            close(1);
                            dup(r_fd[1]);
                            close((r_fd[1]));
                            close(r_fd[0]);
                        }
                        if(i == pipes){
                            close(0);
                            dup(l_fd[0]);
                            close(l_fd[0]);
                            close(l_fd[1]);
                        }
                    }
                    execvp(argv[start[i]], &argv[start[i]]);
                    perror("Command failed to execute!\n");
                    break;
                default  :
                    if(i > 0){
                        close(l_fd[0]);
                        close(l_fd[1]);
                    }
                    l_fd[0] = r_fd[0];
                    l_fd[1] = r_fd[1];
                    wait(&status);
                    break;
            }
        }
    }
}