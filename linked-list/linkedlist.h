#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <cstdio>

enum Error_code {
	success,
	underflow,
	overflow,
	rangeError
};

template <class Node_entry>
struct Node{
	Node_entry entry;
	Node<Node_entry> * next;

	Node();
	Node(Node_entry, Node<Node_entry> * link = NULL);
};

template <class List_entry>
class List {
	public:
		List();
		int size() const;
		bool full() const;
		bool empty() const;
		void clear();
		void traverse(void (*visit)(List_entry &));

		Error_code retrieve(int position, List_entry &container) const;
		Error_code replace(int position, const List_entry &item);
		Error_code remove(int position, List_entry &container);
		Error_code insert(int position, const List_entry &item);

		//extra
		~List();
		List(const List<List_entry> &copy);
		void operator = (const List<List_entry> &copy);
	protected:
		int count; //# items on list
		Node<List_entry> *head; //always points to 1st Node
		void set_position(int position) const; //internal method

		//'mutable' means that these variables can be changed in a 'const' function.
		mutable Node<List_entry> * current; //the current node
		mutable int current_position; //the position in the list of 'current'
};

#endif
