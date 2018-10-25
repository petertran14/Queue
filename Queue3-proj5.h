/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */

#ifndef QUEUE3_PROJ5_H_
#define QUEUE3_PROJ5_H_

#include "MyList-proj5.h"

//queue implemented as a ListNode
template <class T>
class Queue3 : public MyList<T>
{
public:
	void enqueue(T value) {

        this->pushBack(value);
    }

    //Throws BadIndex
	void dequeue(T& value) {

        if (this->isEmpty()) {

            throw BADINDEX();
        }

        this->popFront(value);
    }
};

#endif /* QUEUE3_PROJ5_H_ */
