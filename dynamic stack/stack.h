
#ifndef _STACK_H
#define _STACK_H

#include <cstdlib> //for NULL

//define a new type, Stack_entry
typedef int Stack_entry;
typedef Stack_entry Node_entry;

enum Error_code {
	success,  //really 0
	overflow, //really 1
	underflow //really 2
};

struct Node {
	Node_entry entry;
	Node *next;

	//constructors
	Node();
	Node(Node_entry item, Node * add_on = NULL);
};


class Stack {
	public:
		Stack(); //constructor

		Error_code pop();
		Error_code push(const Stack_entry &item);
		Error_code top(Stack_entry &container) const;
		bool empty() const;

	private:
		Node *topNode;
};

#endif
