#include <iostream>
#include "queue.h"
using namespace std;

/**
 * This is a simple test to test the basic methods of your Queue. 
 * Feel free to augment it so that your tests are more complete
 */
int main() {
	
	Queue myQ;
	bool hasErrors = false;
	
	//Empty
	if (myQ.empty()) {
		cout << "Empty() seems to be working" << endl;
		} else {
			cout << "Empty() seems not be working" << endl;
			hasErrors = true;
		}
	//append
	cout << "Adding 1-10";
	for (Queue_entry i = 0; i < 10; i++){
		myQ.append(i + 1);	
		cout << ".";
	}
	cout << endl;
	if (!myQ.empty()) {
		cout << "Append() seems to be working..." << endl; 
		cout << "Now Testing Retrieve()" << endl;
	} else {
		cout << "Append() seems not to be working" << endl;
		hasErrors = true;
	}
	//Retrieve
	Queue_entry temp;
	Queue_entry val = 1;
	while(!myQ.empty()){
		myQ.retrieve(temp);
		myQ.serve();
		
		cout << "Testing entry matches " << val << "...";
		if (val++ == temp){
			cout << "PASSED" << endl;
			cout << "Retrieve works." << endl;
			cout << "Now Testing Serve()" << endl;
			cout << "Appending myQ..." << endl;
		} else {
			cout << "FAILED" << endl;
			cout << "Retrieving may have not worked." << endl;
			hasErrors = true;
			break;
		}
	}
	
	//Serve
	while (!myQ.empty()) {
		myQ.serve();
	}
	if (myQ.empty()) {
		cout << "Serve seems to be working." << endl;
	}  else {
		cout << "Serve seems not to be working." << endl;
		hasErrors = true;
	}
	if (hasErrors){
		cout << "Queue has errors. Keep working" << endl;
	} else {
		cout << "No errors found in simple test" << endl;
	}
	
	return 0;

}
