#include <iostream>
#include <iomanip>
#include "sortUtils.h"
#include "mjgTimer.h"
using namespace std;

/* Prototypes */
void print(int &);
void printList(List<int> &);
void doBubbleSort(List<int > &);
bool sameEntries(List<int> &, List<int>&);
bool isSorted(List<int> &);

int main(){
	//create a list that holds ints
    List<int> myList;
	
	loadRandomList(myList);
	
	//Comment any of the lines below to test only 
	//certain sorts.
	doBubbleSort(myList);
	//doInsertionSort(myList);
	//doSelectionSort(myList);

	
	return 0;
}


void doBubbleSort(List<int> &list){
	List<int> testList;
	testList = list;

	cout << "Before Bubble Sort: " << endl;
	printList(testList);

	//do the sort
	bubbleSort(testList);	
	
	cout << endl << "After Bubble Sort: " << endl;
	printList(testList);
	if(!isSorted(testList)) cout << "***** List is NOT sorted!" << endl;
	if(!sameEntries(testList, list)) cout << "****ENTRIES HAVE BEEN MODIFIED!" << endl;

}

/**
 * This function can be used by a List's traverse() method
 * to print out each item in a List on the same line,
 * separated by spaces.
 * @param x - an item in the List. Passed by .traverse()
 */
void print(int &x){
    cout << setfill('0') << setw(2) << x << "  ";
}

/**
 * This will print the indicies/values of the list
 */
void printList(List<int> &list){
	cout << "Indices: ";
	for(int i = 0; i < list.size(); i++){
		cout << setfill('0') << setw(2) << i << "  ";
	}
	cout << endl;

	cout << "Values:  ";
	list.traverse(print);
	cout << endl;
}
bool sameEntries(List<int> & first, List<int>& second){
		List<int> list1 = first;
		List<int> list2 = second;

		if(list1.size() == list2.size()) {

			int temp, temp2;
			for(int i = 0; i < list1.size(); i++){
				list1.retrieve(i, temp);

				bool found = false;
				for(int j = 0; j < list2.size(); j++){
					list2.retrieve(j, temp2);
					if(temp == temp2){
						list2.remove(j, temp2);
						found = true;
						break;
					}
				}

				if(!found) return false;
			}

			if(list2.size() > 0) return false;
		} else return false;
	return true;
}

bool isSorted(List<int> &list){
	int size = list.size();
	if(size <= 1) return true;

	int val1, val2;
	list.retrieve(0, val1);
	for(int i = 1; i < size; i++){
		list.retrieve(i, val2);

		if(val2 < val1){
			return false;
		}
		val1 = val2;
	}

	return true;

}
