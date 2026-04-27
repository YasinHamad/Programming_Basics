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

