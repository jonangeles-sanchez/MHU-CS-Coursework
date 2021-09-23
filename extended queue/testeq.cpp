#include <iostream>
#include "equeue.h"
using namespace std;


int main() {
	Extended_queue eQ;

	// YOUR CODE GOES HERE
	// You should check every method of Extended_queue,
	// and make sure it works as expected.
	// You will need to use methods of Queue, also
	
	bool passesTests = true;
	
	//Test full() 
	Extended_queue().append(1);
	Extended_queue().append(2);
	Extended_queue().append(3);
	Extended_queue().append(4);
	Extended_queue().append(5);
	if (Extended_queue().full()) {
		cout << "full() seems to work" << endl;
	} else {
		cout << "full() appears to be broken" << endl;
		passesTests = false;
	}
	
	//Test size()
	//Stumped
	if (e) {
		cout << "size() seems to be working" << endl;
	} else {
		cout << "size() seems to be broken" << endl;
		passesTests = false;
	}
	
	//Test retrieveAndServe(Queue_entry &container)
	//Serve
	Extended_queue().serve();
	Extended_queue().serve();
	Extended_queue().serve();
	Extended_queue().serve();
	Extended_queue().serve();
	if (Extended_queue().empty()) {
		cout << "Serve() seems to work." << endl;
	} else {
		cout << "Serve() appears to be broken." << endl;
		passesTests = false;
	}
	//Stumped
	Extended_queue().append(1);
	if (Extended_queue.(1)  == 1) {
		cout << "Serve and retrieve work. Val is 1." << endl;
	} else {
		cout << "Serve and retrieve do not work. Val is not 1." << endl;
		passesTests = false;
	}

	Extended_queue().clear();
	if (Extended_queue().empty()) {
		cout << "Clear() seems to work!" << endl;
	} else {
		cout << "Serve() appears to be broken." << endl;
		passesTests = false;
	}
	
	/*
	//Check for overflow
	Error_code retval;
	for (int i = 0; i < 1000; i++) {
		if ((retval = Extended_queue().append(i)) == overflow) {
			break;
		}
	}
	
	//Should be overflow
	if (retval != overflow) {
		cout << "should have gotten overflow; did not" << endl;
		passesTests = false;
	} else {
		cout << "Got overflow; Test passed" << endl;
	}
	
	//Test underflow
	for (int i = 0; i < 1000; i++) {
		if ((retval = Extended_queue().append(i)) == underflow) {
			break;
		}
	}
	if (retval != underflow) {
		cout << "Should have gotten underflow; did not. Test fails." << endl;
		passesTests = false;
	} else {
		cout << "Got underflow; Test passed" << endl;
	}
	
	if (passesTests) {
		cout << "All tests passed!" << endl;
	} else {
		cout << "Did not pass all tests" << endl; 
	}
	*/
		
	return 0;
}
