#include "equeue.h"

int Extended_queue::size() const {
	// From p.91 in the book
	return count;
}

bool Extended_queue::full() const {
	return (count == MAX);
}

void Extended_queue::clear() {

	while (!Extended_queue().empty()){ 
		Extended_queue().serve();
		}
		
	
		
}

Error_code Extended_queue::retrieveAndServe(Queue_entry &container){
	if (count <=0) return underflow;
	container = storage[front];
	return success;
}
