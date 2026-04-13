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
struct stUser {
	string name;
	string pin_code;
	int permissions;
	bool mark_as_deleted = false;
};
/* --------------------------------- STRUCTURES --------------------------------- */
/* --------------------------------- GLOBAL VARIABLES --------------------------------- */
const int LINE_WIDTH = 50;
const string ACCOUNTS_FILE = "accounts.txt";
const string USERS_FILE = "users.txt";
const string ADMIN_NAME = "Admin";
stUser CURRENT_USER;

/* --------------------------------- GLOBAL VARIABLES --------------------------------- */
/* --------------------------------- ENUMS --------------------------------- */
enum enOptions {
	ShowClientListOption = 1, AddNewClientOption = 2, DeleteClientOption = 3,
	UpdataClientInfoOption = 4, FindClientOption = 5, TransactionsOption = 6, ManageUsersOption = 7, ExitOption = 8
};
enum enPermissions {
	ShowClientListPermission = 1, AddNewClientPermission = 2, DeleteClientPermission = 4,
	UpdataClientInfoPermission = 8, FindClientPermission = 16, TransactionsPermission = 32, ManageUsersPermission = 64, ExitPermission = 128
};
enum enTransactionOption {
	DepositeOption = 1, WithdrawOption = 2, TotalBalancesOption = 3, MainMenueOption = 4
};
enum enManageUsersOption {
	ListUsersOption = 1, AddNewUserOption = 2, DeleteUserOption = 3, UpdateUserOption = 4, FindUserOption = 5, BackToMainMenueOption = 6
};
/* --------------------------------- ENUMS --------------------------------- */
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
/*-----------------------------------------------------------------------------------------*/
bool SaveUsersToFile(const string file_name, vector<stUser> users);
string ConvertUserToLine(stUser user, string separator = "#||#");
void UpdateUserData(stUser& user);
bool UpdateUserInVector(vector<stUser>& users, stUser user);
bool UpdateUser(string user_name);
void PerformUpdateUser();
void ShowUpdateUser();
bool MarkAsDeleted(vector<stUser>& users, stUser user);
void AskForPermission(string message, int& permission, int value);
void ReadUserPermissions(stUser& user);
stUser ReadNewUser();
void AddNewUser();
void AddNewUsers();
void BackToManageUsersScreen();
void PrintUsers(vector<stUser> users);
void ShowAccessDenied();
bool CheckPermission(enPermissions option);
void ShowUsersList();
void PrintUser(const stUser& user);
bool DeleteUser(string user_name);
void PerformDeleteUser();
void ShowDeleteUser();
void FindUser();
void ShowFindUser();
void PerformManageUserOption(enManageUsersOption option);
void ShowManageUsersScreen();
stUser ConvertLineToUser(string line, string separator = "#||#");
vector<stUser> RetriveUsersData(const string file_name);
bool FindUser(string user_name, string pin_code, stUser& user);
bool FindUser(string user_name, stUser& user);
bool FindUser(string user_name, stUser& user, vector<stUser> users);
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
	deposite = readers::ReadPositiveDoubleNumber("Enter deposit amount: ");

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
	messages.push_back("[1] Deposit.");
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
	AddAccountToFile(ACCOUNTS_FILE, ConvertAccountToLine(account));
}

// this function fires the show client list feature
void ShowClientList() {
	//if (CheckPermission(enOptions::ShowClientListOption)) return ShowAccessDenied();

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
	//system("cls");

	//PrintHeader("Program Ends :-)", '-', LINE_WIDTH);
	//cout << endl;

	//cout << "\n\nPress any key to end the program . . .";
	//system("pause>0");
	ShowLoginScreen();
}

