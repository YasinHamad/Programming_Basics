#include <iostream>
#include <cmath>
#include <string> // to use the string object
#include <cstdlib>
#include <vector>
#include <cctype> // isupper(), isdigit()
#include <iomanip> // for setw()
//#include <fstream> // for files
//#include <ctime> // for time
#include <print>


//#include <sstream> // for ostringstream oss;

#include "readers.h"
#include "printers.h"
#include "converters.h"
#include "files.h"
#include "datetime.h"
#include "generators.h"
#include "allocators.h"
#include "fillers.h"
#include "manipulators.h"

using namespace std;

#define SIZE 50

class clsCalculator {
private:
	enum enOperationType {AddOperation=0, SubtractOperation =1, MultiplyOperation =2, DivideOperation =3, ModeOperation=4};

	struct stOperation {
		enOperationType operationType;
		int number;
		int result;
		int previous_result;
	};

	vector<stOperation> operations;

	string OperationTypeToString(enOperationType operationType) {
		string operationTypes[] = { "adding", "subtracting", "multiplying", "dividing", "mode"};
		return operationTypes[operationType];
	}

	string GetOperationSign(enOperationType operationType) {
		string operationTypes[] = { "+", "-", "*", "/", "%"};
		return operationTypes[operationType];
	}


	void AddAnOperation(enOperationType operationType, int number, int previous_result, int result) {
		stOperation new_operation;
		
		new_operation.operationType = operationType;
		new_operation.result = result;
		new_operation.number = number;
		new_operation.previous_result = previous_result;

		operations.push_back(new_operation);
	}

	int GetLastResult() {
		if (operations.empty()) return 0;
		else {
			stOperation operation = operations.back();
			return operation.result;
		}
	}
	
	int Calculate(int number1, int number2, enOperationType operationType) {
		switch (operationType) {
		case enOperationType::AddOperation: return number1 + number2;
		case enOperationType::MultiplyOperation: return number1 * number2;
		case enOperationType::DivideOperation: return number1 / number2;
		case enOperationType::SubtractOperation: return number1 - number2;
		case enOperationType::ModeOperation: return number1 % number2;
		}
	}

	void PerformOperation(enOperationType operationType, int number) {
		int last_result = GetLastResult();

		AddAnOperation(operationType, number, last_result,
			Calculate(last_result, number, operationType));
	}

	void PrintOperation(stOperation operation) {
		cout << "Result after " << OperationTypeToString(operation.operationType)
						<< " " << operation.number << " is : " << operation.result << "\n";
	}

public:
	void PrintResults() {
		vector<vector<string>> table_data;

		table_data.push_back(
			{"Operation", "Result"}
			);

		for (stOperation& operation : operations) {
			string row = to_string(operation.previous_result) +
				GetOperationSign(operation.operationType) +
				to_string(operation.number);
			
			table_data.push_back({ row, to_string(operation.result) });
		}

		printers::MakeTable(table_data, printers::enPosition::center, true);
	}

	void PrintResult() {
		if (operations.empty()) {
			cout << "Result after clearing is : 0" << "\n";
		}
		else {
			PrintOperation(operations.back());
		}
	}

	void Add(int number) {
		PerformOperation(enOperationType::AddOperation, number);
	}

	void Subtract(int number) {
		PerformOperation(enOperationType::SubtractOperation, number);
	}

	void Multiply(int number) {
		PerformOperation(enOperationType::MultiplyOperation, number);
	}

	void Divide(int number) {
		if (number == 0) number = 1;
		PerformOperation(enOperationType::DivideOperation, number);
	}

	void Mode(int number) {
		PerformOperation(enOperationType::ModeOperation, number);
	}

	void Clear() {
		operations.clear();
	}

	void CancelLastOperation() {
		if(!operations.empty()) operations.pop_back();
	}
};

int main()
{
	clsCalculator calculator;

	calculator.Clear();

	calculator.Add(10);
	calculator.PrintResult();

	calculator.Add(100);
	calculator.PrintResult();

	calculator.Subtract(20);
	calculator.PrintResult();

	calculator.Divide(0);
	calculator.PrintResult();

	calculator.Divide(2);
	calculator.PrintResult();

	calculator.CancelLastOperation();
	calculator.PrintResult();

	calculator.Multiply(3);
	calculator.PrintResult();

	cout << "\n";
	calculator.PrintResults();
	cout << "\n";

	calculator.Clear();
	calculator.PrintResult();
	cout << "\n";
	calculator.PrintResults();
	cout << "\n";
}