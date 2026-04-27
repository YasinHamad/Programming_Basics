#pragma once

#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <class element_type>
class clsQueueArr
{
private:
	clsDynamicArray<element_type> _array;

public:
	void Push(element_type element) {
		_array.InsertAtEnd(element);
	}

	int Size() { return _array.Size(); }

	element_type Front() {
		return _array.GetItem(0);
	}

	element_type Back() {
		return _array.GetItem(this->Size() - 1);
	}

	void Pop() {
		_array.DeleteFirstItem();
	}

	void Print() {
		_array.Print();
	}

	element_type GetItem(int index) {
		return _array.GetItem(index);
	}

	void Reverse() {
		_array.Reverse();
	}

	bool UpdateItem(int index, element_type data) {
		return _array.SetItem(index, data);
	}

	void InsertAfter(int index, element_type data) {
		_array.InsertAfter(index, data);
	}

	void InsertAtFront(element_type data) {
		_array.InsertAtBeggining(data);
	}

	void InsertAtBack(element_type data) {
		Push(data);
	}

	void Clear() {
		_array.Clear();
	}
};

