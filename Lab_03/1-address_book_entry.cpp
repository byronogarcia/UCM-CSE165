#include <iostream>
#include "Entry.h"

using namespace std;

int main(int argc, const char * argv[])
{
	string name, lastname, email;

	cin >> name;
	cin >> lastname;
	cin >> email;

	Entry myEntry;

	myEntry.setName(name);
	myEntry.setLastname(lastname);
	myEntry.setEmail(email);

	myEntry.print();

	system("Pause");

	return 0;
}