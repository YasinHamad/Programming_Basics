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

class clsCodeGenerator {
	
};

class clsPerson {
	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

	void fun() {}

public:
	clsPerson(){}

	clsPerson(int ID, string first_name, string last_name, string email, string phone){
		_ID = ID;
		_FirstName = first_name;
		_LastName = last_name;
		_Email = email;
		_Phone = phone;
	}

	int getID() {
		return _ID;
	}

	void setFirstName(string first_name) {
		_FirstName = first_name;
	}
	string getFirstName() {
		return _FirstName;
	}

	void setLastName(string last_name) {
		_LastName = last_name;
	}
	string getLastName() {
		return _LastName;
	}

	void setEmail(string email) {
		_Email = email;
	}
	string getEmail() {
		return _Email;
	}

	void setPhone(string phone) {
		_Phone = phone;
	}
	string getPhone() {
		return _Phone;
	}

	void SendEmail(string subject, string body) {
		cout << "The following message sent successfully to email: " << _Email << "\n";
		cout << "Subject: " << subject << "\n";
		cout << "Body   : " << body << "\n";
	}

	void SendSMS(string message) {
		cout << "The following SMS sent successfully to phone: " << _Phone << "\n";
		cout << message << "\n";
	}

	void Print() {
		cout << "Info" << "\n";
		cout << "______________________________" << "\n";
		cout << "ID       :" << _ID << "\n";
		cout << "FirstName:" << _FirstName << "\n";
		cout << "LastName :" << _LastName << "\n";
		cout << "FullName :" << _FirstName << " " << _LastName << "\n";
		cout << "Email    :" << _Email << "\n";
		cout << "Phone    :" << _Phone << "\n";
		cout << "______________________________" << "\n";
	}

};

class clsEmployee : public clsPerson {
private:
	string _Title;
	float _Salary = 0.0;
	string _Department;


public:
	clsEmployee(int id, string firstname, string lastname, string email, string phone, string title, string department, float salary)
		: clsPerson(id, firstname, lastname, email, phone) {
		
		_Title = title;
		_Salary = salary;
		_Department = department;
	}

	string getTitle() { return _Title; }
	void setTitle(string title) { _Title = title; }

	float getSalary() { return _Salary; }
	void setSalary(float salary) { _Salary = salary; }

	string getDepartment() { return _Department; }
	void setDepartment(string department) { _Department = department; }

	void Print() {
		cout << "Info" << "\n";
		cout << "______________________________" << "\n";
		cout << "ID        :" << getID() << "\n";
		cout << "FirstName :" << getFirstName() << "\n";
		cout << "LastName  :" << getLastName() << "\n";
		cout << "FullName  :" << getFirstName() << " " << getLastName() << "\n";
		cout << "Email     :" << getEmail() << "\n";
		cout << "Phone     :" << getPhone() << "\n";
		cout << "Title     :" << _Title << "\n";
		cout << "Salary    :" << _Salary << "\n";
		cout << "Department:" << _Department << "\n";
		cout << "______________________________" << "\n";
	}

};

class clsDeveloper : public clsEmployee{
	string _MainProgrammingLanguage;

public:
	clsDeveloper(int id, string firstname, string lastname, string email, string phone, string Title, string Department, float Salary, string MainProgrammingLanguage)
		: clsEmployee(id, firstname, lastname, email, phone, Title, Department, Salary) {
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	string getMainProgrammingLanguage() { return _MainProgrammingLanguage; }
	void setMainProgrammingLanguage(string MainProgrammingLanguage) { _MainProgrammingLanguage = MainProgrammingLanguage; }

	void Print() {
		cout << "Info" << "\n";
		cout << "______________________________" << "\n";
		cout << "ID                     :" << getID() << "\n";
		cout << "FirstName              :" << getFirstName() << "\n";
		cout << "LastName               :" << getLastName() << "\n";
		cout << "FullName               :" << getFirstName() << " " << getLastName() << "\n";
		cout << "Email                  :" << getEmail() << "\n";
		cout << "Phone                  :" << getPhone() << "\n";
		cout << "Title                  :" << _Title << "\n";
		cout << "Department             :" << _Department << "\n";
		cout << "Salary                 :" << _Salary << "\n";
		cout << "MainProgrammingLanguage:" << _MainProgrammingLanguage << "\n";
		cout << "______________________________" << "\n";
	}

};

int main()
{
	clsDeveloper developer(10, "Yasin", "Hamad", "yasin@gmail.com", "71345036", "Backend Dev",
		"Architecture", 100000, "C#");

	developer.SendEmail("Hi", "How are you?");
	cout << endl;

	developer.SendSMS("Hi, how are you?");
	cout << endl;
	
	developer.Print();
	cout << endl;
}