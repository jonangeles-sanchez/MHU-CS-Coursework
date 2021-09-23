/**
 * Jonathan Angeles-Sanchez
 * 9/11/20
 * This program will test all of the methods of our Stack class
 */
#include <iostream>
#include "stack.h"
using namespace std;

int main() {

	Stack myStack;
	bool passesTests = true;
	//Empty
	
		if (myStack.empty()) {
			cout << "empty() seems to work" << endl;
		} else {
			cout << "empty() does not seem to work" << endl;
			passesTests = false;
		}
	//Push
	
	myStack.push(1);
	
	if (!myStack.empty()) {
		cout << "push() seems to work" << endl;
	} else {
		cout << "push() seems to not work" << endl;
		passesTests = false;
	}
	
	//Top
	
	Stack_entry temp;
	myStack.top(temp);

	if (myStack.top(temp) == 1) {
		cout << "Retrieve() seems to work" << endl;
	} else {
		cout << "Retrieve() does not seem to work" << endl;
		passesTests = false;
	}
	
	//Pop
	
	myStack.pop();
	if (myStack.empty()) {
		cout << "pop() seems to work" << endl;
	} else {
		cout << "pop() seems not to work" << endl;
		passesTests = false;
	}
	
	//PassesTests
	
	if (passesTests) {
		cout << "All tests passed!" << endl;
	} else {
		cout << "Did not pass all tests." << endl;
	}

	return 0;
}
