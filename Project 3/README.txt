
 **************************************
 * Author: Ruben Suarez               *
 * Project 3: Multi-threading program *
 * Class: Operating Systems (CS 4328) *
 * Instructor: Dr. Xiao Chen          *
 **************************************
 
 Note: use option -std=c99 or -std=gnu99 (or newer) to compile the code if you're having issues compiling on 
 eros.cs.txstate.edu or zeus.cs.txstate.edu. Example: "$gcc -std=c99 program.c -o program"

 Proj3a.c and Proj3b.c focus on the following subject:
	Three students are competing for a scholarship of $4,000. The
  	scholarship is awarded in a FCFS fashion. Each time each a
  	student can get 25% of the available fund.
 
 Proj3a.c does NOT consider the mutual exclusion issue.
	-How to compile:
		The following terminal command will compile Proj3a.c
		$gcc -o a Proj3a.c -lpthread -lm

	-How to run:
		To run the Proj3a.c executable simply type in the terminal the following command:
		$./a
		
  Proj3b.c does consider the mutual exclusion issue and addresses it.
	-How to compile:
		The following terminal command will compile Proj3a.c
		$gcc -o b Proj3b.c -lpthread -lm

	-How to run:
		To run the Proj3a.c executable simply type in the terminal the following command:
		$./b	
		
		
		


	