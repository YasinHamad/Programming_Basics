# Introduction
For example if the lesson about bubble sorting, understand it, write it, be sure it is work, and that is enough.
In real word, you will use the language libraries.

In this course, you will :
- extend your knowledge
- practice more

___
# What is DS and why?

Program = Algorithms + DS.

To make an algorithm, you need tools:
- the language tools, like: if-else statement, loops
- and you need places to put the data in (these are data structures)

`int`, `string` are data structures, because you put data in them.
`array`, `struct` are data structures.
It is all about, how you will represent the data in the RAM.

DS is about dealing with data in code.

DS is about, how you put your data in RAM, so you can use them.

There are many data structures.

If you don't know all data structures, you'll be limited.
Data structures help you store, process, and retrieving your data, in the program.

> Various types of data structures have their own characteristics, features, applications,
> advantages, and disadvantages.

You should know what data structure is suitable for your task.

Data structures help you deal with the data in your program.

> Data types : basic building blocks of data. Examples include integers, doubles, chars, and booleans.
> They define the type of data that can be stored and the operations that can be performed on that data.
> Data structures : collections of data types arranged in a specific way to efficiently store, organize, and manage data.
> Data structures use data types to create more complex and functional ways to handle data.

---
# Difference between DS and DB
The database is out of your program.

> [!Note]
> HDD means hard disk drive.
> SSD means solid state drive.

DB data are stored permanently in your HDD or SSD.
DS data are stored temporarily in your RAM.

> [!Important]
> In your program, think about:
> - what data I have
> - how to organize them (struct - vector of struct - etc.)

DS makes it easier to deal with data in RAM.
Imaging dealing with `string name = "yasin##hamad"`, instead of `struct name` of first name and last name.

Queries in DB reduces the amount of code you write.

In DS, you build the structure of the data, to use it your system.
You build the structure using the data types, and the data collections.

| Data Structure                                                                                                | Database                                                                                                     |
| ------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| Data in data structure is stored<br>in RAM inside the program.<br>It is a volatile(متقلب) memory (Temporary). | Data in database is stored in hard desk <br>outside the program.<br>It is a non-volatile memory (Permanent). |
| Special format for storing data.                                                                              | Organized collection of data.                                                                                |
| Used for efficiency and to reduce the<br>complexity of the program.                                           | Used to access the data, and manage<br>it easily.                                                            |
| Programming languages Cpp, JAVA,<br>Python are used to preform operations<br>using data structures.           | Structured query language (SQL) is used<br>to perform operations on the data in<br>the database.             |
| Example : Array, Linked List, Stack,<br>Queue, Tree, Graph.                                                   | Example: MySQL, Oracle, MongoDB,<br>Sybase, SQL Server, SQL Express, etc.                                    |

---
# Classifications of Data Structures

We can traverse the linear data structure using a for loop.
We can't traverse the non-linear data structure using a for loop.

Data Structure
- Primitive (Integer - Float - Char - Pointer)
- Non-Primitive
	- Linear
		- Static (Array)
		- Dynamic (Queue - Stack - Linked List)
	- Non-Linear (Tree - Graph)

The primitive types are usually built into the language.
Non primitive types are built on top of the primitive ones, and they are connected in a meaningful way.
Homogeneous (same type). Heterogeneous (different type).

Data structures
- Static (Array) -> fixed memory size.
- Dynamic (Queue - Stack) -> size is not fixed.

---
# Time & Space Complexity - Big O Notation - Part 1
## Things affect program speed & efficiency

Program Speed
- Algorithm (we call this complexity)
	- Time
	- Space
- Hardware, CPU, RAM, OS (we call this performance)

As devs, we don't care about the hardware part, but we care about the algorithm part.
What affects the algorithm speed? The answer is : time & space.
Servers-they are also computers- is powerful more than normal computers.

## Time & Space Complexity - Big O Notation
The algorithm takes time and space.

