#ifndef _QUEUE_H
#define _QUEUE_H

const int MAX = 100;

typedef int Queue_entry;

enum Error_code {
	success,
	underflow,
	overflow
};

class Queue {
	public:
		Queue(); 
		bool empty() const;
		Error_code serve();
		Error_code append(const Queue_entry &item);
		Error_code retrieve(Queue_entry &container) const;

	protected:
		int count;
		int front, back;
		Queue_entry storage[MAX];
};

#endif
