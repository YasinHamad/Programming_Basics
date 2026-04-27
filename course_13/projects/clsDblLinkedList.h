#pragma once

template <class element_type>
class clsDblLinkedList
{
public:
	class Node {
	public:
		element_type data;
		Node* next;
		Node* prev;
	};

private:
	Node* _head = NULL;
	int _size = 0;

public:
	void PrintList() {
		Node* _head = this->_head;

		cout << "NULL <-> ";

		while (_head) {
			cout << "[ " << _head->data << " ]" << " <-> ";
			_head = _head->next;
		}

		cout << "\b\b\b\b<-> NULL" << "\n";
	}

	void InsertAtBeginning(element_type data) {
		Node* new_node = new Node();
		new_node->data = data;
		new_node->next = _head;
		new_node->prev = NULL;
		if (_head) _head->prev = new_node;
		_head = new_node;
		_size++;
	}

	Node* Find(element_type data) {
		Node* _head = this->_head;
		while (_head) {
			if (_head->data == data) return _head;
			_head = _head->next;
		}
		return NULL;
	}

	void InsertAfter(Node* node, element_type data) {
		if (!node) return;
		Node*& _head = node->next;

		Node* new_node = new Node();
		new_node->data = data;
		new_node->next = _head;
		new_node->prev = NULL;
		if (_head) _head->prev = new_node;
		_head = new_node;
		_size++;

		node->next->prev = node;
	}

	void InsertAtEnd(element_type data) {
		Node** head_ref = &this->_head;

		Node* new_node = new Node();
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = NULL;
		Node* previous = NULL;

		while (*head_ref) {
			previous = *head_ref;
			head_ref = &((*head_ref)->next);
		}
		*head_ref = new_node;
		new_node->prev = previous;
		_size++;
	}

	void DeleteNode(element_type data) {
		Node** head_ref = &this->_head;
		if (!*head_ref) return;

		while (*head_ref && (*head_ref)->data != data) {
			head_ref = &((*head_ref)->next);
		}
		if (!*head_ref) return;

		Node* node_to_delete = *head_ref;

		if ((*head_ref)->next)
			(*head_ref)->next->prev = (*head_ref && (*head_ref)->prev) ? (*head_ref)->prev : NULL;

		(*head_ref) = (*head_ref) && (*head_ref)->next ? (*head_ref)->next : NULL;

		delete node_to_delete;
		_size--;
	}

	void DeleteFirstNode() {
		if (!_head) return;
		Node* node_to_delete = _head;
		if (_head->next)	_head->next->prev = NULL;
		_head = (_head->next) ? _head->next : NULL;
		delete node_to_delete;
		_size--;
	}

	void DeleteLastNode() {
		Node* head = _head;
		if (!head) return;
		while (head->next && head->next->next) {
			head = head->next;
		}

		if (!head->next) {
			delete head;
			_size--;
			_head = NULL;
			return;
		}

		delete head->next;
		head->next = NULL;
		_size--;
	}

	int Size() { return _size; }

	bool IsEmpty() { return _size == 0; }

	void Clear() { 
		while (!IsEmpty()) {
			DeleteFirstNode();
		}
	}

	void Reverse() {
		Node* current = _head;
		Node* temp = nullptr;

		while (current) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			if (!current->prev) {
				_head = current;
				return;
			}
			current = current->prev;
		}
	}

	Node* GetNode(int index) {
		if (!(index >= 0 && index <= _size - 1)) return NULL;
		Node* current = _head;
		while (current && index != 0) {
			current = current->next;
			index--;
		}
		return current;
	}

	element_type GetItem(int index) {
		Node* node = GetNode(index);
		return node ? node->data : element_type{};
	}

	bool UpdateItem(int index, element_type data) {
		Node* node = GetNode(index);
		if (node) {
			node->data = data;
			return true;
		}
		return false;
	}

	bool InsertAfter(int index, element_type data) {
		Node* node = this->GetNode(index);
		if (node) {
			InsertAfter(node, data);
			return true;
		}
		return false;
	}
};
