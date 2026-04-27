#pragma once

#include <iostream>
#include <string>

#include "clsStack.h"

using namespace std;

class clsMyString
{
private:
	string _Value;
	clsStack<string> _Stack_Undo;
	clsStack<string> _Stack_Redo;

public:
	clsMyString(string Value = "") {
		this->Value = Value;
	}

	string GetValue() { return _Value; }
	void SetValue(string Value) { 
		_Stack_Undo.Push(Value);
		this->_Value = Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	void Redo() {
		if (!_Stack_Redo.IsEmpty()) {
			_Value = _Stack_Redo.Top();
			_Stack_Undo.Push(_Value);
			_Stack_Redo.Pop();
		}
	}

	void Undo() {
		if (!_Stack_Undo.IsEmpty()) {
			_Stack_Redo.Push(_Value);
			_Stack_Undo.Pop();
			_Value = _Stack_Undo.Top();
		}
	}
};

