### Course[05]
How to print a char based on a number
```cpp
char(ascii_number); // to get the char

// or you can do this

char c = ascii_number;
```

To get an entire line
```c
string Text;
getline(cin, Text); // I'm not sure about it, because I did not try it
```

To get a random number
```cpp
// this is for rand() and srand()
#include <cstdlib> 
// this is for time()
#include <ctime>

// put this in main, you need to call it only once
srand((unsigned)time(NULL));

// rand() will give you a number btw 0 and MAX_INT
cout << rand() << endl;
// you can get the right most digit like this. Now you have a number btw 0 and 9
cout << rand()%10 << endl;

// you can use this, if you put RandomNumber(1, 10) then 1 and 10 will be included
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum; 
}
```

Note
```cpp
// you can do this in cpp
  string word = "";
  word += 'a';
}
```

