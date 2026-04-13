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
/* --------------------------------- FUNCTIONS --------------------------------- */
struct stAccount {
	string number;
	string pin_code;
	string name;
	string phone;
	double balance;
};

stAccount ReadNewAccount() {
	stAccount account;

	cout << "Enter account number: ";
	getline(cin, account.number);

	cout << "Enter pin code: ";
	getline(cin, account.pin_code);

	cout << "Enter name: ";
	getline(cin, account.name);

	cout << "Enter phone: ";
	getline(cin, account.phone);

	cout << "Enter account balance: ";
	cin >> account.balance;
	cin.ignore(1, '\n');

	return account;
}

string ConvertAccountToLine(const stAccount& account, string separator = "#||#") {
	vector<string> data;

	data.push_back(account.number);
	data.push_back(account.pin_code);
	data.push_back(account.name);
	data.push_back(account.phone);
	data.push_back(to_string(account.balance));
	
	return manipulators::string_utilities::JoinString(data, separator);
}

stAccount ConvertLineToAccount(string line, string separator = "#||#") {
	stAccount account;
	vector<string> data = manipulators::string_utilities::Split(line, separator);

	account.number = data.at(0);
	account.pin_code = data.at(1);
	account.name = data.at(2);
	account.phone = data.at(3);
	account.balance = stod(data.at(4));

	return account;
}

void PrintAccount(const stAccount& account) {
	cout << "Account number : " << account.number << "\n";
	cout << "Pin code       : " << account.pin_code << "\n";
	cout << "Name           : " << account.name << "\n";
	cout << "Phone          : " << account.phone << "\n";
	cout << "Account balance: " << account.balance << "\n";
}

bool AddAccountToFile(const string file_name, string line) {
	fstream my_file;

	my_file.open(file_name, ios::out | ios::app);

	if (my_file.is_open()) {
		if(line.length() != 0) my_file << line << endl;
		
		my_file.close();

		return true;
	}
	return false;
}

void AddNewAccount() {
	stAccount account;
	account = ReadNewAccount();
	AddAccountToFile("accounts.txt", ConvertAccountToLine(account));
}

void AddAccounts() {
	char add_more = 'y';
	while (tolower(add_more) == 'y') {
		system("cls");
		cout << "Adding new account: \n\n";	

		AddNewAccount();

		cout << "Account added successfully, do you want to add more?[y/n]: ";
		cin >> add_more;
		cin.ignore(1, '\n');
	}
}















/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		//string test_str = readers::ReadASentence("Enter a message please: ");
		//string test_str = "my name is actaully yasin, yasin is my first name, yes yasin";
		//char c = readers::ReadChar("Enter your char: ");
		//char* arr = NULL;
		//int arr_size = 0;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		AddAccounts();
		
		

		//cout << manipulators::string_utilities::RemovePunctuations(test_str) << endl;


				
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */

						
						
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}