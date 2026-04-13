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

/* --------------------------------- GLOBAL VARIABLES --------------------------------- */
const int LINE_WIDTH = 50;
const string ACCOUNTS_FILE = "accounts.txt";
/* --------------------------------- GLOBAL VARIABLES --------------------------------- */
/* --------------------------------- ENUMS --------------------------------- */
enum enOptions {
	ShowClientListOption = 1, AddNewClientOption = 2, DeleteClientOption = 3,
	UpdataClientInfoOption = 4, FindClientOption = 5, TransactionsOption = 6, ExitOption = 7
};
enum enTransactionOption {
	DepositeOption = 1, WithdrawOption = 2, TotalBalancesOption = 3, MainMenueOption = 4
};
/* --------------------------------- ENUMS --------------------------------- */
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
/* --------------------------------- DECLARE FUNCTIONS --------------------------------- */
void PrintHeader(string message, char line_char, int line_width);
stAccount ConvertLineToAccount(string line, string separator = "#||#");
vector<stAccount> RetriveAccountsData(const string file_name);
void PrintAccounts(vector<stAccount> accounts);
void ShowClientList();
void PerformAction(enOptions option);
void ShowMainMenueScreen();
void BackToMainMenueScreen();
void AddNewAccount();
stAccount ReadNewAccount();
bool AddAccountToFile(const string file_name, string line);
string ConvertAccountToLine(const stAccount& account, string separator = "#||#");
bool IsAccountNumberExists(string account_number);
void AddNewClient();
void DeleteClient();
void PerformDeleteAccount();
bool DeleteAccountByNumber(string account_number);
bool FindAccountByNumber(string account_number, stAccount& resultant_account);
bool FindAccountByNumber(string account_number, vector<stAccount> accounts, stAccount& resultant_account);
void PrintAccount(const stAccount& account);
bool SaveAccountsToFile(const string file_name, vector<stAccount> accounts);
bool MarkAsDeleted(vector<stAccount>& accounts, stAccount account);
void UpdateAccountData(stAccount& account);
bool UpdateAccountByNumber(string account_number);
void PerformUpdateAccount();
bool UpdateAccountInVector(vector<stAccount>& accounts, stAccount account);
void UpdateClient();
void ShowTransactionsMenueScreen();
void PerformTransaction(enTransactionOption option);
void PerformDepositTransaction();
void BackToTransactionMenueScreen();
void DepositTransaction();
void PrintAccountBalances(vector<stAccount> accounts);
void WithdrawTransaction();
void PerformWithdrawTransaction();
void FindClient();
void ExitProgram();
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

// this function print accounts in table
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

	printf("\nClient List [%d] Client(s)\n", (table_data.size() - 1));

	printers::MakeTable(table_data, printers::enPosition::center, true);
}

// this function checks whether an account exist or not
bool IsAccountNumberExists(string account_number) {
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);

	for (stAccount& account : accounts) {
		if (account.number == account_number) return true;
	}
	return false;
}

