
 **************************************
 * Author: Ruben Suarez               *
 * Project 2: Shell program           *
 * Class: Operating Systems (CS 4328) *
 * Instructor: Dr. Xiao Chen          *
 **************************************
 
 Note: use option -std=c99 or -std=gnu99 (or newer) to compile the code if you're having issues compiling on 
 eros.cs.txstate.edu or zeus.cs.txstate.edu. Example: "$gcc -std=c99 program.c -o program"
 
 shhh.c holds a small shell - called shhh - that has the following capabilities:
	1. Can execute a command with the accompanying arguments.
	2. Recognizes multiple pipe requests and is able handle them.
	3. Recognizes redirection requests and is able handle them.
	4. Will quit the shhh shell with the keybaord input "exit".

	-How to compile:
		The following terminal command will compile shhh.c, pre.c ana sort.c
		$gcc -o shhh shhh.c
		$gcc -o pre pre.c
		$gcc -o sort sort.c
	-Expected output files:
		shhh
		pre
		sort

	-How to run:
		To run the shell (shhh) executable simply type in the terminal the following command:
		$./shhh
		
		You can then type in a command or ouse one of the sample commands:
		Sample commands:
			shhh>ls
			shhh>ls -t -al
			shhh>cat file.txt (file.txt is an existing file)
			shhh>ls -al > output.txt
			And then open output.txt to see if the content is correct or not
			shhh> ls | more | wc
			shhh>./pre < input.txt | ./sort > output.txt 
			
			If useing ./pre and ./sort from proj1, the input.txt file is an existing file that holds
			the ./pre input data in this format:
				TX 26 
				NC 9
				MD 5
				NY 19
				CA 38
				.
				.
			and the output.txt is the output file where ./sort will print out its results.
		
		You can then input the U.S. state abbreviations and their populations (in millions) 
		as displayed below followed by Ctrl + D on the keybard to terminate the input and 
		have the program begin to process the input.
		
		
		


	