// fritz ammon
// cs 202 section 1002
// assignment 14
// description: the class declaration and
// "definition" of linkedStack
// a stack implemented with linked lists

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>
#include <string>

template <class myType>
struct nodeType
{
	myType info;
	nodeType<myType> *link;
};

template <class myType>
class linkedStack
{
public:
	linkedStack();
	linkedStack(const linkedStack<myType>&);

	~linkedStack();

	void deleteStack();

	bool isStackEmpty() const;

	void push(const myType&);

	myType peek() const;

	myType pop();

	int stackCount() const;

	myType stackSum() const;

	bool operator==(const linkedStack<myType>&);
	bool operator!=(const linkedStack<myType>&);

	linkedStack<myType> operator=(const linkedStack<myType>&);

private:
	myType rSum(nodeType<myType> *) const;

	void copyStack(const linkedStack<myType>&);

	nodeType<myType> *stackTop;
	int count;
};

template <class myType>
linkedStack<myType>::linkedStack()
{
	count = 0;
	stackTop = 0;
}

template <class myType>
linkedStack<myType>::linkedStack(const linkedStack<myType>& stack)
{
	copyStack(stack);
}

template <class myType>
linkedStack<myType>::~linkedStack()
{
	deleteStack();
}

template <class myType>
void linkedStack<myType>::deleteStack()
{
	nodeType<myType> *node, *tempNode;

	node = stackTop;
	while (node) // while node is not 0
	{
		tempNode = node; // save the node
		node = node->link; // move to next node
		delete tempNode; // delete the saved node
	}

	count = 0;
}

template <class myType>
bool linkedStack<myType>::isStackEmpty() const
{
	return count == 0;
}

template <class myType>
void linkedStack<myType>::push(const myType& info)
{
	nodeType<myType> *newTop = new nodeType<myType>;

	newTop->info = info;
	newTop->link = stackTop; // new node points to (last) top

	stackTop = newTop; // new top is teh new node

	count++;
}

template <class myType>
myType linkedStack<myType>::peek() const
{
	if (stackTop)
		return stackTop->info; // just show the info at the top
	else // Know that in the case of double, you return 0.0
	{
		std::cout << "Error (peek), stack is empty.\n";
		return static_cast<myType> (0);
	}
}

template <>
std::string linkedStack<std::string>::peek() const
{
	if (stackTop)
		return stackTop->info; // just show the info at the top
	else
	{
		std::cout << "Error (peek), stack is empty.\n";
		return "";
	}
}

template <class myType>
myType linkedStack<myType>::pop()
{
	nodeType<myType> *prevTop;
	myType prevInfo;

	if (stackTop)
	{
		prevTop = stackTop; // Save current top.
		prevInfo = stackTop->info; // Save previous top info.

		stackTop = stackTop->link; // Move to next node (new top).

		delete prevTop; // Delete previous top.

		count--;

		return prevInfo; // Return previous top info.
	}
	else
	{
		std::cout << "Error (pop), cannot pop from an empty stack.\n";
		// Know that in the case of double, you return 0.0
		return static_cast<myType> (0);
	}
}

template <>
std::string linkedStack<std::string>::pop()
{
	nodeType<std::string> *prevTop;
	std::string prevInfo;

	if (stackTop)
	{
		prevTop = stackTop; // Save current top.
		prevInfo = stackTop->info; // Save previous top info.

		stackTop = stackTop->link; // Move to next node (new top).

		delete prevTop; // Delete previous top.

		count--;

		return prevInfo; // Return previous top info.
	}
	else
	{
		std::cout << "Error (pop), cannot pop from an empty stack.\n";
		return "";
	}
}

template <class myType>
int linkedStack<myType>::stackCount() const
{
	return count;
}

template <class myType>
myType linkedStack<myType>::stackSum() const
{
	return rSum(stackTop);
}

template <class myType>
bool linkedStack<myType>::operator==(const linkedStack<myType>& stack)
{
	nodeType<myType> *myNode = stackTop;
	nodeType<myType> *urNode = stack.stackTop;

	if (count != stack.count)
		return false; // shouldn't be different sizes

	while (myNode && urNode)
	{
		if (myNode->info != urNode->info)
			return false;

		myNode = myNode->link;
		urNode = urNode->link;
	}

	return true;
}

template <class myType>
bool linkedStack<myType>::operator!=(const linkedStack<myType>& stack)
{
	return !(*this == stack);
}

template <class myType>
linkedStack<myType> linkedStack<myType>::operator=(const linkedStack<myType>& stack)
{
	copyStack(stack);

	return *this;
}
	
template <class myType>
myType linkedStack<myType>::rSum(nodeType<myType> *top) const
{
	if (!top)
		return 0;
	else
		return rSum(top->link) + top->info;
}

template <class myType>
void linkedStack<myType>::copyStack(const linkedStack<myType>& stack)
{
	nodeType<myType> *node; // to traverse the passed stack
	nodeType<myType> *newNode, *lastNode; // for this stack

	if (stack.count == 0)
	{
		count = 0;
		stackTop = 0;
		return;
	}

	node = stack.stackTop; // refer to the passed stack's top

	// start off the list
	stackTop = new nodeType<myType>;
	stackTop->info = node->info;
	stackTop->link = 0;
	
	lastNode = stackTop;

	while (node->link != 0) // if true then only one node
	{ // else
		node = node->link; // move down passed stack

		newNode = new nodeType<myType>; // make new node
		newNode->info = node->info; // copy passed info
		newNode->link = 0;
		
		lastNode->link = newNode; // set last node link to new node
		lastNode = newNode; // last is now new node
	}

	count = stack.count;
}

#endif // LINKEDSTACK_H