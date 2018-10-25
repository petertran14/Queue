/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */

#ifndef QUEUE2_PROJ5_H_
#define QUEUE2_PROJ5_H_

#include "MyVector-proj5.h"

//This class is a circular queue
template <class T>
class Queue2 : public MyVector<T>
{
private:
	int front;
	int rear;

public:
	Queue2() : MyVector<int>() {

        //rear holds the index of a non-existent array at initialization
        this->front = 0;
        this->rear  = -1;
    }

    void enqueue(T value) {

        //if we are out of space, left or right
        if (this->size == this->capacity) {

            //remember the old size
            int oldSize = this->capacity;

            //increase the capacity
            this->capacity += 3;

            //make a temp pointer
            T *temp = new T[this->capacity];

            //copy over the data, starting from front, modulus it whenever there are instances that we have a circular array
            for (int i = 0; i < this->size; i++) {

                temp[i] = this->data[front];
                this->front = (this->front + 1) % oldSize;
            }

            //start the front at index 0 in this new queue, and reset front to 0, and rear to size - 1
            delete [] this->data;
            this->data = temp;
            this->front = 0;
            this->rear = this->size - 1;
        }

        //increase the index to store data
        this->rear = (this->rear + 1) % this->capacity;

        //store data
        this->data[this->rear] = value;

        //increase size
        this->size++;
    }

    //Throws BadIndex
    void dequeue(T &value) {

        if (this->isEmpty()) {

            throw BADINDEX();
        }

        //decrease size
        this->size--;

        //make sure front with be circular if neccessary
        this->front = (this->front + 1) % this->capacity;

        //since front was set to 0 by enqueue, by adding 1 in the previous statement we were ahead an index.
        //Since we were assuming front was -1. Now we pull back an index by subtracting 1.
        value = this->data[this->front - 1];
    }
};


#endif /* QUEUE2_PROJ5_H_ */
