/**
 * Implementation of our Stack class
 */

#include "stack.h"

/**
 * Default constructor
 */
Stack::Stack() {
    // Initialize our stack
    count = 0;
}

/**
 * Determine if the stack is empty or not
 * @return true if the stack is empty, false otherwise
 */
bool Stack::empty() const {
    if (count == 0) {
        return true;    
    }
    return false;

    // return (count == 0);
}

/**
 * Push a value onto the top of the stack
 * @param item the value to push onto the stack
 * @return success if there is space. Overflow otherwise
 */
Error_code Stack::push(const Stack_entry &item) {
    // Check for overflow FIRST!
    if (count == MAX) return overflow;  
    
    // Add item to storage at spot count
    storage[count] = item;

    // Increment count
    count++;    

    // A one-line solution that does both?
    // storage[count++] = item;

    return success;
}


/**
 * Retrieve the value on top of the stack
 * @param container - empty container in which to place the top value
 * @return success, or underflow if stack is empty
 */
Error_code Stack::top(Stack_entry &container) const {
    if (empty()) return underflow;

    container = storage[count - 1];

    return success;
}

/**
 * Remove a value from the top of the stack
 * @return success or underflow, if stack is empty
 */
Error_code Stack::pop() {
    if (empty()) return underflow;

    count--;

    return success;
}
