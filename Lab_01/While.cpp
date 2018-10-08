#include <iostream>
#include <cstdlib> 

using namespace std;

int main() {

	int n;

	cin >> n; 

	do {
		if (n < 0) {
			exit(0);
		}
		else if (n != -1 && n % 2 == 0) {

			cout << "EVEN" << endl;

			main();
		}
		else if (n != -1 && n % 2 == 1) {

			cout << "ODD" << endl;

			main();
		}
		else { return(0); }

	} while (n > 0);
	 
} 