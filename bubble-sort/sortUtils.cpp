#include <cstdlib>
#include <iostream>
#include "sortUtils.h"

/* Global constants */
const int NUM_ENTRIES = 15;


//add any additional functions you might need here - MJG

/**
 * This function will sort the list using 
 * the bubble sort algorithm.
 * @param list - the list to search
 */
void bubbleSort(List<int> &list){

	for(int i = 0; i < list.size(); i++) {
		for (int j = 0; j < list.size() - 1 - i; j++) {
			int rightVal = j+1;
			int leftVal = j;
			list.retrieve (j, leftVal);
			list.retrieve (j + 1, rightVal);
			if (leftVal > rightVal) {
				list.replace (j, rightVal);
				list.replace (j + 1, leftVal);
			}
		}
	}		
}


/**
 * Insert NUM_ENTRIES ints into list, making sure they
 * entries are in random-esque order.
 * @param list - The list to populate with a random list
*/
void loadRandomList(List<int> &list){
	srand(time(NULL));
	for(int i = 0; i < NUM_ENTRIES; i++){
		list.insert(i, rand() % 50);
	}
}
