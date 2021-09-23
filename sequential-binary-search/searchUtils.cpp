#include <cstdlib>
#include <iostream>
#include "searchUtils.h"

/* Global constants */
const int NUM_ENTRIES = 15;

/**
 * This function performs a binary search, looking for 
 * searchTerm in list. 'list' must be sorted.
 * @param list - the *sorted* list to search
 * @param searchTerm - the number to look for
 * @return true if searchTerm is found in list, false if not.
 */
bool binarySearch(const List<int> &list, const int searchTerm){
	bool foundValue = false;
	int low, mid, high;
	low = 0;
	high = (list.size() - 1);
	mid = ((low + high) / 2);
	int listVal;

	for (int i = 0; i < list.size(); i++){
		list.retrieve(i, listVal);	
		//while (low <= high) {
			if (mid < searchTerm) {
				low = mid + 1;
			} else if (mid && listVal  == searchTerm) {
				foundValue = true;
				break;
			} else { 
				if (mid > searchTerm) {
				high = mid - 1;
				} 
			} 		
		//}
	}
	return foundValue;
}

/**
 * This function performs a sequential search, looking for 
 * searchTerm in list. 
 * @param list - the list to search
 * @param searchTerm - the number to look for
 * @return true iff searchTerm is found in list, false if not.
 */
bool sequentialSearch(const List<int> &list, const int searchTerm){
	bool foundValue = false;
	
	int listVal;
	for (int i = 0; i < list.size(); i++) {
		list.retrieve(i, listVal);
		if (listVal == searchTerm) {
			foundValue = true;
			break;
		}
	}
	return foundValue;
}

/**
 * Insert NUM_ENTRIES ints into list, making sure the
 * entries are in sorted (increasing) order
 * @param list - The list to populate with an increasingly sorted list
*/
void loadSortedList(List<int> &list){
	srand(time(NULL));
	list.clear();
	int val = (rand() % 20);
	for (int i = 0; i < NUM_ENTRIES; i++) {
		val = (rand() % 20) + val;
		list.insert(i, val);
		}
	}

/**
 * Insert NUM_ENTRIES ints into list, making sure they
 * entries are in random-esque order.
 * @param list - The list to populate with a random list
*/
void loadRandomList(List<int> &list){
	srand(time(NULL));
	list.clear();
	for (int i = 0; i < NUM_ENTRIES; i++) {
		list.insert(i, rand() % 20);
		}
	}
