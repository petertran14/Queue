/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */
/*
#include "MyVector-proj5.h"

template <class T>
MyVector<T>::MyVector() {

	this->size = 0;
	this->capacity = 1;
	this->data = new T[this->capacity];
}



template <class T>
MyVector<T>::~MyVector() {

	delete [] this->data;
	this->size = 0;
}



template <class T>
MyVector<T>::MyVector(const MyVector& that) {

	this->size = that.size;
	this->capacity = that.capacity;

	this->data = new T[this->capacity];

	for (int i = 0; i < this->size; i++) {

		this->data[i] = that.data[i];
	}
}


template <class T>
MyVector<T>& MyVector<T>::operator=(MyVector& that) {

	if (this != &that) {

		this->size = that.size;
		this->capacity = that.capacity;

		delete [] this->data;
		this->data = new T[this->capacity];

		for (int i = 0; i < this->size; i++) {

			this->data[i] = that.data[i];
		}
	}

	return *this;
}

//its ok to return a reference if the lifetime of the object doesn't
//go out of scope after the return
template <class T>
MyVector<T>& MyVector<T>::pushFront(T item) {

	if (this->size == this->capacity) {

		grow();
	}

	this->shiftRight();
	this->data[0] = item;
	this->size++;

	return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushBack(T item) {

	//if we dont have enough space to add an item, increase its size
	if(this->size == this->capacity) {

		grow();
	}

	this->data[this->size] = item;
	this->size++;

	return *this;
}

//Throws BadIndex
template <class T>
MyVector<T>& MyVector<T>::popFront(T &item) {

	if (this->size == 0) {

		throw BADINDEX();
	}

	//if we actually have data to pop
	if (this->size > 0) {

		item = this->data[0];
		this->size--;
		this->shiftLeft();
	}
}

//Throws BadIndex
template <class T>
MyVector<T>& MyVector<T>::popBack(T &item) {

	if (this->size == 0) {

		throw BADINDEX();
	}

	if (this->size > 0) {

		item = this->data[this->size - 1];
		this->size--;
	}
}

//Throws BadIndex
template <class T>
T MyVector<T>::front() {

	//if there is no data to access
	if (this->size == 0) {

		throw BADINDEX();
	}

	return this->data[0];
}

//Throws BadIndex
template <class T>
T MyVector<T>::back() {

	if (this->size == 0) {

		throw BADINDEX();
	}

	return this->data[this->size - 1];
}

//Throws BadIndex
template <class T>
T& MyVector<T>::operator[](int index) {

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

template <class T>
int MyVector<T>::getSize() const {

	return this->size;
}

template <class T>
bool MyVector<T>::isEmpty() const {

	return this->size == 0;
}
*/