Printing `Array[10]` items, is faster than printing `Array[1000]` items, regardless the hardware.

We can't judge the algorithm depending on time, because time depends on the hardware. So, we need a way to differentiate between printing the `array[10]` and the `array[1000]`, that doesn't depend on time.

The big O gives you the relationship between the `input_size` and the time/space.
The big O doesn't consider the hardware.
The big O doesn't give you an exact answer on how long a piece of code will take to run.

> An algorithm's time complexity: specifies how long it will take to execute an algorithm as a function of its input size.
> Similarly, an algorithm's space complexity: specifies the total amount of space or memory required to execute an algorithm as a function of the size of the input.

> The big O stands for "Order of complexity"
> The big O represents the algorithm's worst-case complexity.
> It uses the `algebraic terms` to describe the complexity of an algorithm.
> Big O defines the runtime required to execute an algorithm, by identifying how the performance of your algorithm will change as the input size grows.
> Big O allows us to discuss our code algebraically to get a sense of how quickly it might operate under the strain of large data sets.
> Big O tells us about the efficiency of the algorithm.
> Big O notation, written as O(blank), shows us how many operations our code will run, and how its runtime grows in comparison to other possible solutions.

Order of complexities:
- O(1)
- O(log n)
- O(n)
- O(n log n)
- O(n^2)
- O(n^3)
- O(2^n)
- O(n!)

## Big O(1) : Constant Time Function
The algorithm doesn't depend on the number of inputs.

```cpp
char GetLastChar1(string s) {
	return s[ s.length() - 1 ];
}

char GetLastChar2(string s) {
	int n = s.length() - 1;
	for(int i = 0; i<=n; i++) {
		if(i == n) {
			return s[n];
		}
	}
}
```

In the second function, you made a connection between the algorithm and the size of the input.
The first function will take 4 steps regardless the size of the input.
O(1) is the fastest because it doesn't depend on the input size. It takes constant number of steps, for example, 4 steps in all cases. It always takes the same time.

## Big O(n) : Linear Time Function

The second function above is O(n), you know why :)
It is the linear time function.

## Big O(n^2) : Quadratic Time Function

```cpp
int MultiplicationSum(short n) {
	int sum = 0;
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=n; j++) {
			sum = sum + (j * j);
		}
	}
	return sum;
}
```

It is $O(n^2)$, no need for explanation.
So, this algorithm depends on the input size, and the relation is the quadratic.

## Big O(Log n) : Logarithmic Time Function

```cpp
void fun1(short n) {
	short x = n;
	while(x>0) {
		x = x/2;
		cout << x << endl;
	}
}
``` 
It is the logarithmic function `O(log n)`;

## Important Question, Work Smart :)

The following two algorithms are O(n), but the second one is faster if the number is not the last number in the array.
```cpp
int FindNumberAlgo(int arr[10], short number) {
	int size = 10;
	int pos = -1;
	
	for(int i = 0; i<=n; i++) {
		if(arr[i] == number) pos = i;
	}
	
	return pos;
}
int FindNumberAlgo(int arr[10], short number) {
	int size = 10;
	
	for(int i = 0; i<=n; i++) {
		if(arr[i] == number) return i;
	}
	
	return -1;
}
```

## Big O Comparison and Conclusion
It is just comparison.

---
# Binary Data Structure: Real Examples
For example 79, represents 1,2,4,8, and 64.

Before start looping, think if you can implement your idea in another way. In `O(1)`.

It seems that the permission with the bitwise `&` is important.

review the scenario.
Each box has a number depending on the binary system, and the user has a number.
If you want to give the user access to some box, add to their number the number of that box.
Whenever you want to check if the user has access to some box, do the bitwise `&` operator between the number of the box and the user's number.

___
# Array DS
In `Cpp`, you can have dynamic arrays, that means after giving the size of the array, you can shrink/expand it.

