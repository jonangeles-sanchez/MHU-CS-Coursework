#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstdlib> // for use of NULL

typedef int Queue_entry;
typedef Queue_entry Node_entry;

//Node structure definition
struct Node {
    Node_entry entry;
    Node * next;
    
    //two 'methods' of this struct (constructors)
    Node(); //default constructor
    Node(Node_entry, Node * add_on = NULL); //additional constructor
};

enum Error_code {  
    success, // 0
    underflow, // 1
    overflow // 2
};


class Queue {
    public:
        Queue();    
        bool empty() const;
        Error_code serve();
        Error_code append(const Queue_entry &item);
        Error_code retrieve(Queue_entry &container) const;

    protected:
        Node *front, *back;
};

#endif
