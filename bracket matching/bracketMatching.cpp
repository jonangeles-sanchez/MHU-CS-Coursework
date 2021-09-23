/**
 * Jonathan Angeles
 * 9/14/20
 * Bracket Matching Program
*/

#include <iostream>
#include "stack.h"
using namespace std;

/**
 * This program will check to see if brackets match.
 * Opening brackets include: '{', '(', '['
 * Closing brackets include: '}', ')', ']'
 * Assume that the code has *no* comments.
 * Use a stack to make sure that each opening bracket has a match.
 * If there is no match or a mis-match, print the line # on which the
 * error occurred and exit.
 *
 * RETURN VALUES:
 * If all brackets match, return 0
 * If *any* bracket errors, return 1
*/

int main(){
	
	const int SIZE = 256;
	Stack_entry buffer[SIZE];
	Stack myStack;
	Stack_entry temp;

	// Read a line of text, storing it in 'buffer'
	while (cin.getline(buffer, SIZE)) {
        
		//at this point in time, 'buffer' holds a line of 'myFile.cpp'
		for(int i = 0; buffer[i]; i++){
			if (buffer[i] == '{' || buffer[i] == '[' || buffer[i] == '(') 
				myStack.push(buffer[i]);
		}
		
		for(int i = 0; buffer[i]; i++) {

		if (buffer[i] == '}' || buffer[i] == ']' || buffer[i] == ')' )
		//myStack.top(temp);
		
  		if (myStack.top(temp)  == '{' && buffer[i] == '}') {
			myStack.pop();
		}  if  
			(myStack.top(temp)  == '[' && buffer[i] == ']') {
				myStack.pop();
			}  if 
				(myStack.top(temp) == '(' && buffer[i] == ')') {
					myStack.pop();
				}  if
					(myStack.top(temp) != buffer[i] || (myStack.empty())) {
						return 1;
						//took a guess where line # may be
						cout << "Error on line " << SIZE  << endl;
						break;
				
					}
				}
			}
			

	
	return 0;
}
