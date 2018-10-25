/*
 * author: Peter Tran
 * assignment: Project 5
 * class: CSI 1440, Section 3
 * date: April 8th
 */

#ifndef NODE_PROJ5_H_
#define NODE_PROJ5_H_

template <class T>
class Node
{
public:
	T data;
	Node *next;

	Node(T d)
	{
//        cout << "\nData in Node: " << data << endl;
		data = d;
		next = NULL;
	}

	~Node()
	{
		delete next;
	}
};

#endif /* NODE_PROJ5_H_ */
