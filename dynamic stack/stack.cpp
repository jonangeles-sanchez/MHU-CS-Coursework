/**
 * Marty Gilbert (Professor)
 * Jonathan Angeles
 * Implementation of the Stack class
 */

#include "stack.h"

Node::Node() {
	next = NULL;		
}

Node::Node(Node_entry item, Node * add_on){
	entry = item;
	next = add_on;
}


/**
 * Default Constructor
 */
Stack::Stack() {
	//initialize our class
	topNode = NULL;
}

/**
 * pushes a value onto the top of the Stack
 * @param item value to put on to the Stack
 * @return success if room to add item, overflow if Stack is full
 */
Error_code Stack::push(const Stack_entry &item) {
	Node * newTop = new Node(item, topNode);
	if (newTop == NULL) return overflow;
	topNode = newTop;
	return success;
}


/**
 * Pop - remove the top item from the stack, if it exists
 * @return success if able to remove the top item, underflow
 * if Stack is empty
 */
Error_code Stack::pop() {
	if (empty()) return underflow;
	
	Node * oldTop = topNode;
	topNode = topNode->next;
	delete oldTop;

	return success;
}

/**
 * Empty - tell if the Stack is empty or not
 * @return true iff the Stack is empty, false otherwise
 */
bool Stack::empty() const {
	if (empty()) return true;
	else return false;
}


/**
 * Retrieve the top value (if any) from the Stack
 * @param container - an empty container in which to place the top value
 * @return success, if Stack is NOT empty. underflow otherwise
 */
Error_code Stack::top(Stack_entry &container) const {
	if (empty()) return underflow;
	container = topNode->entry;
	return success;
}
