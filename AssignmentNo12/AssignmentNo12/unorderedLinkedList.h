// Fritz Ammon
// CS 202 1002
// HW 12
// Description: linked list type class template

#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include "linkedListType.h"

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type&) const;

	void insert(const Type&);

	void insertLast(const Type&);

	void deleteNode(const Type&);

protected:
	using linkedListType<Type>::count;
	using linkedListType<Type>::first;
	using linkedListType<Type>::last;
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& item) const
{
	nodeType<Type> *tempNode = first;
	bool found = false;

	while (tempNode != NULL && !found)
	{
		if (tempNode->info == item)
			found = true;
		else
			tempNode = tempNode->link;
	}

	return found;
}

template <class Type>
void unorderedLinkedList<Type>::insert(const Type& item)
{
	nodeType<Type> *tempNode = new nodeType<Type>;

	tempNode->info = item;
	tempNode->link = first;

	first = tempNode;

	count++;

	if (last == NULL)
		last = first;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& item)
{
	nodeType<Type> *tempNode = new nodeType<Type>;

	tempNode->info = item;
	tempNode->link = NULL;

	if (first == NULL)
		first = last = tempNode;
	else
	{
		last->link = tempNode;
		last = tempNode;
	}

	count++;
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& item)
{
	nodeType<Type> *tempNode;
	nodeType<Type> *prevTempNode;
	bool found;

	if (first == NULL)
		cout << "Cannot delete node from empty list.\n";
	else
	{
		if (first->info == item)
		{
			tempNode = first;
			first = first->link;
			count--;

			if (first == NULL)
				last = NULL;

			delete tempNode;
		}
		else
		{
			found = false;
			prevTempNode = first;

			tempNode = first->link;

			while (tempNode != NULL && !found)
			{
				if (tempNode->info != item)
				{
					prevTempNode = tempNode;
					tempNode = tempNode->link;
				}
				else
					found = true;
			}

			if (found)
			{
				prevTempNode->link = tempNode->link;
				count--;

				if (last == tempNode)
					last = prevTempNode;

				delete tempNode;
			}
		}
	}
}

#endif // UNORDEREDLINKEDLIST_H