// this function chooses the appropriate function to call in the main menue in the main menue screen
void PerformAction(enOptions option) {
	switch (option){
	case enOptions::ShowClientListOption: return CheckPermission(enPermissions::ShowClientListPermission) ? ShowClientList() : ShowAccessDenied();
	case enOptions::AddNewClientOption: return CheckPermission(enPermissions::AddNewClientPermission) ? AddNewClient() : ShowAccessDenied();
	case enOptions::DeleteClientOption: return CheckPermission(enPermissions::DeleteClientPermission) ? DeleteClient() : ShowAccessDenied();
	case enOptions::UpdataClientInfoOption: return CheckPermission(enPermissions::UpdataClientInfoPermission) ? UpdateClient() : ShowAccessDenied();
	case enOptions::FindClientOption: return CheckPermission(enPermissions::FindClientPermission) ? FindClient() : ShowAccessDenied();
	case enOptions::TransactionsOption: return CheckPermission(enPermissions::TransactionsPermission) ? ShowTransactionsMenueScreen() : ShowAccessDenied();
	case enOptions::ManageUsersOption: return CheckPermission(enPermissions::ManageUsersPermission) ? ShowManageUsersScreen() : ShowAccessDenied();
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
	messages.push_back("[7] Manage Users.");
	messages.push_back("[8] Logout.");

	PrintHeader("Main Menue Screen", '=', LINE_WIDTH);

	for (string& message : messages) {
		cout << "\t" << message << "\n";
	}

	printers::PrintChar('=', LINE_WIDTH);
	cout << endl;

	PerformAction((enOptions)readers::ReadPositiveNumberInRange("Choose what you want to do [1 to 8]: ", 1, 8));
}

/*-----------------------------------------------------------------------------------------*/

// this function takes a user structure and converts it to a line of string
string ConvertUserToLine(stUser user, string separator) {
	vector<string> data;

	data.push_back(user.name);
	data.push_back(user.pin_code);
	data.push_back(to_string(user.permissions));

	return manipulators::string_utilities::JoinString(data, separator);
}

// refill user data from the screen
void UpdateUserData(stUser& user) {
	char check = 'a';

	cout << "Enter pin code: ";
	getline(cin >> std::ws, user.pin_code);

	do {
		cout << "Do you want to give them full access [y/n]: ";
		cin >> check;

		if (tolower(check) == 'y') user.permissions = -1;
		else if (tolower(check) == 'n') ReadUserPermissions(user);

	} while (tolower(check) != 'y' && tolower(check) != 'n');
}

// update data of the give user in the vector
bool UpdateUserInVector(vector<stUser>& users, stUser user) {
	for (stUser& _user : users) {
		if (_user.name == user.name) {
			_user = user;
			return true;
		}
	}
	return false;
}

// find the user we want to update, update it, then save changes
bool UpdateUser(string user_name) {
	stUser user;
	vector<stUser> users = RetriveUsersData(USERS_FILE);
	char flag = 'n';

	if (FindUser(user_name, user, users)) {
		if (user.name == ADMIN_NAME) {
			cout << "This user can't be updated.";
			return false;
		}
		cout << "Are you sure you want to update this user:\n\n";

		PrintUser(user);

		cout << "\n[y/n]: ";
		cin >> flag;

		if (tolower(flag) == 'y') {
			UpdateUserData(user);

			return (UpdateUserInVector(users, user) && SaveUsersToFile(USERS_FILE, users));
		}
		else {
			cout << "The process has been canceled\n";
			return false;
		}
	}
	cout << "The user [" << user_name << "] does not exist!\n";
	return false;
}

// takes from the screen the date needed to update a user, and fire the update process
void PerformUpdateUser() {
	string user_name = "";

	cout << "Enter the user name you want to update: ";
	cin >> user_name;

	if (UpdateUser(user_name)) {
		cout << "User successfully updated" << endl;
	}
}

// show the update screen
void ShowUpdateUser() {
	system("cls");

	PrintHeader("Update User Screen", '-', LINE_WIDTH);
	cout << endl;

	PerformUpdateUser();

	BackToManageUsersScreen();
}

// save the users in the vector to the file
bool SaveUsersToFile(const string file_name, vector<stUser> users) {
	fstream my_file;

	my_file.open(file_name, ios::out);

	if (my_file.is_open()) {
		for (stUser user: users) {
			if (!user.mark_as_deleted) {
				my_file << ConvertUserToLine(user) << endl;
			}
		}

		my_file.close();
		return true;
	}
	return false;
}

// mark the given user as deleted in the given vecotr of users
bool MarkAsDeleted(vector<stUser>& users, stUser user) {
	for (stUser& _user : users) {
		if (_user.name == user.name) {
			_user.mark_as_deleted = true;
			return true;
		}
	}
	return false;
}

// takes specific permission from the screen
void AskForPermission(string message, int& permission, int value) {
	char check = 'a';
	while (true) {
		cout << message;
		cin >> check;
		if (tolower(check) != 'y' && tolower(check) != 'n') continue;
		if (tolower(check) == 'y') permission += value;
		break;
	}
}

// read all user's permissions
void ReadUserPermissions(stUser& user) {
	int permissions = 0;
	cout << "Do you want to give access to: " << "\n\n";

	AskForPermission("Show client list [y/n]: ",  permissions, (int)enPermissions::ShowClientListPermission);
	AskForPermission("Add new client [y/n]: ",  permissions, (int)enPermissions::AddNewClientPermission);
	AskForPermission("Delete client [y/n]: ",  permissions, (int)enPermissions::DeleteClientPermission);
	AskForPermission("Update client [y/n]: ",  permissions, (int)enPermissions::UpdataClientInfoPermission);
	AskForPermission("Find client [y/n]: ",  permissions, (int)enPermissions::FindClientPermission);
	AskForPermission("Transactions [y/n]: ",  permissions, (int)enPermissions::TransactionsPermission);
	AskForPermission("Manage users [y/n]: ",  permissions, (int)enPermissions::ManageUsersPermission);

	user.permissions = permissions;
}

// fill data of a new user
stUser ReadNewUser() {
	stUser user;
	stUser aux_user;
	char check = 'a';

	cout << "Enter user name: ";
	getline(cin >> std::ws, user.name);

	while (FindUser(user.name, aux_user)) {
		cout << "User with [" << user.name << "] already exists, enter another name: ";
		getline(cin >> std::ws, user.name);
	}

	cout << "Enter pin code: ";
	getline(cin, user.pin_code);


	do {
		cout << "Do you want to give them full access [y/n]: ";
		cin >> check;
		
		if (tolower(check) == 'y') user.permissions = -1;
		else if (tolower(check) == 'n') ReadUserPermissions(user);
	
	} while (tolower(check) != 'y' && tolower(check) != 'n');

	return user;
}

// prepare and fill new user, then save it to the file
void AddNewUser() {
	stUser user;
	user = ReadNewUser();
	AddAccountToFile(USERS_FILE, ConvertUserToLine(user));
}

// keep adding new users
void AddNewUsers() {
	char flag = 'n';

	system("cls");

	PrintHeader("Add New User Screen", '-', LINE_WIDTH);
	cout << endl;

	do {
		AddNewUser();

		cout << "\nUser added successfully, do you want to add more users [y/n]: ";
		cin >> flag;

		cout << endl;

	} while (tolower(flag) == 'y');


	BackToManageUsersScreen();
}

void BackToManageUsersScreen() {
	cout << "\n\nPress any key to go back . . .";
	system("pause>0");

	ShowManageUsersScreen();
}

// print the table of the users
void PrintUsers(vector<stUser> users) {

	vector<vector<string>> table_data;

	table_data.push_back({ "User Name", "Pin Code", "Permissions" });

	for (stUser& user : users) {
		table_data.push_back
		({
			user.name,
			user.pin_code,
			to_string(user.permissions)
			});
	}

	printf("\nUsers List [%d] User(s)\n", (table_data.size() - 1));

	printers::MakeTable(table_data, printers::enPosition::center, true);
}

// show the access denied screen
void ShowAccessDenied() {
	system("cls");

	printers::PrintChar('-', LINE_WIDTH);
	cout << "\n";
	cout << "Access denied," << "\n";
	cout << "you don't have permission to do this," << "\n";
	cout << "please contact your admin." << "\n";
	printers::PrintChar('-', LINE_WIDTH);
	cout << "\n";

	BackToMainMenueScreen();
}

// check if the current user has permission to do a specific task
bool CheckPermission(enPermissions option) {
	if (CURRENT_USER.permissions != -1 && !(CURRENT_USER.permissions & option))
		return false;
	return true;
}

void ShowUsersList() {

	system("cls");

	PrintUsers(RetriveUsersData(USERS_FILE));

	BackToManageUsersScreen();
}

// print the given user's data
void PrintUser(const stUser& user) {
	cout << "The following are the user details: \n";
	printers::PrintChar('-', LINE_WIDTH);
	cout << "\n";
	cout << "User name   : " << user.name << "\n";
	cout << "Pin code    : " << user.pin_code << "\n";
	cout << "Permissions : " << user.permissions << "\n";
	printers::PrintChar('-', LINE_WIDTH);
	cout << endl;
}

// find and delete a user, then save the chages to the file
bool DeleteUser(string user_name) {
	stUser user;
	vector<stUser> users = RetriveUsersData(USERS_FILE);
	char flag = 'n';

	if (FindUser(user_name, user, users)) {
		if (user.name == ADMIN_NAME) {
			cout << "This user can't be deleted.";
			return false;
		}
		cout << "Are you sure you want to delete this user:\n\n";

		PrintUser(user);

		cout << "\n[y/n]: ";
		cin >> flag;

		if (tolower(flag) == 'y') {
			return (MarkAsDeleted(users, user) && SaveUsersToFile(USERS_FILE, users));
		}
		else {
			cout << "The process has been canceled\n";
			return false;
		}
	}
	cout << "The user [" << user_name << "] does not exist!\n";
	return false;
}

// take from the screen the data needed to delete a user, then fire the deleting process
void PerformDeleteUser() {
	string user_name = "";

	cout << "Enter the user name you want to delete: ";
	cin >> user_name;

	if (DeleteUser(user_name)) {
		cout << "User successfuly deleted" << endl;
	}
}

void ShowDeleteUser() {
	system("cls");

	PrintHeader("Delete User Screen", '-', LINE_WIDTH);
	cout << endl;

	PerformDeleteUser();

	BackToManageUsersScreen();
}

// take from the screen the data needed to find a user
// search for it, then print it on the screen
void FindUser() {
	string user_name = "";

	cout << "Enter the user name you want to find: ";
	cin >> user_name;

	stUser user;
	vector<stUser> users = RetriveUsersData(USERS_FILE);

	if (FindUser(user_name, user, users)) {
		cout << endl;
		PrintUser(user);
	}
	else cout << "The user [" << user_name << "] does not exist!\n";
}

void ShowFindUser() {
	system("cls");

	PrintHeader("Find User Screen", '-', LINE_WIDTH);
	cout << endl;

	FindUser();

	BackToManageUsersScreen();
}

// fire the appropriate function based on the user choice
void PerformManageUserOption(enManageUsersOption option) {
	switch (option) {
	case enManageUsersOption::ListUsersOption: return ShowUsersList();
	case enManageUsersOption::AddNewUserOption: return AddNewUsers();
	case enManageUsersOption::DeleteUserOption: return ShowDeleteUser();
	case enManageUsersOption::UpdateUserOption: return ShowUpdateUser();
	case enManageUsersOption::FindUserOption: return ShowFindUser();
	case enManageUsersOption::BackToMainMenueOption: return ShowMainMenueScreen();
	default: return ShowManageUsersScreen();
	}
}

void ShowManageUsersScreen() {
	system("cls");

	vector<string> messages;
	messages.push_back("[1] List Users.");
	messages.push_back("[2] Add New User.");
	messages.push_back("[3] Delete User.");
	messages.push_back("[4] Update User.");
	messages.push_back("[5] Find User.");
	messages.push_back("[6] Main Menue.");

	PrintHeader("Manage Users Menue Screen", '=', LINE_WIDTH);

	for (string& message : messages) {
		cout << "\t" << message << "\n";
	}

	printers::PrintChar('=', LINE_WIDTH);
	cout << endl;

	PerformManageUserOption((enManageUsersOption)readers::ReadPositiveNumberInRange("Choose what you want to do [1 to 6]: ", 1, 6));
}

// convert a line of string to a user structure
stUser ConvertLineToUser(string line, string separator) {
	stUser user;
	vector<string> data = manipulators::string_utilities::Split(line, separator);

	user.name = data.at(0);
	user.pin_code = data.at(1);
	user.permissions= stoi(data.at(2));

	return user;
}

// retrives the users from the file
vector<stUser> RetriveUsersData(const string file_name) {
	vector<stUser> user_records;

	vector<string> account_lines;

	files::LoadDataFromFileToVector(file_name, account_lines);

	for (string& line : account_lines) {
		user_records.push_back(ConvertLineToUser(line));
	}

	return user_records;
}

// the following three functions search for a user in the file
bool FindUser(string user_name, string pin_code, stUser& user) {
	vector<stUser> users = RetriveUsersData(USERS_FILE);

	for (stUser& _user : users) {
		if (user_name == _user.name && pin_code == _user.pin_code) {
			user = _user;
			return true;
		}
	}
	return false;
}
bool FindUser(string user_name, stUser& user) {
	vector<stUser> users = RetriveUsersData(USERS_FILE);

	for (stUser& _user : users) {
		if (user_name == _user.name) {
			user = _user;
			return true;
		}
	}
	return false;
}
bool FindUser(string user_name, stUser& user, vector<stUser> users) {
	for (stUser& _user : users) {
		if (user_name == _user.name) {
			user = _user;
			return true;
		}
	}
	return false;
}

// perform the login process
void ShowLoginScreen() {
	string user_name;
	string pin_code;
	bool flag = false;

	do {
		system("cls");
		PrintHeader("Login Screen", '=', LINE_WIDTH);

		if (flag) {
			cout << "Invalid Username/Password!" << "\n";
		}
		if(!flag) flag = true;

		user_name = readers::ReadASentence("Enter username: ");
		pin_code = readers::ReadASentence("Enter pin code: ");

	} while (!FindUser(user_name, pin_code, CURRENT_USER));
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

