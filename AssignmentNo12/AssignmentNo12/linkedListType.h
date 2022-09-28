// Fritz Ammon
// CS 202 1002
// HW 12
// Description: linked list type class template

#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

#include <iostream>

using std::cout;

template <class myType>
struct nodeType
{
	myType info;
	nodeType<myType> *link;
};

template <class myType>
class linkedListType
{
public:
	linkedListType(); // constructor
	linkedListType(const linkedListType<myType>&); // copy
	~linkedListType();

	void initializeList();

	bool isEmptyList() const; // no nodes

	void print() const;

	void reversePrint() const; // recursive print

	int length() const; // num nodes

	void destroyList(); // delete all nodes

	myType front() const;
	myType back() const;

	nodeType<myType>* firstPtr() const; // return head

	virtual bool search(const myType&) const = 0;

	virtual void insert(const myType&) = 0;

	virtual void insertLast(const myType&) = 0;

	virtual void deleteNode(const myType&) = 0;

private:
	void copyList(const linkedListType<myType>&); // deep copy of nodes
	void recursiveReversePrint(const nodeType<myType>*) const;

protected:
	int count;
	nodeType<myType> *first;
	nodeType<myType> *last;
};

template <class myType>
linkedListType<myType>::linkedListType()
{
	first = NULL;
	initializeList();
}

template <class myType>
linkedListType<myType>::linkedListType(const linkedListType<myType>& list)
{
	first = NULL;
	copyList(list);
}
	
template <class myType>
linkedListType<myType>::~linkedListType()
{
	destroyList();
}
	
template <class myType>
void linkedListType<myType>::initializeList()
{
	if (first != NULL)
		destroyList();
	else
	{
		first = last = NULL;
		count = 0;
	}
}
	
template <class myType>
bool linkedListType<myType>::isEmptyList() const
{
	return first == NULL;
}
	
template <class myType>
void linkedListType<myType>::print() const
{
	nodeType<myType> *tempNode = first;

	while (tempNode != NULL)
	{
		cout << tempNode->info << " ";
		tempNode = tempNode->link;
	}
}
	
template <class myType>
void linkedListType<myType>::reversePrint() const
{
	recursiveReversePrint(first);
	cout << "\n";
}
	
template <class myType>
int linkedListType<myType>::length() const
{
	return count;
}
	
template <class myType>
void linkedListType<myType>::destroyList()
{
	nodeType<myType> *tempNode;

	while (first != NULL)
	{
		tempNode = first;
		first = first->link;
		delete tempNode;
	}

	last = NULL;

	count = 0;
}
	
template <class myType>
myType linkedListType<myType>::front() const
{
	if (first == NULL)
		return 0;
	else
		return first->info;
}
	
template <class myType>
myType linkedListType<myType>::back() const
{
	if (last == NULL)
		return 0;
	else
		return last->info;
}
	
template <class myType>
nodeType<myType>* linkedListType<myType>::firstPtr() const
{
	return first;
}

template <class myType>
void linkedListType<myType>::copyList(const linkedListType<myType>& list)
{
	nodeType<myType>* tempNode;
	nodeType<myType>* prevNode;

	if (list.count == 0 || list.first == NULL || list.last == NULL)
	{
		initializeList();
		return;
	}

	if (first != NULL)
		destroyList();

	tempNode = list.first;

	first = new nodeType<myType>;
	first->info = tempNode->info;
	first->link = NULL;

	last = first;

	count = list.count;

	tempNode = tempNode->link;

	while (tempNode != NULL)
	{
		prevNode = new nodeType<myType>;
		prevNode->info = tempNode->info;
		prevNode->link = NULL;

		last->link = prevNode;
		last = prevNode;

		tempNode = tempNode->link;
	}
}
	
template <class myType>
void linkedListType<myType>::recursiveReversePrint(const nodeType<myType>* node) const
{
	if (node != NULL)
	{
		recursiveReversePrint(node->link);
		cout << node->info << " ";
	}
}

#endif // LINKEDLISTTYPE_H