#pragma once

#include <iostream>
#include "clsQueueArr.h"

using namespace std;

template <class element_type>
class clsStackArr : public clsQueueArr<element_type>
{
public:
	void Push(element_type data) {
		clsQueueArr<element_type>::InsertAtFront(data);
	}

	element_type Top() {
		return clsQueueArr<element_type>::Front();
	}

	element_type Bottom() {
		return clsQueueArr<element_type>::Back();
	}
};

