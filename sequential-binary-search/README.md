# HW Sequential and Binary Search

## Description

The past few days in class, we've talked about searching a list for a specific search term. It's important to note that a sequential search works on both sorted and unsorted lists, while binary search only works on a sorted list.

As we discussed sequential search's efficiency, we stated that it would need at most n comparisons to find out whether or not a search term exists in the list. Using big-O notation, we write this as O(n)

(read: "order n"). This means that in the worst case, this search takes n comparisons.

More recently, we've discussed searching a sorted list for a term. Binary search, which takes at most lg<sub>2</sub>n
comparisons is written as O(lg n). You will write both the sequential and binary search for this assignment.

## Getting the Source

1. Accept the GitHub assignment by clicking on the link in Moodle.
2. Copy the SSH clone URL. [ NOTE: If you see HTTPS clone URL, click the SSH link directly below the text box to access the SSH clone URL. ]
3. Open up a terminal, and navigate to your cs220 directory and type: `git clone <url from step #2>`
4. The source is now in a directory named sequential-binary-search-<useranme>. You may change the name of the directory, if you'd like.


## Writing the Source

In this directory, you'll see several files. The files you'll need to pay particular attention to are:

* `doublylinkedlist.h //fully implemented.Don't touch.`
* `doublylinkedlist.cpp //fully implemented. Don't touch.`
* `searchUtils.h //fully implemented. Don't touch.`
* `searchUtils.cpp //You write code for this one!`
* `searchProgram.cpp //a simple test program - you write this one`

Write the code for searchUtils.cpp and searchProgram.cpp.


## Compiling the Source

### Compiling/executing simpletest.cpp

To compile the simple test program, simply type:

`make`

This will create an executable named search. To execute your program, type:

`./search`


### Cleaning up

To clean up all of the files created by make, type:

`make clean`


## Running Unit Tests

For this program, I've provided a single unit test to more thoroughly test your code. Unit testing is done by writing code that tests each of your program's behaviors against the expected outcome. If it passes, that means that your code behaves correctly. It does not mean that your program is 100% correct.

[ Note: these unit tests will work on the CS server, or on Ferguson 148 lab machines. It is not guaranteed to work on your personal computers, unless the unittest-cpp* packages are installed. See me if you'd like your machine to work with these unit tests. ]

To compile the unit test program, type:

`make test`

To execute the unit test program, type:

`./test`

The output will tell you if you failed any of the unit tests. The name of the failed unit test will indicate which part of your List is the culprit. For instance, if the TestClear unit test failed, it means that your List's clear() method doesn't function properly.

## Submitting your source

After you are satisfied that your code works perfectly, you need to commit your code to your local repository, and then push that code back to GitHub.

To commit your working code, type:

`make clean && git commit -a -m 'My working sequential and binary search program for grading'`

[ Note: you can customize the message however you like. ]

After your code is committed successfully, submit your code to your GitHub repository by:

`git push`

## Grading
Points will be awarded based on the following table:

Metric|	Points|
---|---:
Program compiles with no errors or warnings|30
Program passes all unit tests|35
Program includes complete and thorough documentation|15
Program efficiency and correctness|20
