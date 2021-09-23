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
    //YOUR CODE GOES HERE
    front = back = NULL;
    count = 0;
}


/**
 * Put the value from the front of the Queue
 * into 'item'
 * @param item The empty container in which the front value will be stored
 * @return Error_code underflow if the queue is empty; success otherwise
*/
Error_code Queue::retrieve(Queue_entry &container) const {
    if (empty()) return underflow;

    container = front->entry;
    
    return success;
}

/**
 * Serve the front item off of the Queue
 * @return Error_code underflow if the queue is empty; success otherwise
*/
Error_code Queue::serve(){
    if (empty()) return underflow;
    Node * oldFront = front;
    front = front->next;
    delete oldFront;

    if(front == NULL) back = NULL;
    count--;

    return success;
}


/**
 * Append item to the end of the Queue
 * @param item The data to add to the end of the queue
 * @return Error_code overflow if the queue is full; success otherwise
*/
Error_code Queue::append(const Queue_entry &item){
    Node * newBack = new Node(item);
    if(newBack == NULL) return overflow;
    if (front == NULL) front = back = newBack;
    else {
        back->next = newBack;
        back = newBack;
    }
    count++;
    return success;
}

/**
 * @return True iff the queue is empty
*/
bool Queue::empty() const {
    return (front == NULL);
}

Queue::~Queue(){
    while(!empty()) serve();
}

int Queue::size() const{
    return count;
}

Queue::Queue(const Queue &original){
    Node *originalNode = original.front;
    if (originalNode == NULL){
        front = back = NULL;
    } else {
        front = back = new Node(originalNode->entry);
        while(originalNode->next != NULL){
            originalNode = originalNode->next;
            back = back->next = new Node(originalNode->entry);
        }

    }
    count = original.count;
}

void Queue::operator = (const Queue &original){
    Node *newFront, *newBack, *originalNode = original.front;
    if (originalNode == NULL){
        newFront = newBack = NULL;
    } else {
        newFront = newBack = new Node(originalNode->entry);
        while(originalNode->next != NULL){
            originalNode = originalNode->next;
            newBack = newBack->next = new Node(originalNode->entry);
        }

        while(!empty()) serve();
    }
    count = original.count;
    front = newFront;
    back = newBack;

}