// this function reads the data of an account from the screen and returns stAccount
stAccount ReadNewAccount() {
	stAccount account;

	cout << "Enter account number: ";
	getline(cin >> std::ws, account.number);
		
	while (IsAccountNumberExists(account.number)) {
		cout << "Client with [" << account.number << "] already exists, enter another number: ";
		getline(cin >> std::ws, account.number);
	}

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

// this function append a new line to the file passed
bool AddAccountToFile(const string file_name, string line) {
	fstream my_file;

	my_file.open(file_name, ios::out | ios::app);

	if (my_file.is_open()) {
		if (line.length() != 0) my_file << line << endl;

		my_file.close();

		return true;
	}
	return false;
}

// this function takes an stAccount variable and returns it as on line of string
string ConvertAccountToLine(const stAccount& account, string separator) {
	vector<string> data;

	data.push_back(account.number);
	data.push_back(account.pin_code);
	data.push_back(account.name);
	data.push_back(account.phone);
	data.push_back(to_string(account.balance));

	return manipulators::string_utilities::JoinString(data, separator);
}

// this function marks an stAccount variable as deleted by setting `mark_as_deleted=true`
// when saving the vector to the file, this account will not be saved
bool MarkAsDeleted(vector<stAccount>& accounts, stAccount account) {
	for (stAccount& acc : accounts) {
		if (acc.number == account.number) {
			acc.mark_as_deleted = true;
			return true;
		}
	}
	return false;
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

// this function prints an account on the screen
void PrintAccount(const stAccount& account) {
	cout << "The following are the account details: \n";
	printers::PrintChar('-', LINE_WIDTH);
	cout << "\n";
	cout << "Account number : " << account.number << "\n";
	cout << "Pin code       : " << account.pin_code << "\n";
	cout << "Name           : " << account.name << "\n";
	cout << "Phone          : " << account.phone << "\n";
	cout << "Account balance: " << account.balance << "\n";
	printers::PrintChar('-', LINE_WIDTH);
	cout << endl;
}

// this function checks if the account exists in the file
bool FindAccountByNumber(string account_number, vector<stAccount> accounts, stAccount& resultant_account) {
	for (stAccount account : accounts) {
		if (account.number == account_number) {
			resultant_account = account;
			return true;
		}
	}
	return false;
}

// this function checks if the account exists in the file
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

// this function deletes an account from the file
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
	cout << "The account [" << account_number << "] does not exist!\n";
	return false;
}

// this function fires the update account feature
void PerformUpdateAccount() {
	string account_number = "";

	cout << "Enter the account number you want to update: ";
	cin >> account_number;

	if (UpdateAccountByNumber(account_number)) {
		cout << "Account successfully updated" << endl;
	}
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

// this function reads from the screen the new account's data
void UpdateAccountData(stAccount& account) {
	cout << "Enter pin code: ";
	getline(cin >> std::ws, account.pin_code);

	cout << "Enter name: ";
	getline(cin, account.name);

	cout << "Enter phone: ";
	getline(cin, account.phone);

	cout << "Enter account balance: ";
	cin >> account.balance;
	cin.ignore(1, '\n');
}

// this function update account's fields by number
bool UpdateAccountByNumber(string account_number) {
	stAccount account;
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);
	char flag = 'n';

	if (FindAccountByNumber(account_number, accounts, account)) {
		cout << "Are you sure you want to update this account:\n\n";

		PrintAccount(account);

		cout << "\n[y/n]: ";
		cin >> flag;

		if (tolower(flag) == 'y') {
			UpdateAccountData(account);

			return (UpdateAccountInVector(accounts, account) && SaveAccountsToFile(ACCOUNTS_FILE, accounts));
		}
		else {
			cout << "The process has been canceled\n";
			return false;
		}
	}
	cout << "The account [" << account_number << "] does not exist!\n";
	return false;
}

// this function fires the delete account features
void PerformDeleteAccount() {
	string account_number = "";

	cout << "Enter the account number you want to delte: ";
	cin >> account_number;

	if (DeleteAccountByNumber(account_number)) {
		cout << "Account successfuly deleted" << endl;
	}
}

// this function communicates with the user to deposit from their account
void DepositTransaction() {
	string account_number = "";
	stAccount account;
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);
	double deposite = 0.0;
	char flag = 'n';

	cout << "Enter the account number: ";
	cin >> account_number;

	while (!FindAccountByNumber(account_number, accounts, account)) {
		cout << "The account [" << account_number << "] does not exist!\n\n";
		cout << "Enter another account number: ";
		cin >> account_number;
	}

	cout << "\n";
	PrintAccount(account);

	cout << "\n";
	deposite = readers::ReadPositiveDoubleNumber("Enter deposite amount: ");

	cout << "Are you sure you want to perform this trnsaction? [y/n]: ";
	cin >> flag;
	if (tolower(flag) == 'y') {
		account.balance += deposite;
		UpdateAccountInVector(accounts, account);
		SaveAccountsToFile(ACCOUNTS_FILE, accounts);
		cout << "\nAccount successfully updated\n";
		cout << "The new balance for client [" << account.number << "]" << " is [" << account.balance << "]" << endl;;
	}
	else {
		cout << "The process has been canceled\n";
	}
}

