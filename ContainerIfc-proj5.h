/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */

#ifndef CONTAINERIFC_PROJ5_H_
#define CONTAINERIFC_PROJ5_H_

class BADINDEX {};

template <class T>
class ContainerIfc
{
public:
	virtual ContainerIfc <T>& pushFront(T) = 0;
	virtual ContainerIfc <T>& pushBack(T) = 0;
	virtual ContainerIfc <T>& popFront(T&) = 0;   //Throws BadIndex
	virtual ContainerIfc <T>& popBack(T&) = 0;    //Throws BadIndex

	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual T front() = 0;    //Throws BadIndex
	virtual T back() = 0;     //Throws BadIndex
	virtual T& operator[](int) = 0;     //Throws BadIndex
};


#endif /* CONTAINERIFC_PROJ5_H_ */
