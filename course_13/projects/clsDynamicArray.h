#pragma once

#include <iostream>

template <typename element_type>
class clsDynamicArray
{
private:
	int _Size = 0;
	element_type* array;

	void _CopyElements(int number, element_type* new_array) {
		for (int i = 0; i < number; i++) {
			new_array[i] = array[i];
		}
	}

public:
	clsDynamicArray(int size = 0) {
		this->_Size = size >= 0 ? size : 0;
		array = new element_type[size];
	}
	~clsDynamicArray() {
		delete[] array;
	}

	bool SetItem(int index, element_type data) {
		if (!(index >= 0 && index < _Size)) return false;
		array[index] = data;
		return true;
	}

	bool IsEmpty() {
		return _Size == 0;
	}

	int Size() {
		return _Size;
	}

	void Print() {
		for (int i = 0; i < _Size; i++) {
			cout << "[" << i << "] " << array[i] << "\n";
		}
	}

	bool Resize(int size) {
		if (size < 0) return false;
		element_type* new_array = new element_type[size];
		_CopyElements(size < _Size ? size : _Size, new_array);
		_Size = size;
		delete[] array;
		array = new_array;
	}

	element_type GetItem(int index) {
		if (!(index >= 0 && index < _Size)) return element_type{};
		return array[index];
	}

	void Reverse() {
		for (int i = 0, j = Size() - 1; i < j; i++, j--) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	void Clear() {
		Resize(0);
	}

	void DeleteItemAt(int index) {
		if (!(index >= 0 && index < _Size)) return;
		for (int i = index; i < _Size - 1; i++) {
			array[i] = array[i + 1];
		}
		_Size--;
	}

	void DeleteFirstItem() {
		DeleteItemAt(0);
	}

	void DeleteLastItem() {
		DeleteItemAt(Size() - 1);
	}

	int Find(element_type data) {
		for (int i = 0; i < _Size; i++) {
			if (data == array[i]) return i;
		}
		return -1;
	}
	
	void DeleteItem(element_type data) {
		int index = Find(data);
		if (index == -1) return;
		DeleteItemAt(index);
	}

	void InsertAt(int index, element_type data) {
		//if (!(index >= 0 && index < _Size)) return;
		element_type* new_array = new element_type[_Size + 1];

		int i = 0;
		for (; i < index; i++) {
			new_array[i] = array[i];
		}

		new_array[i] = data;

		i++;
		for (; i - 1 < _Size; i++) {
			new_array[i] = array[i - 1];
		}

		delete[] array;
		array = new_array;
		_Size++;
	}

	void InsertAtBeggining(element_type data) {
		InsertAt(0, data);
	}
	
	void InsertBefore(int index, element_type data) {
		index = index < 0 ? 1 : index;
		InsertAt(index - 1, data);
	}

	void InsertAfter(int index, element_type data) {
		index = index >= _Size ? _Size - 1 : index;
		InsertAt(index + 1, data);
	}

	void InsertAtEnd(element_type data) {
		_Size++;
		InsertAt(_Size - 1, data);
		_Size--;
	}
};

