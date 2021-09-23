#include "queue.h"

//Implementation of Node constructors
Node::Node(){
	next = NULL;
}

Node::Node(Node_entry item, Node * add_on){
	entry = item;
	next = add_on;
}

/**
 * Constructor
*/
Queue::Queue(){
	front = back = NULL;
}


/**
 * Put the value from the front of the Queue
 * into 'item'
 * @param item The empty container in which the front value will be stored
 * @return Error_code underflow if the queue is empty; success otherwise
*/
Error_code Queue::retrieve(Queue_entry &container) const {
	if(empty()) return underflow;
	container = front->entry;
	return success;
}

/**
 * Serve the front item off of the Queue
 * @return Error_code underflow if the queue is empty; success otherwise
*/
Error_code Queue::serve(){
	if(front == NULL) return underflow;
	Node *old_front=front;
	front = old_front->next;
	if(front == NULL) back = NULL;
	delete old_front;
	return success;
}


/**
 * Append item to the end of the Queue
 * @param item The data to add to the end of the queue
 * @return Error_code overflow if the queue is full; success otherwise
*/
Error_code Queue::append(const Queue_entry &item){
	Node *new_back = new Node(item);
	if (new_back == NULL) return overflow;
	if (back == NULL) front = back = new_back;
	else {
		back->next = new_back;
		back = new_back;
	}
	return success;
}

/**
 * @return True iff the queue is empty
*/
bool Queue::empty() const {
	return (front == NULL);
	}