Time complexity:
- `O(1)` to insert/access a single element.
- `O(n)` to insert/access all the array elements ( where n is the size of the array ).

Time complexity of finding an element in the array : `O(n)`.

> Arrays are used when the size of the data set it known.

---
# Matrix DS
`O(1)` for insert/access.
`O(n*k)` for insert/access all elements. Where `n` is the size of rows, and `k` is the size of columns.
`O(n*k)` for search for an element. 

---
# Stack DS
## Important : What is Stack Data Structure?
LIFO : last in first out.
Use case : call stack.

## STL : Stack
STL : Standard Template Library.
```cpp
#include <stack>
int main()
{
	stack<int> stackNumbers;

	stackNumbers.push(1);
	stackNumbers.push(2);
	stackNumbers.push(3);
	stackNumbers.push(4);

	// number of items
	cout << "Count : " << stackNumbers.size() << "\n";

	cout << "Items are : " << "\n";
	while (!stackNumbers.empty()) {
		cout << stackNumbers.top() << "\n";
		stackNumbers.pop();
	}
}
```

```
Count : 4
Items are :
4
3
2
1
```

## Stack Swap
This function just swap the pointers, it is `O(1)`.

```cpp
stack<int> stackNumbers1;
stack<int> stackNumbers2;

stackNumbers1.push(1);
stackNumbers1.push(2);
stackNumbers1.push(3);
stackNumbers1.push(4);

stackNumbers2.push(10);
stackNumbers2.push(20);
stackNumbers2.push(30);
stackNumbers2.push(40);

PrintStack(stackNumbers1);
PrintStack(stackNumbers2);

stackNumbers1.swap(stackNumbers2);

PrintStack(stackNumbers1);
PrintStack(stackNumbers2);
```

```
| 4 |
| 3 |
| 2 |
| 1 |
-----
| 40 |
| 30 |
| 20 |
| 10 |
-----
| 40 |
| 30 |
| 20 |
| 10 |
-----
| 4 |
| 3 |
| 2 |
| 1 |
-----
```

---
# Vector DS
Vector is a new version of stack.
It is built using stack.
Vector is an extension of stack.


compare the methods
you can deal with vector like array.

> [!Important]
> The built in data structures have a lot of built in features, use them.

---
# Queue Data Structure
## Important : What is Queue DS?
FIFO : first in first out.

## STL : Queue

```cpp
// #include <queue>
queue<int> _queue_01;
_queue_01.push(1);
_queue_01.push(2);
_queue_01.push(3);
_queue_01.push(4);

cout << "Count : " << _queue_01.size() << "\n";
// first element
cout << "Front : " << _queue_01.front() << "\n";
// last element
cout << "Back  : " << _queue_01.back() << "\n";

PrintQueue(_queue_01);
```

```
Count : 4
Front : 1
Back  : 4
------------
1 2 3 4
------------
```

## Swap Queue

```cpp
queue<int> _queue_01;
queue<int> _queue_02;
_queue_01.push(1);
_queue_01.push(2);
_queue_01.push(3);
_queue_01.push(4);

_queue_02.push(10);
_queue_02.push(20);
_queue_02.push(30);
_queue_02.push(40);

PrintQueue(_queue_01);
PrintQueue(_queue_02);

_queue_01.swap(_queue_02);

PrintQueue(_queue_01);
PrintQueue(_queue_02);
```

```
------------
1 2 3 4
------------
------------
10 20 30 40
------------
------------
10 20 30 40
------------
------------
1 2 3 4
------------
```

---
Print Stack & Queue
```cpp
template <typename element>
void PrintStack(stack<element> _stack) {
	while (!_stack.empty()) {
		cout << "| " << _stack.top() << " |" << "\n";
		_stack.pop();
	}
	cout << "-----" << "\n";
}

template <typename element>
void PrintQueue(queue<element> _queue) {
	int size = _queue.size() * 3;
	cout << clsOutput::GetChar(size, "-") << "\n";
	while (!_queue.empty()) {
		cout << _queue.front() << " ";
		_queue.pop();
	}
	cout << "\n" << clsOutput::GetChar(size, "-") << "\n";
}
```

