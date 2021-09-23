/* 
 * Didn't get a chance to finish due to a studious weekend
 * and Monday being full of exams.
 *
*/
#include <cstdlib>
#include <iostream>
#include "sortUtils.h"

/* Global constants */
const int NUM_ENTRIES = 15;
int i, j, min;

//add any additional functions you might need here - MJG

/**
 * This function will sort the list using 
 * the selection sort algorithm.
 * @param list - the list to search
 */
void selectionSort(List<int> &list){
	//List count
	for (i = 0; i < list.size() -1; i++){
		//goes through list 
		for(j = i+1; j < list.size(); j++) {
			//Here begins finding the smallest value
			if (i < min) {
				min = j;
				//Here is where it is then replaced
				list.replace (i, min);
			}
		}
	}
			
}

/**
 * This function will sort the list using 
 * the insertion sort algorithm.
 * @param list - the list to search
 */
void insertionSort(List<int> &list){
	//Wanted to go through values and find values less than
	//
	for (int i = 0; i < list.size(); i++) {
		while (j >= 0) {
			//j = j + 1;
			//value would = value - 1
			j = j - 1;
			}
		//i = j + 1;
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
