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

class clsEmployee {
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _Title;
	string _Email;
	string _Phone;
	float _Salary;
	string _Department;

public:
	clsEmployee(int ID, string first_name, string last_name, string title, string email, string phone, float salary, string department) {
		_ID = ID;
		_FirstName = first_name;
		_LastName = last_name;
		_Title = title;
		_Email = email;
		_Phone = phone;
		_Salary = salary;
		_Department = department;
	}

	int getID() { return _ID; }

	string getFirstName() { return _FirstName; }
	void setFirstName(string first_name) { _FirstName = first_name; }

	string getLastName() { return _LastName; }
	void setLastName(string last_name) { _LastName = last_name; }

	string getTitle() { return _Title; }
	void setTitle(string title) { _Title = title; }

	string getEmail() { return _Email; }
	void setEmail(string email) { _Email = email; }

	string getPhone() { return _Phone; }
	void setPhone(string phone) { _Phone = phone; }

	float getSalary() { return _Salary; }
	void setSalary(float salary) { _Salary = salary; }

	string getDepartment() { return _Department; }
	void setDepartment(string department) { _Department = department; }

	string FullName() { return _FirstName + " " + _LastName; }

	void SendEmail(string subject, string body) {
		cout << "Email sended successfully to : " << _Email << "\n";
		cout << "Subject : " << subject << "\n";
		cout << "Body : " << body << "\n";
	}

	void SendSMS(string message) {
		cout << "Message sended successfully to : " << _Phone << "\n";
		cout << "Message : " << message << "\n";
	}

	void Print() {
		cout << printers::FormatedCout(20, "Info", printers::enPosition::center) << "\n";

		cout << printers::PrintDashes(20, "=") << "\n";

		cout << "ID         : " << _ID << "\n";
		cout << "FirstName  : " << _FirstName << "\n";
		cout << "LastName   : " << _LastName << "\n";
		cout << "FullName   : " << FullName() << "\n";
		cout << "Title      : " << _Title << "\n";
		cout << "Email      : " << _Email << "\n";
		cout << "Phone      : " << _Phone << "\n";
		cout << "Salary     : " << _Salary << "\n";
		cout << "Department : " << _Department << "\n";

		cout << printers::PrintDashes(20, "=") << "\n";
	}

};



int main()
{
	clsEmployee employee(01, "Yasin", "Hamad", "Backend Developer", "yasin27@gmail.com", "71345036", 10000, "Architecture");

	cout << "\n";
	employee.SendEmail("Remember", "Allah with you");
	cout << "\n";

	employee.SendSMS("You have the right to make money, just be valuable");
	cout << "\n";

	employee.Print();
}