---
# Singly Linked List
## What is Linked List?

The main block in linked list is the node.
Linked lists is composed of nodes. Each node contains two fields : 
- Data field
- Pointer field, that has the address of the next node.

In C, before the dynamic arrays, they used linked list because they don't know the size of the data. So they need to add new data in the runtime.
Linked list allows you to add data dynamically on run time.
Linked list is a linear data structure.
It is used to build other data structures, like Stack, Queue, and others.

## Singly Lined List Implementation

```cpp
class Node {
public:
	int data;
	Node* next;
};

void PrintLinkList(Node* _head) {
	cout << "HEAD -> ";

	while (_head) {
		cout << "[ " << _head->data << " ]" << " -> ";
		_head = _head->next;
	}

	cout << "NULL";
}

void DeleteLinkedList(Node* _head) {
	if (!_head) return;
	DeleteLinkedList(_head->next);
	delete _head;
}


int main()
{
	Node* head = NULL;

	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;

	node1 = new Node();
	node2 = new Node();
	node3 = new Node();

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;

	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	PrintLinkList(head);


	DeleteLinkedList(head);
}
```

```
HEAD -> [ 1 ] -> [ 2 ] -> [ 3 ] -> NULL
```

> [!Website]
> pythontutor.com, visualizes what is happening in the code.

## Operations - Insert At Beginning

```cpp
void InsertAtBeginning(Node*& head, int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = head;
	head = new_node;
}

int main()
{
	Node* head = NULL;
	PrintLinkedList(head);

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 5);
	InsertAtBeginning(head, 6);

	PrintLinkedList(head);
	DeleteLinkedList(head);
	PrintLinkedList(head);
}
```

```
HEAD -> NULL
HEAD -> [ 6 ] -> [ 5 ] -> [ 4 ] -> [ 3 ] -> [ 2 ] -> [ 1 ] -> NULL
HEAD -> NULL
```

## Operations - Find

```cpp
Node* Find(Node* head, int data) {
	while (head) {
		if (head->data == data) return head;
		head = head->next;
	}
	return NULL;
}

int main()
{
	Node* head = NULL;
	PrintLinkedList(head);

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 5);
	InsertAtBeginning(head, 6);

	PrintLinkedList(head);

	Node* _find_node = Find(head, 3);
	if (_find_node) cout << _find_node->data << "\n";
	else cout << "node not found" << "\n";

	DeleteLinkedList(head);
}
```

```
HEAD -> NULL
HEAD -> [ 6 ] -> [ 5 ] -> [ 4 ] -> [ 3 ] -> [ 2 ] -> [ 1 ] -> NULL
3
```

## Operations - Insert After

```cpp
void InsertAfter(Node* node, int data) {
	if(node) InsertAtBeginning(node->next, data);
}

int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 5);
	InsertAtBeginning(head, 6);

	PrintLinkedList(head);

	Node* node = Find(head, 3);
	InsertAfter(node, 55);

	PrintLinkedList(head);

	DeleteLinkedList(head);
}
```

```
HEAD -> [ 6 ] -> [ 5 ] -> [ 4 ] -> [ 3 ] -> [ 2 ] -> [ 1 ] -> NULL
HEAD -> [ 6 ] -> [ 5 ] -> [ 4 ] -> [ 3 ] -> [ 55 ] -> [ 2 ] -> [ 1 ] -> NULL
```

## Operations - Insert At End

```cpp
void InsertAtEnd(Node** head_ref, int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	
	while (*head_ref) {
		head_ref = &((*head_ref)->next);
	}
	*head_ref = new_node;
}

int main()
{
	Node* head = NULL;

	InsertAtEnd(&head, 1);
	InsertAtEnd(&head, 2);
	InsertAtEnd(&head, 3);

	PrintLinkedList(head);

	DeleteLinkedList(head);
}
```

