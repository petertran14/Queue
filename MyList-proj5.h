/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */

#ifndef MYLIST_PROJ5_H_
#define MYLIST_PROJ5_H_

#include "ContainerIfc-proj5.h"
#include "Node-proj5.h"

//this is not a circular list, use the Node Class
template <class T>
class MyList : public ContainerIfc<T>
{
private:
	Node<T> *head;
	Node<T> *tail;

public:
	MyList() {

        head = NULL;
        tail = NULL;
    }

	~MyList() {

        Node<T> *temp = head;

        while (head != NULL) {

            head = head->next;
            temp->next = NULL;
            delete temp;
            temp = head;
        }
    }

	MyList(MyList& that) {

        //Both head and tail do not point to anything yet
        this->head = NULL;
        this->tail = NULL;

        if (that.getSize() != 0) {

            //temp is for traversing the that list
            Node<T> *temp = that.head;

            //First time assigning a node
            if (this->head == NULL) {

                //create a new node
                this->tail = new Node<T>(temp->data);

                //head will point to the same node tail points to
                this->head = this->tail;

                //advance the that list
                temp = temp->next;
            }

            while (temp) {

                //the current node's next holds the address of the new node
                this->tail->next = new Node<T>(temp->data);

                //reassign tail
                this->tail = this->tail->next;

                //advance the that list
                temp = temp->next;
            }
        }
    }


	MyList <T>& operator=(MyList& that) {

        //to make sure we don't do all this work if we are copying the same objects
        if (this != &that) {

            //delete the data of the ListNode we wish to copy data into
            Node<T> *garbage = head;

            //for operator= we have to delete the data that was originally stored so we
            //can put new data in it
            while (this->head != NULL) {

                this->head = this->head->next;
                garbage->next = NULL;
                delete garbage;
                garbage = this->head;
            }

            this->head = NULL;
            this->tail = NULL;

            if (that.getSize() != 0) {

                Node<T> *temp = that.head;

                if (this->head == NULL) {

                    this->tail = new Node<T>(temp->data);
                    this->head = this->tail;
                    temp = temp->next;
                }

                while (temp) {

                    this->tail->next = new Node<T>(temp->data);
                    this->tail = this->tail->next;
                    temp = temp->next;
                }
            }
        }

        //Return the object
        return *this;
    }

    //reassign head
    virtual MyList <T>& pushFront(T value) {

        //Create a pointer to a Node
        Node<T> *temp = NULL;

        //if we are adding the first value
        if (isEmpty()) {

            this->head = new Node<T>(value);
            this->tail = this->head;
        }

        //There are already elements in the List of Nodes
        else {

            //The temp pointer now points to a new node with the value we want
            temp = new Node<T>(value);

            //temp now points to the node head is pointing to
            temp->next = this->head;

            //head now points to temp
            this->head = temp;
        }

        return *this;
    }

    //reassign tail
    virtual MyList <T>& pushBack(T value) {
        //cout << "\nIn PushBack\n";
        //The list is initially empty
        if (isEmpty()) {
            //cout << "\nBefore Tail\n";
            this->tail = new Node<T>(value);
            //cout << "\nNew Tail\n";
            //cout << "\nTemp Data: " << temp->data << endl;
            this->head = this->tail;
        }

        else {

            //create a new node that tail will point to
            this->tail->next = new Node<T>(value);

            //make the old tail point to the new tail
            this->tail= this->tail->next;
        }

        return *this;
    }

    //reassign head
    //Throws BadIndex
    virtual MyList <T>& popFront(T& value) {

        //Node<T> *temp = this->head;

        //if we have no nodes in our list, throw an error when this function is called
        if (isEmpty()) {

            throw BADINDEX();
        }

        value = this->head->data;

            //we have one node in our list
        if (this->getSize() == 1) {

            delete this->head;
            this->head = this->tail = NULL;
            //value = this->head->data;

            //this will make head point to null
            //this->head = this->head->next;

            //make tail point to null as well, because there are no nodes left
            //this->tail = this->head;

            //delete the only node
            //delete temp;
        }

        //There are more than 1 nodes
        else {

            Node<T> *temp = this->head;

            //advance head to point to the next node
            this->head = this->head->next;

            //the first node will point to null
            temp->next = NULL;

            //delete the first node
            delete temp;
        }

        return *this;
    }

    //reassign tail
    //Throws BadIndex
    virtual MyList <T>& popBack(T& value) {

        Node<T> *temp = this->tail;
        Node<T> *prev = this->head;

        if (isEmpty()) {

            throw BADINDEX();
        }

        value = this->tail->data;

        if (this->getSize() == 1) {

            //get the data in the tail node
            //value = this->tail->data;

            delete this->head;
            this->head = this->tail = NULL;

            //Both point to NULL
            //this->head = this->head->next;
            //this->tail = this->head;

            //delete temp;
        }

        else {

            //get the value at the tail
            //value = this->tail->data;

            while (prev->next->next != NULL) {

                prev = prev->next;
                //cout << "Prev's data: " << prev->data << endl;
            }

            //de-advance tail to null
            this->tail = prev;

            //the tail must always point to null, unless it is a circular list
            this->tail->next = NULL;

            //cout << "Temp's data: " << temp->data << endl;
            //temp is the last node which already points to null
            delete temp;
        }

        return *this;
    }

    virtual int getSize() {
        //cout << "\nInside GetSize\n";
        Node<T> *temp = this->head;
        int count = 0;

        while (temp != NULL) {

            temp = temp->next;
            count++;
        }

        return count;
    }

    virtual bool isEmpty() {

        return head == NULL;
    }

    //Throws BadIndex
    virtual T front() {

        if (isEmpty()) {

            throw BADINDEX();
        }

        return this->head->data;
    }

    //Throws BadIndex
    virtual T back() {

        if (isEmpty()) {

            throw BADINDEX();
        }

        return this->tail->data;
    }

    //Throws BadIndex
    virtual T& operator[](int index) {

        //This is okay.
        //The rule is: Don't return a pointer to a "local" variable
        Node<T> *temp = head;

        //Node<T> *hold;

        if (isEmpty() || index > this->getSize() - 1 || index < 0) {

            throw BADINDEX();
        }

        int count = 0;

        while (temp != NULL) {

            if (count == index) {
//cout << "\nData in Index: " << temp->data << endl;
                return temp->data;
            }

            temp = temp->next;
            count++;
        }

        throw BADINDEX();
    }
};

#endif /* MYLIST_PROJ5_H_ */
