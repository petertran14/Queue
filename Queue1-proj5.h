/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */

#ifndef QUEUE1_PROJ5_H_
#define QUEUE1_PROJ5_H_

#include "MyVector-proj5.h"

//This class is not a circular queue
//Queues are First In, First Out
template <class T>
class Queue1 : public MyVector<T>
{
public:
	void enqueue(T value) {

        //a value is added to the rear
        this->pushBack(value);
    }

    //Throws BadIndex
	void dequeue(T& value) {

        if (this->isEmpty()) {

            throw BADINDEX();
        }

        //a value is removed from the front
        this->popFront(value);
    }
};

#endif /* QUEUE1_PROJ5_H_ */