```
HEAD -> [ 1 ] -> [ 2 ] -> [ 3 ] -> NULL
```

## Operations - Delete Node

```cpp
void DeleteNode(Node** head_ref, int data) {
	if (!*head_ref) return;

	while (*head_ref && (*head_ref)->data != data) {
		head_ref = &((*head_ref)->next);
	}
	if (!*head_ref) return;

	Node* node_to_delete = *head_ref;
	*head_ref = (*head_ref)->next;
	delete node_to_delete;
}

int main()
{
	Node* head = NULL;

	InsertAtEnd(&head, 1);
	InsertAtEnd(&head, 2);
	InsertAtEnd(&head, 3);

	PrintLinkedList(head);

	DeleteNode(&head, 2);

	PrintLinkedList(head);

	DeleteLinkedList(head);
}
```

```
HEAD -> [ 1 ] -> [ 2 ] -> [ 3 ] -> NULL
HEAD -> [ 1 ] -> [ 3 ] -> NULL
```

## Operations - Delete First Node

```cpp
void DeleteFirstNode(Node*& head) {
	if (!head) return;
	Node* node_to_delete = head;
	head = head->next;
	delete node_to_delete;
}

int main()
{
	Node* head = NULL;

	InsertAtEnd(&head, 1);
	InsertAtEnd(&head, 2);
	InsertAtEnd(&head, 3);

	PrintLinkedList(head);

	DeleteFirstNode(head);

	PrintLinkedList(head);

	DeleteLinkedList(head);
}
```

```
HEAD -> [ 1 ] -> [ 2 ] -> [ 3 ] -> NULL
HEAD -> [ 2 ] -> [ 3 ] -> NULL
```

## Operations - Delete Last Node

```cpp
void DeleteLastNode(Node*& _head) {
	Node* head = _head;
	if (!head) return;
	while (head->next && head->next->next) {
		head = head->next;
	}

	if (!head->next) {
		delete head;
		_head = NULL;
		return;
	}

	delete head->next;
	head->next = NULL;
}

int main()
{
	Node* head = NULL;

	InsertAtEnd(&head, 1);
	InsertAtEnd(&head, 2);
	InsertAtEnd(&head, 3);

	PrintLinkedList(head);

	DeleteLastNode(head);
	PrintLinkedList(head);

	DeleteLastNode(head);
	PrintLinkedList(head);

	DeleteLastNode(head);
	PrintLinkedList(head);

	DeleteLastNode(head);
	PrintLinkedList(head);

	DeleteLinkedList(head);
}
```

```
HEAD -> [ 1 ] -> [ 2 ] -> [ 3 ] -> NULL
HEAD -> [ 1 ] -> [ 2 ] -> NULL
HEAD -> [ 1 ] -> NULL
HEAD -> NULL
HEAD -> NULL
```

---
# Doubly Linked List
## What is Doubly Linked List?
Each node has :
- data.
- pointer that stores the address of the next node.
- pointer that stores the address of the previous node.

## Doubly Linked List Implementation

```cpp
class Node {
public:
	int data;
	Node* next;
	Node* prev;
};


void PrintLinkedList(Node* _head) {
	cout << "HEAD -> ";

	while (_head) {
		cout << "[ " << _head->data << " ]" << " <-> ";
		_head = _head->next;
	}
	
	cout << "\b\b\b\b-> NULL" << "\n";
}

void DeleteLinkedList(Node* &_head) {
	if (!_head) return;
	DeleteLinkedList(_head->next);
	delete _head;
	_head = NULL;
}

int main()
{
	Node* head = NULL;

	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;

	node1 = new Node();
	node2 = new Node();
	node3 = new Node();

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;

	head = node1;

	node1->next = node2;
	node1->prev = NULL;

	node2->next = node3;
	node2->prev = node1;

	node3->next = NULL;
	node3->prev = node2;
	
	PrintLinkedList(head);
	DeleteLinkedList(head);
	PrintLinkedList(head);
}

```