// this function communicates with the user to withdraw from their account
void WithdrawTransaction() {
	string account_number = "";
	stAccount account;
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);
	double withdraw = 0.0;
	char flag = 'n';

	cout << "Enter the account number: ";
	cin >> account_number;

	while (!FindAccountByNumber(account_number, accounts, account)) {
		cout << "The account [" << account_number << "] does not exist!\n\n";
		cout << "\nEnter another account number: ";
		cin >> account_number;
	}

	cout << "\n";
	PrintAccount(account);

	cout << "\n";
	withdraw = readers::ReadPositiveDoubleNumber("Enter withdraw amount: ");

	while (withdraw > account.balance) {
		cout << "Amount exceeds the balance, you can withdraw up to [" << account.balance << "]\n";
		withdraw = readers::ReadPositiveDoubleNumber("\nEnter another amount: ");
	}

	cout << "Are you sure you want to perform this trnsaction? [y/n]: ";
	cin >> flag;
	if (tolower(flag) == 'y') {
		account.balance -= withdraw;
		UpdateAccountInVector(accounts, account);
		SaveAccountsToFile(ACCOUNTS_FILE, accounts);
		cout << "\nAccount successfully updated\n";
		cout << "The new balance for client [" << account.number << "]" << " is [" << account.balance << "]" << endl;;
	}
	else {
		cout << "The process has been canceled\n";
	}
}

// this function fires the deposit feature
void PerformDepositTransaction() {
	system("cls");

	PrintHeader("Deposit Screen", '-', LINE_WIDTH);
	cout << endl;

	DepositTransaction();

	BackToTransactionMenueScreen();
}

// this function fires the withdraw feature
void PerformWithdrawTransaction() {
	system("cls");

	PrintHeader("Withdraw Screen", '-', LINE_WIDTH);
	cout << endl;

	WithdrawTransaction();

	BackToTransactionMenueScreen();
}

// this function prints acount numbers, names, and balances
void PrintAccountBalances(vector<stAccount> accounts) {

	vector<vector<string>> table_data;
	double total = 0.0;

	table_data.push_back({ "Account Number", "Client Name", "Balance" });

	for (stAccount& account : accounts) {
		table_data.push_back
		({
			account.number,
			account.name,
			to_string(account.balance)
			});
		total += account.balance;
	}

	printf("\nBalances List [%d] Client(s)\n", (table_data.size() - 1));

	printers::MakeTable(table_data, printers::enPosition::center, true);

	printf("Total balances = [%f]\n", total);
}

// this function fires the total balances feature
void ShowClientBalaces() {
	system("cls");

	PrintAccountBalances(RetriveAccountsData(ACCOUNTS_FILE));

	BackToTransactionMenueScreen();
}

// this function fires the appropriate transaction feature
void PerformTransaction(enTransactionOption option) {
	switch (option) {
	case enTransactionOption::DepositeOption: return PerformDepositTransaction();
	case enTransactionOption::WithdrawOption: return PerformWithdrawTransaction();
	case enTransactionOption::TotalBalancesOption: return ShowClientBalaces();
	case enTransactionOption::MainMenueOption: return ShowMainMenueScreen();
	default: return ShowTransactionsMenueScreen();
	}
}

// this function displays the transaction menue features on the screen
void ShowTransactionsMenueScreen() {
	system("cls");

	vector<string> messages;
	messages.push_back("[1] Deposite.");
	messages.push_back("[2] Withdraw.");
	messages.push_back("[3] Total Balances.");
	messages.push_back("[4] Main Menue.");

	PrintHeader("Transactions Menue Screen", '=', LINE_WIDTH);

	for (string& message : messages) {
		cout << "\t" << message << "\n";
	}

	printers::PrintChar('=', LINE_WIDTH);
	cout << endl;

	PerformTransaction((enTransactionOption)readers::ReadPositiveNumberInRange("Choose what you want to do [1 to 4]: ", 1, 4));
}

// this function searchs for an account and displays it on the screen
void FindAccount() {
	string account_number = "";

	cout << "Enter the account number you want to find: ";
	cin >> account_number;

	stAccount account;
	vector<stAccount> accounts = RetriveAccountsData(ACCOUNTS_FILE);

	if (FindAccountByNumber(account_number, accounts, account)) {
		cout << endl;
		PrintAccount(account);
	}
	else cout << "The account [" << account_number << "] does not exist!\n";
}

