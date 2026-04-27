#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "clsDate.h"
#include "clsOutput.h"

using namespace std;

class clsQueueLine
{
public:
	struct stTicket {
		string title;
		int number;
		string date;
		int waiting_customers;
		int serve_time;
	};

private:
	string _Prefex;
	int _CustomerServeTime;
	queue<stTicket> _Tickets_Queue;
	int _TotalCustomers = 0;
	int _ServedCustomers = 0;

	void _PrintTicket(stTicket ticket) {
		cout << "---------------------------" << "\n";
		cout << "            " << ticket.title << "            " << "\n";
		cout << "---------------------------" << "\n";

		cout << ticket.date << "\n";
		cout << "Waiting Customers = " << ticket.waiting_customers << "\n";
		cout << "Serve Time In" << "\n";
		cout << ticket.serve_time << " Minutes" << "\n";

		cout << "---------------------------" << "\n";
	}

	string _GetTitle() {
		string result = _Prefex;
		result += clsOutput::FormatNumber(_TotalCustomers+1, 2);
		return result;
	}

	void _ReverseQueue(queue<stTicket>& queue) {
		stack<stTicket> temp_stack;
		while (!queue.empty()) {
			temp_stack.push(queue.front());
			queue.pop();
		}
		while (!temp_stack.empty()) {
			queue.push(temp_stack.top());
			temp_stack.pop();
		}
	}

public:
	clsQueueLine(string prefex, int customer_serve_time) {
		_Prefex = prefex;
		_CustomerServeTime = customer_serve_time;
	}

	void IssueTicket() {
		stTicket new_ticket;
		new_ticket.title = _GetTitle();
		new_ticket.number = _TotalCustomers + 1;
		new_ticket.waiting_customers = _Tickets_Queue.size();
		new_ticket.date = clsDate::GetSystemDateTime();
		new_ticket.serve_time = new_ticket.waiting_customers * _CustomerServeTime;

		_Tickets_Queue.push(new_ticket);
		_TotalCustomers++;
	}

	void PrintInfo() {
		cout << "----------------------------------" << "\n";
		cout << "            Queue Info            " << "\n";
		cout << "----------------------------------" << "\n";

		cout << "Prefix            = " << _Prefex << "\n";
		cout << "Total tickets     = " << _TotalCustomers << "\n";
		cout << "Served Clients    = " << _ServedCustomers << "\n";
		cout << "Waiting Customers = " << _Tickets_Queue.size() << "\n";
		
		cout << "----------------------------------" << "\n";
	}

	void PrintTicketsLineRTL() {
		queue<stTicket> tickets = _Tickets_Queue;
		cout << "Tickets: ";
		while (!tickets.empty()) {
			stTicket ticket = tickets.front();
			tickets.pop();
			cout << ticket.title << " <-- ";
		}
		cout << "\n";
	}

	void PrintTicketsLineLTR() {
		queue<stTicket> tickets = _Tickets_Queue;
		_ReverseQueue(tickets);
		cout << "Tickets: ";
		while (!tickets.empty()) {
			stTicket ticket = tickets.front();
			tickets.pop();
			cout << ticket.title << " --> ";
		}
		cout << "\n";
	}

	void PrintAllTickets() {
		cout << "       --{Tickets}--       " << "\n";
		queue<stTicket> tickets = _Tickets_Queue;
		while (!tickets.empty()) {
			stTicket ticket = tickets.front();
			tickets.pop();
			_PrintTicket(ticket);
			cout << "\n";
		}
	}

	void ServeNextCustomer() {
		if (!_Tickets_Queue.empty()) {
			_Tickets_Queue.pop();
			_ServedCustomers++;
		}
	}
};