```
HEAD -> [ 1 ] <-> [ 2 ] <-> [ 3 ] -> NULL
HEAD-> NULL
```

## Operation - Insert At Beginning

```cpp
void InsertAtBeginning(Node*& head, int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = head;
	new_node->prev = NULL;
	if (head) head->prev = new_node;
	head = new_node;
}

int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);

	PrintLinkedList(head);
	DeleteLinkedList(head);
	PrintLinkedList(head);
}
```

```
HEAD -> [ 3 ] <-> [ 2 ] <-> [ 1 ] -> NULL
HEAD-> NULL
```

## Operation - Find Node

```cpp
Node* Find(Node* head, int data) {
	while (head) {
		if (head->data == data) return head;
		head = head->next;
	}
	return NULL;
}

int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);

	Node* node1 = Find(head, 1);
	Node* node2 = Find(head, 11);
	if (node1) cout << node1->data << "\n"; else cout << "node1 not found" << "\n";
	if (node2) cout << node2->data << "\n"; else cout << "node2 not found" << "\n";

	DeleteLinkedList(head);
}
```

```
1
node2 not found
```

## Operation - Insert After

```cpp
void InsertAfter(Node* node, int data) {
	if (!node) return;
	InsertAtBeginning(node->next, data);
	node->next->prev = node;
}

int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);

	Node* node1 = Find(head, 1);
	Node* node2 = Find(head, 2);
	Node* node3 = Find(head, 3);

	InsertAfter(node1, 111);
	InsertAfter(node2, 222);
	InsertAfter(node3, 333);

	PrintLinkedList(head);
	DeleteLinkedList(head);
}
```

```
HEAD -> [ 3 ] <-> [ 333 ] <-> [ 2 ] <-> [ 222 ] <-> [ 1 ] <-> [ 111 ] -> NULL
```

## Operation - Insert at End

```cpp
void InsertAtEnd(Node** head_ref, int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	Node* previous = NULL;
	
	while (*head_ref) {
		previous = *head_ref;
		head_ref = &((*head_ref)->next);
	}
	*head_ref = new_node;
	new_node->prev = previous;
}

int main()
{
	Node* head = NULL;

	InsertAtEnd(&head, 1);
	InsertAtEnd(&head, 2);
	InsertAtEnd(&head, 3);
	InsertAtBeginning(head, 0);

	PrintLinkedList(head);
	DeleteLinkedList(head);
}
```

```
HEAD -> [ 0 ] <-> [ 1 ] <-> [ 2 ] <-> [ 3 ] -> NULL
```

New Print
```cpp
enum enVisitList {enForword = 0, enBackword = 1};

void PrintLinkedList(Node* _head, enVisitList direction, bool print_in_reverse = false) {
	string arrow = "->";
	cout << "NULL " << arrow << " ";
	Node* prev = NULL;

	while (_head) {
		cout << "[ " << _head->data << " ]" << " " << arrow << " ";
		prev = _head;
		_head = direction == enVisitList::enForword ? _head->next : _head->prev;
	}
	
	cout << " NULL" << "\n";

	if(print_in_reverse && direction==enVisitList::enForword) PrintLinkedList(prev, enVisitList::enBackword);
}
```

```
NULL -> [ 0 ] -> [ 1 ] -> [ 2 ] -> [ 3 ] ->  NULL
NULL -> [ 3 ] -> [ 2 ] -> [ 1 ] -> [ 0 ] ->  NULL
```

## Operation - Delete Node

