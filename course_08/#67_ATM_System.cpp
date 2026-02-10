#include <iostream>
#include <cmath>
#include <string> 
#include <cstdlib>
#include <vector>
#include <cctype> 
#include <iomanip>


/* --------------------------------- MY LIBRARIES --------------------------------- */
#include "readers.h"
#include "printers.h"
#include "converters.h"
#include "files.h"
#include "datetime.h"
#include "generators.h"
#include "allocators.h"
#include "fillers.h"
#include "manipulators.h"
/* --------------------------------- MY LIBRARIES --------------------------------- */

using namespace std;

/* --------------------------------- STRUCTURES --------------------------------- */
struct stAccount {
	string number;
	string pin_code;
	string name;
	string phone;
	double balance;
	bool mark_as_deleted = false;
};
/* --------------------------------- STRUCTURES --------------------------------- */
/* --------------------------------- GLOBAL VARIABLES --------------------------------- */
const int LINE_WIDTH = 50;
const string ACCOUNTS_FILE = "accounts.txt";
stAccount CURRENT_CLIENT;
/* --------------------------------- GLOBAL VARIABLES --------------------------------- */
/* --------------------------------- ENUMS --------------------------------- */
enum enATMOption {
	QuickWithdrawOption = 1, NormalWithdrawOption = 2, DepositOption = 3, CheckBalanceOption = 4, LogoutOption = 5
};
enum enQuickWithdrawOption {
	_20_Option=1, _50_Option=2, _100_Option=3, _200_Option=4, _400_Option=5, 
	_600_Option=6, _800_Option=7, _1000_Option=8, ExitQuickWithdrawOption=9
};
/* --------------------------------- ENUMS --------------------------------- */
/* --------------------------------- DECLARE FUNCTIONS --------------------------------- */
void PrintHeader(string message, char line_char, int line_width);
stAccount ConvertLineToAccount(string line, string separator = "#||#");
vector<stAccount> RetriveAccountsData(const string file_name);
void ShowMainMenueScreen();
void BackToMainMenueScreen();
string ConvertAccountToLine(const stAccount& account, string separator = "#||#");
bool SaveAccountsToFile(const string file_name, vector<stAccount> accounts);
bool UpdateAccountInVector(vector<stAccount>& accounts, stAccount account);
void DepositTransaction();
void ExitProgram();
void ShowLoginScreen();
/* --------------------------------- DECLARE FUNCTIONS --------------------------------- */
/* --------------------------------- FUNCTIONS --------------------------------- */

// this procedure prints the header of the screen
void PrintHeader(string message, char line_char, int line_width) {
	printers::PrintChar(line_char, line_width);
	cout << "\n";

	cout << printers::FormatedCout(line_width, message, printers::enPosition::center);
	cout << "\n";

	printers::PrintChar(line_char, line_width);
	cout << endl;
}

// this function convert a line of data to stAccount
stAccount ConvertLineToAccount(string line, string separator) {
	stAccount account;
	vector<string> data = manipulators::string_utilities::Split(line, separator);

	account.number = data.at(0);
	account.pin_code = data.at(1);
	account.name = data.at(2);
	account.phone = data.at(3);
	account.balance = stod(data.at(4));

	return account;
}

// this function returns all accounts(those are in the file) as vector of stAccount
vector<stAccount> RetriveAccountsData(const string file_name) {
	vector<stAccount> account_records;

	vector<string> account_lines;

	files::LoadDataFromFileToVector(file_name, account_lines);

	for (string& line : account_lines) {
		account_records.push_back(ConvertLineToAccount(line));
	}

	return account_records;
}

// this function takes an stAccount variable and returns it as one line of string
string ConvertAccountToLine(const stAccount& account, string separator) {
	vector<string> data;

	data.push_back(account.number);
	data.push_back(account.pin_code);
	data.push_back(account.name);
	data.push_back(account.phone);
	data.push_back(to_string(account.balance));

	return manipulators::string_utilities::JoinString(data, separator);
}

// this function saves vector of stAccounts to the file
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

// this function updates the passed account in the passed vector of accounts
bool UpdateAccountInVector(vector<stAccount>& accounts, stAccount account) {
	for (stAccount& acc : accounts) {
		if (acc.number == account.number) {
			acc = account;
			return true;
		}
	}
	return false;
}

// this function fires the exit feature
void ExitProgram() {
	//system("cls");

	//PrintHeader("Program Ends :-)", '-', LINE_WIDTH);
	//cout << endl;

	//cout << "\n\nPress any key to end the program . . .";
	//system("pause>0");
	ShowLoginScreen();
}

// this function allows the user to back to the main menue screen
void BackToMainMenueScreen() {
	cout << "\n\nPress any key to go back . . .";
	system("pause>0");

	ShowMainMenueScreen();
}

// this function communicates with the user to withdraw from their account
bool PerformQuickWithdrawTransaction(double withdraw) {
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);
	char flag = 'n';

	while (withdraw > CURRENT_CLIENT.balance) {
		cout << "Amount exceeds the balance, you can withdraw up to [" << CURRENT_CLIENT.balance << "]\n";
		return false;
	}

	cout << "Are you sure you want to perform this trnsaction? [y/n]: ";
	cin >> flag;
	if (tolower(flag) == 'y') {
		CURRENT_CLIENT.balance -= withdraw;
		UpdateAccountInVector(accounts, CURRENT_CLIENT);
		SaveAccountsToFile(ACCOUNTS_FILE, accounts);
		cout << "\nAccount successfully updated\n";
		cout << "The new balance for client [" << CURRENT_CLIENT.number << "]" << " is [" << CURRENT_CLIENT.balance << "]" << endl;
		return true;
	}
	else {
		cout << "The process has been canceled\n";
	}
	return false;
}

