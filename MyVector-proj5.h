/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */

#ifndef MYVECTOR_PROJ5_H_
#define MYVECTOR_PROJ5_H_

#include "ContainerIfc-proj5.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

template <class T>
class MyVector : public ContainerIfc<T>
{
protected:
	T *data;
	int size;
	int capacity;

	//need to implement these to
	void grow()
	{
		if (this->size == this->capacity) {

			this->capacity += 3;
			T *temp = new T[this->capacity];

			for (int i = 0; i < this->size; i++) {

				*(temp + i) = *(data + i);
			}

			delete [] this->data;
			this->data = temp;
		}
	}

	//this is for pushFront, where it adds data to the front and we
	//need to give it space
	void shiftRight()
	{
        if (this->getSize() > 0) {

            //shift all the elements over by one, the data[0] will still hold
            //the original item of what used to be there but we can overwrite it
            for (int i = 0; i < this->getSize(); i++) {

                this->data[this->size - i] = this->data[this->size - i - 1];
            }
        }
	}

	//this is for pop front, where we have removed the first element and
	//therefore need to shift everything left by one to keep good order
	void shiftLeft()
	{
        if (this->getSize() > 1) {

            //copy over the data
            for (int i = 0; i < this->getSize(); i++) {

                this->data[i] = this->data[i + 1];
            }
        }
	}

public:
	MyVector() {

        this->size = 0;
        this->capacity = 3;
        this->data = new T[this->capacity];
    }
	~MyVector() {

        delete [] this->data;
        this->size = 0;
    }

	MyVector(const MyVector& that) {

        this->size = that.size;
        this->capacity = that.capacity;

        this->data = new T[this->capacity];

        for (int i = 0; i < this->size; i++) {

            this->data[i] = that.data[i];
        }
    }

	MyVector<T>& operator=(MyVector that) {

        if (this != &that) {

            this->size = that.size;
            this->capacity = that.capacity;

            delete[] this->data;
            this->data = new T[this->capacity];

            for (int i = 0; i < this->size; i++) {

                this->data[i] = that.data[i];
            }
        }

        return *this;
    }

	MyVector<T>& pushFront(T item) {

        if (this->size == this->capacity) {

            grow();
        }
        int value;

        this->size++;
        this->shiftRight();

        this->data[0] = item;

//        cout << "\nValues: " << endl;
//        for (int i = 0; i < getSize(); i++) {
//
//            cout << data[i] << " ";
//        }

        return *this;
    }

    MyVector<T>& pushBack(T item) {

        //if we dont have enough space to add an item, increase its size
        if(this->size == this->capacity) {

            grow();
        }

        this->data[this->size] = item;
        this->size++;

        return *this;
    }

    //Throws BadIndex
    MyVector<T>& popFront(T &item) {

        if (this->size == 0) {

            throw BADINDEX();
        }

        //return the item by reference
        item = this->data[0];

        //we need to shift our data left to rebalance the array
        this->shiftLeft();

        //decrease the size
        this->size--;

        return *this;
    }

    //Throws BadIndex
    MyVector<T>& popBack(T &item) {

        if (this->size == 0) {

            throw BADINDEX();
        }

        if (this->size > 0) {

            item = this->data[this->size - 1];
            this->size--;
        }

        return *this;
    }

    //Throws BadIndex
    T front() {

        //if there is no data to access
        if (this->size == 0) {

            throw BADINDEX();
        }

        return this->data[0];
    }

    //Throws BadIndex
    T back() {

        if (this->size == 0) {

            throw BADINDEX();
        }

        return this->data[this->size - 1];
    }

    //Throws BadIndex
    T& operator[](int index) {

        //if there are no items in our *data, then it is not reasonable
        //to access them
        if (this->size == 0) {

            throw BADINDEX();
        }

        //We can create an object of the class:
        //MyVector obj;
        //obj[5] will now return the item at the 5 element in *data
        return this->data[index];
    }

    int getSize() {

        return this->size;
    }

    bool isEmpty() {

        return this->size == 0;
    }
};


#endif /* MYVECTOR_PROJ5_H_ */
