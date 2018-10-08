#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream in("words.txt");

	int words = 0;
	string word;

	while(in >> word) {
		++words;
	}
	cout << words << endl;
}