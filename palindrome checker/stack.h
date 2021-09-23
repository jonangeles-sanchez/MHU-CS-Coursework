/**
 * Header file for our Stack class
 */

#ifndef _STACK_H
#define _STACK_H

const int MAX = 100; 

// Define our custom data type
typedef char Stack_entry;


// Define our error codes
enum Error_code {
    success,    // Really just 0
    underflow,  // Really just 1
    overflow    // Really just 2
};

class Stack {
    public:
        Stack(); // Default constructor

        bool empty() const;

        Error_code pop();
        Error_code push(const Stack_entry &item);
        Error_code top(Stack_entry &container) const;

    private:
        int count;
        Stack_entry storage[MAX];
};

#endif
