
#include "linkedlist.h"

template <class Node_entry>
Node<Node_entry>::Node(){
	next = NULL;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry val, Node<Node_entry> * link){
	entry = val;
	next = link;
}

/**
 * Default constructor.
 * Set head = current = NULL,
 * count = 0, and
 * current_position = -1;
*/
template <class List_entry>
List<List_entry>::List(){
	count = 0;
	current = head = NULL;
	current_position = -1;
}

/**
 * Destructor
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
List<List_entry>::~List(){
	clear();
		

}

/**
 * Copy constructor
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy){
	count = 0;
	current = head = NULL;
	current_position = -1;
	List_entry temp;
	for (int i = 0; i < copy.size(); i++) {
		copy.retrieve(i, temp);
		insert(i, temp);
	}
}

/**
 * Copy operator
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
void List<List_entry>::operator = (const List<List_entry> &copy){
	count = 0;
	current = head = NULL;
	current_position = -1;
	List_entry temp;
	for (int i = 0; i < copy.size(); i++) {
		copy.retrieve(i, temp);
		insert(i, temp);
	}
}

/**
 * Checks if list is full by using boolean.
 * I don't know what the limit would be...
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
bool List<List_entry>::full() const{
	Node<List_entry> *testNode = new Node<List_entry>(); 
	if (testNode == NULL) {
		 return true;
	} else {
		//delete testNode;
		remove(0, testNode);
		return false;		
	}
}
//remove(0, temp);
/*
 * Uses true or false to determine if list is empty.
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
bool List<List_entry>::empty() const{
	if (head == NULL){
	       	return true;
	} else {
		return false;
	}
	//return (count == 0);
}

/**
 * Clears list.
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
void List<List_entry>::clear(){
/*	
	while (head != NULL)	{
		current = head;
		head = current->next;
		delete current;
		 
		}
	}
*/
	if (count == 0) return;
	List_entry temp;
	while(!empty()) {
		remove(0, temp);
	}
}
//list_entry temp;
//while (!empty() {
//	remove (NULL, temp);
//}

/**
 * Retrieves a certain position.
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &container) const{
	//if(position == 0) return underflow;
	if (count == 0) return underflow;
	if(position < 0 || position >= count) return rangeError;
	
	set_position(position);
	//current = head;
	container = current->entry;
	return success;
	//while (head != NULL) {
	}
	
	

// if (empty()) return underflow;
// if (position < 0 || position >= count) return rangeError;
// set_position(position);
// container = current->entry;
//return success;



/**
 * Replaces position.
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &item){
		//current->entry=item
		//replace line container = current->entry;
		if (empty()) return underflow;
		if (position < 0 || position >= count) return rangeError;
		set_position(position);
		current->entry=item;
}

/**
 * Removes position.
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &container){
	if (head == NULL) return underflow;
	if(position < 0 || position > count) return rangeError;
	
	current = head;
	while (current->next != NULL) {
		//if(current->next = Node<List_entry>) {
		//container = Node<List_entry>(item);
		current->next = current->next->next;
		delete container;
		count--;
		}
	//}
}
	

/**
 * This will return the count (size) of the list.
 * @param (if applicable)
 * @return (if applicable)
*/
template <class List_entry>
int List<List_entry>::size() const{
	return count; 
}

/**
 * This will insert item at 'position' in the list, if the list is not full.
 * Any entries at >= position must shifted to the right by 1
 * @param position must be 0 <= position <= count, where count is the # of elements
 * @param item is the List_entry to add
*/
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &item){

	if(position < 0 || position > count) return rangeError;

	Node<List_entry> *new_node;
	new_node = new Node<List_entry>(item);
	if(new_node == NULL) return overflow;

	if(position == 0){
		new_node->next = head;
		current = head = new_node;
		current_position = 0;
	} else {
		set_position(position - 1);
		new_node->next = current->next;
		current->next = new_node;
	}

	count++;
	return success;
}

/**
 * The action specified by function (*visit) has been performed on every
 * entry (in order) of the List, beginning at position 0.
*/
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry&)){
	Node<List_entry> * q = head;
	while(q != NULL){
		(*visit)(q->entry);
		q = q->next;
	}
}

/**
 * Internal method for setting the 'current' Node * to 'position' 
 * After this method is done, 'current' should point to the Node
 * in 'position', and 'current_position' holds 'position'
 * @param position is the position to set 0 <= position < count 
*/
template <class List_entry>
void List<List_entry>::set_position(int position) const{
	if(position < current_position){
		current = head;
		current_position = 0;
	}
	for(; current_position != position; current_position++){
		current = current->next;
	}
}
// if (empty()) return underflow; 
// if (position < 9 }} position <= count
// clear();
// List_entry temp;
// for (int i - 9; i < copy.size(); i++) {
// copy.retrieve(i, temp);
// insert(i, temp);
// }
