/*
 * Marty
 * Implementation of contiguous queue
 */

#include "queue.h"

/**
 * Default Constructor
 */
Queue::Queue(){
	count = 0;
	front = 0;
	back  = MAX - 1;
}

/**
 * Determine whether this Queue is empty
 * @return true iff Queue is empty, false otherwise
 */
bool Queue::empty() const {

	return (count ==0);
}

/**
 * Remove the item from the front of the Queue
 * @return underflow if Queue is empty, success otherwise
 */
Error_code Queue::serve() {
	if (empty()) return underflow;

	count--;

	//can't do this because of circular queue
	front = (front + 1) % MAX;

	return success; 

}


/**
 * Add an item to the back of the queue
 * @param item to be added to the end of the queue
 * @return overflow if Queue is full, success otherwise
 */
Error_code Queue::append(const Queue_entry &item) {

	if (count == MAX) return overflow;
	
	count++;
	
	back = (back + 1) % MAX;
	storage[back] = item; 

	return success;
}

/**
 * Retrieve a value from the front of the Queue
 * @param container will hold the value from the front of the Queue
 * @return underflow if the Queue is empty, success otherwise
 */
Error_code Queue::retrieve(Queue_entry &container) const {
	if (empty()) return underflow;

	container = storage[front];
	
	return success;
	
}
