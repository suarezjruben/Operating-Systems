
 **************************************
 * Author: Ruben Suarez               *
 * Project 4: Page Replacement program*
 * Class: Operating Systems (CS 4328) *
 * Instructor: Dr. Xiao Chen          *
 **************************************
 
 Note: use option -std=c99 or -std=gnu99 (or newer) to compile the code if you're having issues compiling on 
 eros.cs.txstate.edu or zeus.cs.txstate.edu. Example: "$gcc -std=c99 program.c -o program"

 Proj4.c Description: 
	This program compares the performance of the LRU and the Optimal page replacement 
	algorithms. The program will take a reference string and the number of frames as inputs.  
	Assuming the maximum length of a reference string is 20 and that there are 5 diffent pages from 
	page 1 to page 5. The reference string can is randomly generated and the number of frames 
	is entered through the keyboard. For example, the system generates a reference string 
	2 1 3 4 5 2 3 ...5 and 3 is entered as the number of frames. The page replacement process 
	of each is displayed so that it can be observerd how LRU differs from the optimal. 
 
 Proj4.c 
	-How to compile:
		The following terminal command will compile Proj3a.c
		$gcc -o Proj4 Proj4.c 

	-How to run:
		To run the Proj3a.c executable simply type in the terminal the following command:
		$./Proj4

		
		


	