```cpp
void DeleteNode(Node** head_ref, int data) {
	if (!*head_ref) return;

	while (*head_ref && (*head_ref)->data != data) {
		head_ref = &((*head_ref)->next);
	}
	if (!*head_ref) return;

	Node* node_to_delete = *head_ref;

	if ((*head_ref)->next)
		(*head_ref)->next->prev = (*head_ref && (*head_ref)->prev) ? (*head_ref)->prev : NULL;

	(*head_ref) = (*head_ref) && (*head_ref)->next ? (*head_ref)->next : NULL;

	delete node_to_delete;
}

int main()
{
	Node* head = NULL;

	InsertAtEnd(&head, 1);
	InsertAtEnd(&head, 2);
	InsertAtEnd(&head, 3);

	DeleteNode(&head, 3);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteNode(&head, 1);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteNode(&head, 2);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteNode(&head, 2);
	PrintLinkedList(head, enVisitList::enForword);

	DeleteLinkedList(head);
}
```

```
NULL -> [ 1 ] -> [ 2 ] ->  NULL
NULL -> [ 2 ] ->  NULL
NULL ->  NULL
NULL ->  NULL
```

## Operation - Delete First Node

```cpp
void DeleteFirstNode(Node*& head) {
	if (!head) return;
	Node* node_to_delete = head;
	if (head->next)	head->next->prev = NULL;
	head = (head->next) ? head->next : NULL;
	delete node_to_delete;
}

int main()
{
	Node* head = NULL;

	InsertAtEnd(&head, 1);
	InsertAtEnd(&head, 2);
	InsertAtEnd(&head, 3);

	DeleteFirstNode(head);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteFirstNode(head);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteFirstNode(head);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteFirstNode(head);
	PrintLinkedList(head, enVisitList::enForword);

	DeleteLinkedList(head);
}
```

```
NULL -> [ 2 ] -> [ 3 ] ->  NULL
NULL -> [ 3 ] ->  NULL
NULL ->  NULL
NULL ->  NULL
```

## Operation - Delete Last Node

```cpp
void DeleteLastNode(Node*& _head) {
	Node* head = _head;
	if (!head) return;
	while (head->next && head->next->next) {
		head = head->next;
	}

	if (!head->next) {
		delete head;
		_head = NULL;
		return;
	}

	delete head->next;
	head->next = NULL;
}

int main()
{
	Node* head = NULL;

	InsertAtEnd(&head, 1);
	InsertAtEnd(&head, 2);
	InsertAtEnd(&head, 3);

	DeleteLastNode(head);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteLastNode(head);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteLastNode(head);
	PrintLinkedList(head, enVisitList::enForword);
	DeleteLastNode(head);
	PrintLinkedList(head, enVisitList::enForword);

	DeleteLinkedList(head);
}
```

```
NULL -> [ 1 ] -> [ 2 ] ->  NULL
NULL -> [ 1 ] ->  NULL
NULL ->  NULL
NULL ->  NULL
```

---
# What is Circular Linked List?
In case of singly linked list the last node points to the first node.
In case of doubly linked list, the `next` of the last node points to the first node, and the `previous` of the first node points to the last node.

A real example is a fixed sized buffer, whenever you reached the last node, you replace the first node and keep circling.
Look at this :)
```cpp
int main()
{
	Node* head = NULL;

	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;

	node1 = new Node();
	node2 = new Node();
	node3 = new Node();

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;

	head = node1;

	node1->next = node2;
	node1->prev = node3;

	node2->next = node3;
	node2->prev = node1;

	node3->next = node1;
	node3->prev = node2;

	Node* current = node1;
	while (clsInput::ReadBool("hi: ")) {
		for (int i = 0; i < 3; i++) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << "\n";
	}

	delete node3;
	delete node2;
	delete node1;
}
```

---
# Abstract Data Type (ADT)
Use the library/class without caring about the implementation. You just use the thing, you don't know how it is built.

