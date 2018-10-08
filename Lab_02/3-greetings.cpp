#include <iostream>
#include "Greet.h"

using namespace std;

// A polite greeting
void polite(string name){
    cout << "Hello, " << name << "." << endl;
}

// A rude greeting
void rude(string name){
    cout << "Go away, " << name << "!" << endl;
}

int main(int argc, const char * argv[]) {
    // Read in the user's name
    string name;
    cin >> name;
    
    if (name[0] == 'J'){
        // If the name starts with 'J', be rude
        greet(name, rude);
    }
    else{
        // Otherwise be polite
        greet(name, polite);
    }
    
    return 0;
}