int GetAmount(enQuickWithdrawOption option) {
	switch (option) {
	case _20_Option:return 20;
	case _50_Option:return 50;
	case _100_Option:return 100;
	case _200_Option:return 200;
	case _400_Option:return 400;
	case _600_Option:return 600;
	case _800_Option:return 800;
	case _1000_Option:return 1000;
	default: return -1;
	}
}

void ShowNormalWithdraw() {
	system("cls");
	PrintHeader("Normal Withdraw Screen", '-', LINE_WIDTH);
	cout << "Your balance is " << CURRENT_CLIENT.balance << "\n";

	int withdraw = 0;

	do {
		withdraw = readers::ReadPositiveNumber("\nEnter an amount multiple of 5: ");
	} while ((withdraw%5) != 0 || (withdraw<5) || !PerformQuickWithdrawTransaction(withdraw));

	BackToMainMenueScreen();
}

// this function fires the quick withdraw feature
void ShowQuickWithdraw() {
	system("cls");

	vector<string> messages;
	messages.push_back("[1] 20		[2] 50");
	messages.push_back("[3] 100		[4] 200");
	messages.push_back("[5] 400		[6] 600");
	messages.push_back("[7] 800		[8] 1000");
	messages.push_back("[9] Exit");

	PrintHeader("Quick Withdraw Screen", '-', LINE_WIDTH);

	for (string& message : messages) {
		cout << "\t" << message << "\n";
	}

	printers::PrintChar('-', LINE_WIDTH);
	cout << endl;
	cout << "Your balance is " << CURRENT_CLIENT.balance << "\n";

	enQuickWithdrawOption option;
	do {
		option = (enQuickWithdrawOption)readers::ReadPositiveNumberInRange("Choose what you want to do[1 to 9]: ", 1, 9);
		if (option == enQuickWithdrawOption::ExitQuickWithdrawOption) return ShowMainMenueScreen();
	} while (!PerformQuickWithdrawTransaction(GetAmount(option)));

	BackToMainMenueScreen();
}

// this function communicates with the user to deposit from their account
void DepositTransaction() {
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);
	double deposite = 0.0;
	char flag = 'n';

	deposite = readers::ReadPositiveDoubleNumber("Enter a positive deposite amount: ");

	cout << "Are you sure you want to perform this trnsaction? [y/n]: ";
	cin >> flag;
	if (tolower(flag) == 'y') {
		CURRENT_CLIENT.balance += deposite;
		UpdateAccountInVector(accounts, CURRENT_CLIENT);
		SaveAccountsToFile(ACCOUNTS_FILE, accounts);
		cout << "\nAccount successfully updated\n";
		cout << "The new balance for client [" << CURRENT_CLIENT.number << "]" << " is [" << CURRENT_CLIENT.balance << "]" << endl;
	}
	else {
		cout << "The process has been canceled\n";
	}
}

void ShowDeposit() {
	system("cls");
	PrintHeader("Deposit Screen", '-', LINE_WIDTH);
	cout << "Your balance is " << CURRENT_CLIENT.balance << "\n\n";
	DepositTransaction();
	BackToMainMenueScreen();
}

void ShowCheckBalance() {
	system("cls");
	PrintHeader("Check Balance Screen", '-', LINE_WIDTH);
	cout << "Your balance is " << CURRENT_CLIENT.balance << "\n";
	BackToMainMenueScreen();
}

// this function chooses the appropriate function to call in the main menue in the main menue screen
void PerformAction(enATMOption option) {
	switch (option) {
	case enATMOption::QuickWithdrawOption: return ShowQuickWithdraw();
	case enATMOption::NormalWithdrawOption: return ShowNormalWithdraw();
	case enATMOption:: DepositOption: return ShowDeposit();
	case enATMOption::CheckBalanceOption: return ShowCheckBalance();
	case enATMOption::LogoutOption: return ExitProgram();
	default: return ShowMainMenueScreen();
	}
}

// this function displays the main menue features on the screen
void ShowMainMenueScreen() {
	system("cls");

	vector<string> messages;
	messages.push_back("[1] Quick Withdraw.");
	messages.push_back("[2] Normal Withdraw.");
	messages.push_back("[3] Deposit.");
	messages.push_back("[4] Check Balance.");
	messages.push_back("[5] Logout.");

	PrintHeader("ATM Main Menue Screen", '=', LINE_WIDTH);

	for (string& message : messages) {
		cout << "\t" << message << "\n";
	}

	printers::PrintChar('=', LINE_WIDTH);
	cout << endl;

	PerformAction((enATMOption)readers::ReadPositiveNumberInRange("Choose what you want to do [1 to 5]: ", 1, 5));
}

bool FindClient(string number, string pin_code, stAccount& account) {
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);

	for (stAccount& _account : accounts) {
		if (number == _account.number && pin_code == _account.pin_code) {
			account = _account;
			return true;
		}
	}
	return false;
}

// perform the login process
void ShowLoginScreen() {
	string number;
	string pin_code;
	bool flag = false;

	do {
		system("cls");
		PrintHeader("Login Screen", '=', LINE_WIDTH);

		if (flag) {
			cout << "Invalid Name/Pin!" << "\n";
		}
		if(!flag) flag = true;

		number = readers::ReadASentence("Enter number: ");
		pin_code = readers::ReadASentence("Enter pin code: ");

	} while (!FindClient(number, pin_code, CURRENT_CLIENT));
	ShowMainMenueScreen();
}

/* --------------------------------- FUNCTIONS --------------------------------- */

int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */

		ShowLoginScreen();

		/* --------------------------------- CODE --------------------------------- */
		break;
	}
}

