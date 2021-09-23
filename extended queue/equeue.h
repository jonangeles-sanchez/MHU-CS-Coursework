#ifndef _EQUEUE_H
#define _EQUEUE_H

#include "queue.h"

class Extended_queue : public Queue {
	public:
		bool full() const;
		void clear();
		int size() const;
		Error_code retrieveAndServe(Queue_entry &container);
};


#endif
