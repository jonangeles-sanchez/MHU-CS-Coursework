# CS220 - Simple Linked List Assignment

## Getting the Source

1. Accept the GitHub Assignment on our Moodle page. The name of the repository is linked_list
2. Copy the SSH clone URL. [ NOTE: If you see HTTPS clone URL, click the SSH link directly below the text box to access the SSH clone URL. ]
3. Open up a terminal, and navigate to your cs220 directory and type:

`git clone <url from step #2>`

The source is now in a directory named dynamic-linked-list-<username>. You may change the name of the directory, if you'd like.


## Writing the Source

In this directory, you'll see several files. The files you'll need to pay particular attention to are:

* `linkedlist.h` //fully complete - don't touch!
* `linkedlist.cpp` //2-3 methods completed - finish implementing this!
* `simpletest.cpp` //a simple test program - you should make this better.

Write the code for linkedlist.cpp - you'll need to implement every method in the skeleton file. Be sure to provide documentation for each method.

Reminder, this implementation uses dynamic storage.

## Compiling the Source

### Compiling/executing simpletest.cpp

To compile the simple test program, simply type:

`make`

This will create an executable named linkedList. To execute your program, type:

`./linkedList`

### Cleaning up

To clean up all of the files created by make, type:

`make clean`

## Running Unit Tests

For this program, I've provided unit tests to more thoroughly test your code. Unit testing is done by writing code that tests each of your program's behaviors against the expected outcome. If it passes, that means that your code behaves correctly. It does not mean that your program is 100% correct.

[ Note: these unit tests will work on the CS server, or on Ferguson 148 lab machines. It is not guaranteed to work on your personal computers, unless the unittest-cpp* packages are installed. See me if you'd like your machine to work with these unit tests. ]

To compile the unit test program, type:

`make test`

To execute the unit test program, type:

`./test`

The output will tell you if you failed any of the unit tests. The name of the failed unit test will indicate which part of your List is the culprit. For instance, if the TestClear unit test failed, it means that your List's clear() method doesn't function properly. 
