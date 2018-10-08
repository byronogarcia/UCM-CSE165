#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    
    while (true) {
        cin >> b;
        cin >> a;
        
        if (a == -2) {
            break;
        }
        else if (a == -1) {
            cout << endl;
        }
        else {
            for (int i = a; i > 0; i--) {
                cout << b;
            }
        }
    }
    
    return 0;
}
	
