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

	bool IsEmpty() {
		return _list.IsEmpty();
	}

	void Clear() {
		_list.Clear();
	}
};

