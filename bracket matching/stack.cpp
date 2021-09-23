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
	count = 0;
}

/**
 * Destructor. Remove all of the Nodes made by this Stack
 */
Stack::~Stack() {
	while (!empty()) pop();	
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
	count++;
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
	count--;

	return success;
}

/**
 * Empty - tell if the Stack is empty or not
 * @return true iff the Stack is empty, false otherwise
 */
bool Stack::empty() const {
	return (topNode == NULL);
}


/**
 * Retrieve the top value (if any) from the Stack
 * @param container - an empty container in which to place the top value
 * @return success, if Stack is NOT empty. underflow otherwise
 */
Error_code Stack::top(Stack_entry &container) const {
	if(empty()) return underflow;
	
	container = topNode->entry;

	return success;
}


/**
 * Overloaded assignment operator
 * This will tell C++ what to do when we try to set one of 
 * our Stack's equal to another. If we do:
 * stack1 = stack2;
 * Then stack1 should be an exact replica of stack 1
 * @param original the stack to be copied
 */
void Stack::operator = (const Stack &original) {
	Node *newTop, *newCopy, *originalNode = original.topNode;

	if (originalNode == NULL){
		newTop = NULL;
	} else {
		newTop = newCopy = new Node(originalNode->entry);
		while(originalNode->next != NULL){
			originalNode = originalNode->next;
			newCopy = newCopy->next = new Node(originalNode->entry);
			//newCopy = newCopy->next;
		}
	}
	
	//remove all of our Nodes
	while(!empty()) pop();

	topNode = newTop;
	count = original.count;
}

/**
 * Copy constructor
 * Used so that the stack is created as an exact replicat of original
 * @param original the stack to be copied
 */
Stack::Stack(const Stack &original){
	Node *newCopy, *originalNode = original.topNode;

	if(originalNode == NULL) topNode = NULL;
	else {
		topNode = newCopy = new Node(originalNode->entry);
		while(originalNode->next != NULL){
			originalNode = originalNode->next;
			newCopy = newCopy->next = new Node(originalNode->entry);
		}
	}
	count = original.count;

}

/**
 * @return the number of items on the stack
 */
int Stack::size() const {
	return count;
}