// this function reads and adds new account to the file
void AddNewAccount() {
	stAccount account;
	account = ReadNewAccount();
	AddAccountToFile("accounts.txt", ConvertAccountToLine(account));
}

// this function fires the show client list feature
void ShowClientList() {
	system("cls");

	PrintAccounts(RetriveAccountsData(ACCOUNTS_FILE));

	BackToMainMenueScreen();
}

// this function adds clients from the screen
void AddNewClient() {
	char flag = 'n';
	
	system("cls");

	PrintHeader("Add New Client Screen", '-', LINE_WIDTH);
	cout << endl;

	do {
		AddNewAccount();

		cout << "\nClient added successfully, do you want to add more clients [y/n]: ";
		cin >> flag;

		cout << endl;

	} while (tolower(flag) == 'y');


	BackToMainMenueScreen();
}

// this function fires the delete client feature
void DeleteClient() {
	system("cls");

	PrintHeader("Delete Client Screen", '-', LINE_WIDTH);
	cout << endl;

	PerformDeleteAccount();

	BackToMainMenueScreen();
}

// this function fires the update client feature
void UpdateClient() {
	system("cls");

	PrintHeader("Update Client Screen", '-', LINE_WIDTH);
	cout << endl;

	PerformUpdateAccount();

	BackToMainMenueScreen();
}

// this function fires the find client feature
void FindClient() {
	system("cls");

	PrintHeader("Find Client Screen", '-', LINE_WIDTH);
	cout << endl;

	FindAccount();

	BackToMainMenueScreen();
}

// this function fires the exit feature
void ExitProgram() {
	system("cls");

	PrintHeader("Program Ends :-)", '-', LINE_WIDTH);
	cout << endl;

	cout << "\n\nPress any key to end the program . . .";
	system("pause>0");
}

// this function chooses the appropriate function to call in the main menue in the main menue screen
void PerformAction(enOptions option) {
	switch (option){
		case enOptions::ShowClientListOption: return ShowClientList();
		case enOptions::AddNewClientOption: return AddNewClient();
		case enOptions::DeleteClientOption: return DeleteClient();
		case enOptions::UpdataClientInfoOption: return UpdateClient();
		case enOptions::FindClientOption: return FindClient();
		case enOptions::TransactionsOption: return ShowTransactionsMenueScreen();
		case enOptions::ExitOption: return ExitProgram();
		default: return ShowMainMenueScreen();
	}
}

// this function allows the user to back to the transaction menue screen
void BackToTransactionMenueScreen() {
	cout << "\n\nPress any key to go back . . .";
	system("pause>0");

	ShowTransactionsMenueScreen();
}

// this function allows the user to back to the main menue screen
void BackToMainMenueScreen() {
	cout << "\n\nPress any key to go back . . .";
	system("pause>0");

	ShowMainMenueScreen();
}

// this function displays the main menue features on the screen
void ShowMainMenueScreen() {
	system("cls");

	vector<string> messages;
	messages.push_back("[1] Show Client List.");
	messages.push_back("[2] Add New Client.");
	messages.push_back("[3] Delete Client.");
	messages.push_back("[4] Update Client Info.");
	messages.push_back("[5] Find Client.");
	messages.push_back("[6] Transactions.");
	messages.push_back("[7] Exit.");

	PrintHeader("Main Menue Screen", '=', LINE_WIDTH);

	for (string& message : messages) {
		cout << "\t" << message << "\n";
	}

	printers::PrintChar('=', LINE_WIDTH);
	cout << endl;

	PerformAction((enOptions)readers::ReadPositiveNumberInRange("Choose what you want to do [1 to 7]: ", 1, 7));
}

/* --------------------------------- FUNCTIONS --------------------------------- */

int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */
		/* --------------------------------- VARIABLES --------------------------------- */
		/* --------------------------------- VARIABLES --------------------------------- */
		/* --------------------------------- MAIN WORK --------------------------------- */
		ShowMainMenueScreen();
		/* --------------------------------- MAIN WORK --------------------------------- */
		/* --------------------------------- PRINT --------------------------------- */
		/* --------------------------------- PRINT --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- CODE --------------------------------- */
		break;
	}
}

