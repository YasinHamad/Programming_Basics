# Project 1
What did you learn?
- If you feel that the function may depend on a value in the object in the future, don't make it static. You don't need to rewrite it, there may be a lot of things depend on it.
- Programming is a solution that depends on another solution that depends on another solutions, etc.
- Things depend on each other :) see these two ways of thinking
	We build the basic functions, then use these basic things to build other thinks
```cpp
void _DeleteList(Node*& _head) {
	if (!_head) {
		_size = 0;
		return;
	}
	_DeleteList(_head->next);
	delete _head;
	_head = NULL;
}

void Clear() { 
	while (!IsEmpty()) {
		DeleteFirstNode();
	}
}
```
- We doooon't repeat cooooooooode
```cpp
// code 1
Node* node = GetNode(index);
if (node) return node->data;

// code 2
if (!(index >= 0 && index <= _size - 1)) return NULL;
Node* current = _head;
while (current && index != 0) {
	current = current->data;
	index--;
}
return NULL;
```
- see this
```cpp
templace <typename element_type>
void fun() {
	return element_type{};
	// if int, return 0
	// if bool, return false
	// if string, return ""
}
```
- We build basic things, then use these basic things to build other features.

# Project 2
What did you learn? 
- This is composition, define an object of classx in classy, see this, it is so important
```cpp
#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class element_type>
class clsQueue
{
private:
	clsDblLinkedList<element_type> _list;

public:
	void Push(element_type element) {
		_list.InsertAtEnd(element);
	}

	int Size() { return _list.Size(); }

	element_type Front() {
		return _list.GetItem(0);
	}

	element_type Back() {
		return _list.GetItem(this->Size() - 1);
	}

	void Pop() {
		_list.DeleteFirstNode();
	}
	
	void Print() {
		_list.PrintList();
	}
};
```

# Project 3
Use the Inheritance.
Queue :
```cpp
#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class element_type>
class clsQueue
{
private:
	clsDblLinkedList<element_type> _list;

public:
	void Push(element_type element) {
		_list.InsertAtEnd(element);
	}

	int Size() { return _list.Size(); }

	element_type Front() {
		return _list.GetItem(0);
	}

	element_type Back() {
		return _list.GetItem(this->Size() - 1);
	}

	void Pop() {
		_list.DeleteFirstNode();
	}
	
	void Print() {
		_list.PrintList();
	}

	element_type GetItem(int index) {
		return _list.GetItem(index);
	}
	
	void Reverse() {
		_list.Reverse();
	}

	bool UpdateItem(int index, element_type data) {
		return _list.UpdateItem(index, data);
	}

	bool InsertAfter(int index, element_type data) {
		return _list.InsertAfter(index, data);
	}

	void InsertAtFront(element_type data) {
		_list.InsertAtBeginning(data);
	}

	void InsertAtBack(element_type data) {
		Push(data);
	}

	void Clear() {
		_list.Clear();
	}
};
```
Stack depends on queue :
```cpp
#pragma once

#include <iostream>
#include "clsDblLinkedList.h"
#include "clsQueue.h"

using namespace std;

template <class element_type>
class clsStack : public clsQueue<element_type>
{
public:
	void Push(element_type data) {
		clsQueue<element_type>::InsertAtFront(data);
	}

	element_type Top() {
		return clsQueue<element_type>::Front();
	}

	element_type Bottom() {
		return clsQueue<element_type>::Back();
	}
};
```

