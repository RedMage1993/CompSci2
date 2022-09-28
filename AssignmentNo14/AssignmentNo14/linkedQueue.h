// fritz ammon
// cs 202 section 1002
// assignment 14
// description: the class declaration and
// "definition" of linkedQueue
// a queue implemented with linked lists
// this uses the FIFO structure

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include <string>

template <class Type>
struct queueNode
{
	Type info;
	queueNode<Type> *link;
};

template <class Type>
class linkedQueue
{
public:
	linkedQueue();
	linkedQueue(const linkedQueue<Type>&);

	linkedQueue<Type> operator=(const linkedQueue<Type>&);

	~linkedQueue();

	bool isEmptyQueue() const;

	void initializeQueue();

	void enqueue(const Type&);

	Type front() const;
	Type back() const;

	Type dequeue();

	int queueCount() const;

	void printQueue();

private:
	void copyQueue(const linkedQueue<Type>&);

	queueNode<Type> *queueRear;
	queueNode<Type> *queueFront;

	int count;
};

template <class Type>
linkedQueue<Type>::linkedQueue()
{
	initializeQueue();
}

template <class Type>
linkedQueue<Type>::linkedQueue(const linkedQueue<Type>& queue)
{
	copyQueue(queue);
}

template <class Type>
linkedQueue<Type> linkedQueue<Type>::operator=(const linkedQueue<Type>& queue)
{
	copyQueue(queue);

	return *this;
}

template <class Type>
linkedQueue<Type>::~linkedQueue()
{
	queueNode<Type> *tempNode;

	while (queueFront) // while node is there
	{
		tempNode = queueFront; // keep the nodes address
		queueFront = queueFront->link; // go back a node
		delete tempNode; // delete the last node found
	}
}

template <class Type>
bool linkedQueue<Type>::isEmptyQueue() const
{
	return count == 0;
}

template <class Type>
void linkedQueue<Type>::initializeQueue()
{
	queueFront = queueRear = NULL;
	count = 0;
}

template <class Type>
void linkedQueue<Type>::enqueue(const Type& newItem)
{
	queueNode<Type> *newRear = new queueNode<Type>;

	newRear->info = newItem;
	newRear->link = NULL;

	if (queueFront == NULL) // queueRear is NULL too
		queueFront = queueRear = newRear; // last rear points to new rear
	else
	{
		queueRear->link = newRear;
		queueRear = newRear;
	}

	count++;
}

template <class Type>
Type linkedQueue<Type>::front() const
{
	if (queueFront)
		return queueFront->info; // just show the info at the front
	else // Know that in the case of double, you return 0.0
	{
		std::cout << "Error (front), queue is empty.\n";
		return static_cast<Type> (0);
	}
}

template <>
std::string linkedQueue<std::string>::front() const
{
	if (queueFront)
		return queueFront->info; // just show the info at the front
	else
	{
		std::cout << "Error (front), queue is empty.\n";
		return "";
	}
}

template <class Type>
Type linkedQueue<Type>::back() const
{
	if (queueRear)
		return queueRear->info; // just show the info at the top
	else // Know that in the case of double, you return 0.0
	{
		std::cout << "Error (back), queue is empty.\n";
		return static_cast<Type> (0);
	}
}

template <>
std::string linkedQueue<std::string>::back() const
{
	if (queueRear)
		return queueRear->info; // just show the info at the top
	else
	{
		std::cout << "Error (back), queue is empty.\n";
		return "";
	}
}

template <class Type>
Type linkedQueue<Type>::dequeue()
{
	queueNode<Type> *prevFront;
	Type prevInfo;

	if (queueFront)
	{
		prevFront = queueFront; // Save current front.
		prevInfo = queueFront->info; // Save previous front info.

		queueFront = queueFront->link; // Move back a node (new front).

		delete prevFront; // Delete previous front.

		count--;

		return prevInfo; // Return previous front info.
	}
	else
	{
		std::cout << "Error (dequeue), cannot dequeue from an empty queue.\n";
		// Know that in the case of double, you return 0.0
		return static_cast<Type> (0);
	}
}

template <>
std::string linkedQueue<std::string>::dequeue()
{
	queueNode<std::string> *prevFront;
	std::string prevInfo;

	if (queueFront)
	{
		prevFront = queueFront; // Save current front.
		prevInfo = queueFront->info; // Save previous front info.

		queueFront = queueFront->link; // Move back a node (new front).

		delete prevFront; // Delete previous front.

		count--;

		return prevInfo; // Return previous front info.
	}
	else
	{
		std::cout << "Error (dequeue), cannot dequeue from an empty queue.\n";
		return "";
	}
}

template <class Type>
int linkedQueue<Type>::queueCount() const
{
	return count;
}

template <class Type>
void linkedQueue<Type>::copyQueue(const linkedQueue<Type>& queue)
{
	queueNode<Type> *node; // to traverse the passed queue
	queueNode<Type> *newNode; // for this queue

	count = queue.count;
	if (count == 0)
	{
		queueFront = queueRear = NULL;
		return;
	}

	node = queue.queueFront; // refer to the passed queue's front

	// start off the list
	queueFront = new queueNode<Type>;
	queueFront->info = node->info;
	queueFront->link = NULL;
	
	queueRear = queueFront;

	while (node->link != NULL) // if true then only one node
	{ // else
		node = node->link; // move up passed queue

		newNode = new queueNode<Type>; // make new node
		newNode->info = node->info; // copy passed info
		newNode->link = NULL;
		
		queueRear->link = newNode; // set last node link to new node
		queueRear = newNode; // last is now new node
	}
}

template <class Type>
void linkedQueue<Type>::printQueue()
{
	queueNode<Type> *traverser = queueFront;

	while (traverser)
	{
		std::cout << traverser->info << " ";
		traverser = traverser->link; // move up queue
	}
}

#endif // LINKEDQUEUE_H