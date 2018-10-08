#include <iostream>
#include <string>

using namespace std;

int main() {
	string strst;
	int n;

	getline(cin, strst);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << strst << endl;
	}
	//system("Pause");
}