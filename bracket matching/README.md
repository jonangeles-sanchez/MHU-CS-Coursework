# CS220 - Data Structures

## Bracket Matching Program
See more details on this assignment by visiting [MHU's Moodle Site](https://moodle.mhu.edu/)

### Description

For this lab, you will write a program that reads a file and determines if there are any mis-matched brackets. This occurs when a source file has an opening bracket ( '**\[**', '**(**', or '**{**' ) but doesn't have a corresponding closing bracket ( '**\]**', '**)**', or '**}**' ).  

To solve this problem, as your program encounters an opening bracket, it will push it onto a stack. When a closing bracket is encountered, it _should_ be correctly paired with the opening bracket that is currently on top of the stack. If it is a mis-match, print an error, stating which line has the mis-matched entry, and exit.

If there are extra opening brackets on the stack after the program is done, this is an error also. Print a message stating this fact.

If there are no mis-matched brackets, print a message stating that the file has none.  

### Getting the source

We will be using git/GitHub for this assignment.

To complete the assignmnet, you must:
1. Click the link to accept the assignmnet. Sign-in with the GitHub account you previously created.
1. After accepting the invitation, you should see a repository that starts with `bracketmatching` and has your GitHub username after it. View that repository by clicking on it.
1. Now you need to clone your newly created repository to your home directory. To do this, click the green Code button, and look for and copy the SSH clone URL on the right-side of the page. NOTE: If it says 'HTTPS clone URL', click 'SSH' below the text box, and it will switch to 'SSH clone URL'. 
1. Open a terminal and navigate to your cs220 directory. Type `git clone <your SSH clone URL>`

### Requirements
To complete this project successfully, you must perform the following tasks:

1. Write `bracketMatching.cpp`
1. Make sure you define `Stack_entry` to be a `char` in `stack.h`  
1. Create a `myFile.cpp` - this is the file your program will check for errors. Introduce a bracket error on a known line, so you'll know what the output of your program should be.  
1. Modify _bracketMatching.cpp_ where specified to check for mis-matched brackets.
1. You can assume there are no comments in your test file.
1. You can assume there are no blank lines in your test file.  
1. You cannot use the internet or your book for this exercise, but you _can_ use any/all past code you have.
1. You will turn in your code at the time specified by pushing to the GitHub repository, regardless of whether it works or not.

### Running Your Code
To compile your code:
`make`

To run your code:
`./bracket < myFile.cpp`

Where `myFile.cpp` is your test file.


### Submitting your program
To submit your program:
1. `make clean`
2. `git commit -a -m 'My bracket matching program for grading' && git push`
