# LAB for CS220 - Bubble sort
## Description
Your goal for this exercise is to sort a list using the Bubble Sort algorithm.
Before beginning this lab, we discussed how Bubble Sort operates. If you'd like to see a visual depiction, visit [this site](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html) or [this site](https://www.toptal.com/developers/sorting-algorithms/bubble-sort). You may use no other internet source.

The goal is that you understand how a Bubble Sort works, and then think critically to translate that into C++.

## Getting the Source

1. Accept the GitHub assignment by clicking the link on [Moodle](https://moodle.mhu.edu/).
2. Copy the SSH clone URL. [ NOTE: If you see HTTPS clone URL, click the SSH link directly below the text box to access the SSH clone URL. ]
3. Open up a terminal, and navigate to your cs220 directory and type: `git clone <url from step #2>`
4. The source is now in a directory named bubble-sort-<username> You may change the name of the directory, if you'd like.

## Writing the Source

In this directory, you'll see several files. The files you'll need to pay particular attention to are:

* `doublylinkedlist.h //fully implemented.Don't touch`
* `doublylinkedlist.cpp //fully implemented. Don't touch`
* `sortUtils.h //fully implemented. Don't touch`
* `sortUtils.cpp //You write code for this one! `
* `sortProgram.cpp //fully implemented`
* `unittest_ssort.cpp //simple unit tests to see if your code works`
* `mjgTimer.cpp //simple timer program. Don't touch`
* `mjgTimer.h //simple timer program. Don't touch`
* `Makefile //simple make file to help with compiling`
* `README.md //a github README file`

Write the code for `bubbleSort()` in `sortUtils.cpp`

## Compiling the Source

### Compiling/executing sortProgram.cpp

To compile the sort program, simply type:

`make`

This will create an executable named bubbleSort. To execute your program, type:

`./bubbleSort`

### Cleaning up

To clean up all of the files created by make, type:

`make clean`

## Running Unit Tests

For this program, I've provided some unit tests to more thoroughly test your code. Unit testing is done by writing code that tests each of your program's behaviors against the expected outcome. If it passes, that means that your code behaves correctly. It does not mean that your program is 100% correct.

[ Note: these unit tests will work on the CS server, or on Ferguson 148 lab machines. It is not guaranteed to work on your personal computers, unless the unittest-cpp packages are installed. See me if you'd like your machine to work with these unit tests. ]

To compile the unit test program, type:

`make test`

To execute the unit test program, type:

`./test`

The output will tell you if you failed any of the unit tests. The name of the failed unit test will indicate which part of your List is the culprit. For instance, if the TestClear unit test failed, it means that your List's clear() method doesn't function properly.

## Submitting your source

After you are satisfied that your code works perfectly, you need to commit your code to your local repository, and then push that code back to GitHub.

To commit your working code, type:

`make clean && git commit -a -m 'My working bubble sort program for grading'`

[ Note: you can customize the message however you like. ]

After your code is committed successfully, submit your code to your GitHub repository by:

`git push`

## Grading
Points will be awarded based on the following table:

Metric |	Points
---|---:
Program compiles with no errors or warnings|30
Program passes all unit tests|35
Program includes complete and thorough documentation|15
Program efficiency and correctness|20


