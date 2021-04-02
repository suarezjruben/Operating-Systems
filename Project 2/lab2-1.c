/*			Lab 2 Partial Example			*/

#include <stdio.h>

main(){
    char *path, *argv[20], buf[80], n, *p;
    int m, status, inword, continu;

    //
    //argv = array of pointers
    //

    while(1) {
        inword = 0;
        p = buf;
        m = 0;
        continu=0;
        printf( "\nshhh> ");
        while ( ( n = getchar() ) != '\n'  || continu ) {
            //
            //printf("Continu %d\n", continu);
            //printf("N: %c\n", n);
            //printf("inword %d\n", inword);
            //
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
                    argv[m++] = p; //argument m++ equal pointer p which iquals buf
                    //printf("1st argv: %s\n", argv[0]);
                    //
                    //printf("inword %d\n", inword);
                    //printf("m %d\n", m);
                    //printf("argv: %s\n", argv[m]);
                    //printf("buf address: %d\n", buf);
                    //printf("p address: %d\n", p);
                    //printf("Continu %s\n", continu);
                    //printf("N: %c\n", n);
                    *p++ = n;
                    //printf("2st argv: %s\n", argv[1]);
                    //printf("buf: %.2c\n", buf);
                    //printf("buf address: %d\n", buf);
                    //printf("buf[1] address: %d\n", &buf[1]);
                    //printf("p address: %d\n", p);
                    //printf("n address value: %d\n", &n);
                    //printf("p physical address: %d\n", &p);
                    //printf("2nd p: %c\n", p);
                    //printf("2nd buf: %d\n", buf);
                    //printf("argv: %s\n",argv[m]);
                }
                else{
                    *p++ = n;
                    printf("2nd buf: %s\n", buf[2]);
                }
                //printf("3nd p: %c\n", &p);
                //printf("2nd n value: %d\n", n);
            }

        }
        printf("m %d\n", m);
        *p++ = 0;
        argv[m] = 0;
        printf("argv[0]: %s\n", argv[0]);
        printf("argv[1]: %s\n", argv[1]);
        printf("argv[2]: %s\n", argv[2]);

        if ( strcmp(argv[0],"exit") == 0 ) exit(0);

        /* Your change starts from here */

        /*if ( fork() == 0 ){

            execvp( argv[0], argv );
            printf ( " didn't exec \n ");

        }*/



        wait(&status);
        //
        //printf("%d\n", status);
        //printf("%s\n", &status);
        //


    }

}

//./pre < input.txt | rm output.txt | mkdir example | ls -al > output.txt