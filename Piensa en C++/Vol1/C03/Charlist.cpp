//: Charlist.cpp
// Display all the ASCII characters
// Demostrates "for"
#include <iostream>
using namespace std;

int main()
{
	for(int i = 0; i < 128; i = i + 1)
		if(i != 26) // ANSI Terminal Clear screen
			cout << "value: " << i
				 << "\tcharacter: "
				 << char(i)
				 << endl;
}///:~