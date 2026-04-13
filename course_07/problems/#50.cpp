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
const string ACCOUNTS_FILE = "accounts.txt";
/* --------------------------------- FUNCTIONS --------------------------------- */
struct stAccount {
	string number;
	string pin_code;
	string name;
	string phone;
	double balance;
	bool mark_as_deleted = false;
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

vector<stAccount> RetriveAccountsData(const string file_name) {
	vector<stAccount> account_records;

	vector<string> account_lines;

	files::LoadDataFromFileToVector(ACCOUNTS_FILE, account_lines);

	for (string& line : account_lines) {
		account_records.push_back(ConvertLineToAccount(line));
	}

	return account_records;
}

void PrintAccounts(vector<stAccount> accounts) {
	
	vector<vector<string>> table_data;

	table_data.push_back({ "Account Number", "Pin Code", "Client Name", "Phone", "Balance" });

	for (stAccount& account : accounts) {
		table_data.push_back
		({
			account.number,
			account.pin_code,
			account.name,
			account.phone,
			to_string(account.balance)
		});
	}
	
	printf("Client List (%d) Client(s)\n", (table_data.size() - 1));

	printers::MakeTable(table_data, printers::enPosition::center, true);
}

bool FindAccountByNumber(string account_number, stAccount& resultant_account) {
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);


	for (stAccount& account : accounts) {
		if (account.number == account_number) {
			resultant_account = account;
			return true;
		}
	}

	return false;
}

bool FindAccountByNumber(string account_number, vector<stAccount> accounts, stAccount& resultant_account) {
	for (stAccount account : accounts) {
		if (account.number == account_number) {
			resultant_account = account;
			return true;
		}
	}
	return false;
}


bool SaveAccountsToFile(const string file_name, vector<stAccount> accounts) {
	fstream my_file;

	my_file.open(file_name, ios::out);

	if (my_file.is_open()) {
		for (stAccount account : accounts) {
			if (!account.mark_as_deleted) {
				my_file << ConvertAccountToLine(account) << endl;
			}
		}

		my_file.close();
		return true;
	}
	return false;
}

bool MarkAsDeleted(vector<stAccount>& accounts, stAccount account) {
	for (stAccount& acc : accounts) {
		if (acc.number == account.number) {
			acc.mark_as_deleted = true;
			return true;
		}
	}
	return false;
}


bool DeleteAccountByNumber(string account_number) {
	stAccount account;
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);
	char flag = 'n';

	if (FindAccountByNumber(account_number, accounts, account)) {
		cout << "Are you sure you want to delete this account:\n\n";

		PrintAccount(account);
		
		cout << "\n[y/n]: ";
		cin >> flag;

		if (tolower(flag) == 'y') {
			return (MarkAsDeleted(accounts, account) && SaveAccountsToFile(ACCOUNTS_FILE, accounts));
		}
		else {
			cout << "The process has been canceled\n";
			return false;
		}
	}
	cout << "The account does not exist!\n";
	return false;
}

void PerformDeleteAccount() {
	string account_number = "";

	cout << "Enter the account number you want to delte: ";
	cin >> account_number;

	if (DeleteAccountByNumber(account_number)) {
		cout << "Account successfuly deleted" << endl;
	}
	//else PerformDeleteAccount();
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
		
		PrintAccounts(RetriveAccountsData(ACCOUNTS_FILE));
		
		PerformDeleteAccount();

		PrintAccounts(RetriveAccountsData(ACCOUNTS_FILE));

				
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */

						
						
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}