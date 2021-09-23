#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <cstdio>

enum Error_code {
    success,
    underflow,
    overflow,
    range_error
};

template <class Node_entry>
struct Node{
    Node_entry entry;
    Node<Node_entry> * next;
    Node<Node_entry> * back;

    Node();
    Node(Node_entry, Node<Node_entry> * link_back = NULL,
        Node<Node_entry> * link_next = NULL);
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
        Error_code retrieve(int position, List_entry &item) const;
        Error_code replace(int position, const List_entry &item);
        Error_code remove(int position, List_entry &item);
        Error_code insert(int position, const List_entry &item);

        //extra
        ~List();
        List(const List<List_entry> &copy);
        void operator = (const List<List_entry> &copy);
    protected:
        int count;
        void set_position(int position) const;

        mutable int current_position;
        mutable Node<List_entry> * current;
};

#endif