> An ADT defines what a data type can do, but not how it does it.
> Examples: Vector, Stack, Queue, etc.
---
# Map
The Map is a data structure.
The key shouldn't be repeated, if you repeat it, the second value override the first value.
It represent an associative array.

It doesn't depend on indices like arrays, it depends on keys, these keys can be `int-string-etc`.
> Each element in the map is a key-value pair, where the key and value can be of any data type.

Map is called dictionary in other languages like C# and Python.

By default the data is sorted ascendingly depending on the keys. `A->Z`.

Searching for an element takes `O(log n)`.

Example of usage
```cpp
#include <map>

int main()
{
	map<string, int> studentsGrades;
	
	studentsGrades["Ali"] = 77;
	studentsGrades["Ahmed"] = 85;
	studentsGrades["Fadi"] = 95;
	
	// loop over the data
	for (const auto& pair : studentsGrades) {
		cout << "Student: " << pair.first << ", Grade: " << pair.second << "\n";
	}
	
	// find a student
	cout << "\n\n";
	string student_name = "Ali";
	// studentsGrades.end() represents no element found
	if (studentsGrades.find(student_name) != studentsGrades.end()) {
		cout << "Student: " << student_name << ", Grade: " << studentsGrades[student_name] << "\n";
	}
	else {
		cout << "Grage not found for [" << student_name << "]" << "\n";
	}

	student_name = "Aloush";
	if (studentsGrades.find(student_name) != studentsGrades.end()) {
		cout << "Student: " << student_name << ", Grade: " << studentsGrades[student_name] << "\n";
	}
	else {
		cout << "Grade not found for [" << student_name << "]" << "\n";
	}
}
```

```
Student: Ahmed, Grade: 85
Student: Ali, Grade: 77
Student: Fadi, Grade: 95

Student: Ali, Grade: 77
Grade not found for [Aloush]
```

Look at this : 
```cpp
for (pair<string, int> _pair : studentsGrades) {
	cout << "Student: " << _pair.first << ", Grade: " << _pair.second << "\n";
}

// you can also make this
for (const pair<string, int>& _pair : studentsGrades) {
	cout << "Student: " << _pair.first << ", Grade: " << _pair.second << "\n";
}

// but you can't make this, idk why
for (pair<string, int>& _pair : studentsGrades) {
	cout << "Student: " << _pair.first << ", Grade: " << _pair.second << "\n";
}
```

You can put this, but I did not test it.
```cpp
map<pair<string, string>, int> students;
```

---
# Union
It is a data type.
It is a data structure.

Union vs Structure
If you have three variables, the structure put them in three different memory spaces, however, the union put them all in one memory space.
We use the union to reduce the space we use in the memory.
The size of the Union variable, will be the size of the biggest member in it.
If we have for example `char char float`, the size of the union variable will be as the `float` size.
You need to be carful in dealing with it.

You can use one variable at a time.
If you put a value in variable1, you'll find garbage data in the other variables.
Same thing, if you put a value in variable2, you'll find garbage data in variable1.
In other words, when you store one value, you loose the other values that you have stored.

> Unions can lead to undefined behavior if not used properly. 
> If you read from a member that was not the last one written to, the value might not make sense for that type.
> The Union shares the same memory space for all its members. If you store a value in some member, that will modify the same memory space.

Example of usage : 
```cpp
union MyUnion {
	int intValue;
	float floatValue;
	char charValue;
};

int main()
{
	MyUnion my_union;

	my_union.intValue = 32;
	cout << "Int value : " << my_union.intValue << "\n";

	my_union.floatValue = 32.1f;
	cout << "Float value : " << my_union.floatValue << "\n";

	my_union.charValue = 'A';
	cout << "Char value : " << my_union.charValue << "\n";
}
```

```
Int value : 32
Float value : 32.1
Char value : A
```

Node
```cpp
auto x = 3.12; // the compilor makes it double
auto x = 3.12f; // now the compilor knows it is float
```