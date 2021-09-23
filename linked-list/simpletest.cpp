/**
 * Edit this file to customize your interaction with the List that you've written
 */
#include <iostream>
using namespace std;

#include "linkedlist.cpp"

void print(int &q){
	cout << q << " ";
}

int main(){
	
	List<int> myList;

	int val1;

	cout << "Enter values - enter -1 to quit " << endl;
	cin >> val1;

	while(val1 != -1) {
		Error_code result = myList.insert(myList.size(), val1);

		if(result != success){
			cout << "insert() returned error" << endl;
		}
		cin >> val1;
	}


	//what else do you need to test?

	cout << endl << endl << "Your values in order are: \n";
	myList.traverse(print);
	cout << endl;
	
	
	
	return 0;

}
