#ifndef Entry_h
#define ENTRY_H
// We should include <string> here
#include <iostream>
#include <string>

using namespace std;

struct Entry {
	string name, last, mail;

	void setName(const string first_name) {
		name = first_name;
	}
	void setLastname(const string last_name) {
		last = last_name;
	}
	void setEmail(const string email) {
		mail = email;
	}
	void print() {
		cout << "First name: " << name << endl;
		cout << "Last name: " << last << endl;
		cout << "Email: " << mail << endl;
	}
};

#endif;
