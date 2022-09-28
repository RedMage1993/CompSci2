// Fritz Ammon
// CS 202 1002
// HW 12
// Description: ordered linked list
// differs insert/insertLast
// includes sortedmerge

#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include "linkedListType.h"

#include <string>

using std::string;

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type&) const; // check if item exists

	void insert(const Type&); // inserts item but keeps order

	void insertLast(const Type&); // inserts at the end

	void deleteNode(const Type&);

	void sortedMerge(const linkedListType<Type>&,
		const linkedListType<Type>&);

	nodeType<Type>* sMerge(nodeType<Type>*, nodeType<Type>*);

protected:
	using linkedListType<Type>::count;
	using linkedListType<Type>::first;
	using linkedListType<Type>::last;
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& item) const
{
	nodeType<Type> *tempNode = first;
	bool found = false;

	while (tempNode != NULL && !found)
	{
		if (tempNode->info >= item)
			found = true;
		else
			tempNode = tempNode->link;
	}

	if (found)
		found = tempNode->info == item;

	return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& item)
{
	nodeType<Type> *tempNode = NULL;
	nodeType<Type> *prevTempNode = NULL;
	nodeType<Type> *newNode = new nodeType<Type>;
	bool found;

	if (search(item))
	{
		cout << "The item to be inserted is already in the list.\n";
		return;
	}

	newNode->info = item;
	newNode->link = NULL;

	if (first == NULL)
		first = last = newNode;
	else
	{
		tempNode = first;
		found = false;

		while (tempNode != NULL && !found)
		{
			if (tempNode->info >= item)
				found = true;
			else
			{
				prevTempNode = tempNode;
				tempNode = tempNode->link;
			}
		}

		if (tempNode == first)
		{
			newNode->link = first;
			first = newNode;
		}
		else
		{
			prevTempNode->link = newNode;
			newNode->link = tempNode;

			if (tempNode == NULL)
				last = newNode;
		}
	}

	count++;
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& item)
{
	insert(item);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& item)
{
	nodeType<Type> *tempNode;
	nodeType<Type> *prevTempNode = NULL;
	bool found;
	string notInList = "Item to be deleted is not in list.\n";

	if (first == NULL)
		cout << "Cannot delete node from empty list.\n";
	else
	{
		tempNode = first;
		found = false;

		while (tempNode != NULL && !found)
		{
			if (tempNode->info >= item)
				found = true;
			else
			{
				prevTempNode = tempNode;
				tempNode = tempNode->link;
			}
		}

		if (tempNode == NULL)
			cout << notInList;
		else
		{
			if (tempNode->info == item)
			{
				if (first == tempNode)
				{
					first = first->link;
					if (first == NULL)
						last = NULL;

					delete tempNode;
				}
				else
				{
					prevTempNode->link = tempNode->link;

					if (tempNode == last)
						last = prevTempNode;

					delete tempNode;
				}

				count--;
			}
			else
				cout << notInList;
		}
	}
}

template <class Type>
void orderedLinkedList<Type>::sortedMerge(const linkedListType<Type>& list1,
				 const linkedListType<Type>& list2)
{
	nodeType<Type> *tempNode;

	count = list1.length() + list2.length();

	tempNode = first = sMerge(list1.firstPtr(), list2.firstPtr());
	if (tempNode == NULL)
	{
		last = NULL;
		return;
	}

	while (tempNode->link != NULL)
		tempNode = tempNode->link;

	last = tempNode;
}

template <class Type>
nodeType<Type>* orderedLinkedList<Type>::sMerge(nodeType<Type>* node1,
												nodeType<Type>* node2)
{
	nodeType<Type>* newFirst = NULL;

	if (node1 == NULL && node2 == NULL) // end of a list is reached
		newFirst = NULL;
	else if (node1 == NULL)
	{
		newFirst = new nodeType<Type>;
		newFirst->info = node2->info;
		newFirst->link = sMerge(NULL, node2->link);
	}
	else if (node2 == NULL)
	{
		newFirst = new nodeType<Type>;
		newFirst->info = node1->info;
		newFirst->link = sMerge(node1->link, NULL);
	}
	else if (node1->info <= node2->info)
	{ // if node1 was smaller, move down its list and check next
		newFirst = new nodeType<Type>;
		newFirst->info = node1->info;
		newFirst->link = sMerge(node1->link, node2);
	}
	else
	{
		newFirst = new nodeType<Type>;
		newFirst->info = node2->info;
		newFirst->link = sMerge(node1, node2->link);
	}

	return newFirst;
}

#endif // ORDEREDLINKEDLIST_H