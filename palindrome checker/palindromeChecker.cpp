#include <iostream>
#include <cstdio>
#include "stack.h"
using namespace std;


int main(){  

    //to hold the user's input
    Stack_entry original[80];
   
    //to hold the reverse of the input
    Stack myPalindromeStack; 

    //Assume it's a palindrome - switch to 'false' if we disprove it
    bool isPalindrome = true; 

    //A temp Stack_entry container when we need to call myPalindromeStack.top(temp);
    Stack_entry temp;

    //Put your name below
    cout << "Welcome to Jonathan's Palindrome Checker!" << endl;
    cout << "Enter the string you'd like to check: ";
    cin.getline(original, 80);

    //YOUR CODE STARTS HERE
    //Push 'original' onto the myPalindromeStack, character by character
    for (int i = 0;original[i]; i++) {
	myPalindromeStack.push(original[i]); 
	}
   
   /* while (!myPalindromeStack.empty()) {
	myPalindromeStack.top(temp);
	}
    */ 
    //After pushing onto myPalindromeStack
    // -compare the first character of 'original' to the top of the stack
    // Don't know what to do here... Here is where I got stumped.
    // I wasn't sure if I was supposed to reverse a stack or it would 
    // already be reversed.	 
  
    //while (!myPalindromeStack.empty()) {
    for (int i = 0; i < original[i]; i++) {

	if(myPalindromeStack.top(temp) == myPalindromeStack.top(original[80])){
    //      -if the same, check the next character (until the end of 'original')
	myPalindromeStack.pop();
	}
    //      -if different, not a palindrome! Stop checking 'original'
    	else {
		break;
	}
}    
    //YOUR CODE ENDS HERE
    //I am also not sure how to end the code considering there are exitCodes below
    
    
    /** DO NOT EDIT BELOW THIS LINE */
    int exitCode = 0;
    if(isPalindrome){
        cout << original << " IS a palindrome!" << endl;
    } else {
        cout << original << " is NOT a palindrome!" << endl;
        exitCode = 1;
    }

    return exitCode;
}
