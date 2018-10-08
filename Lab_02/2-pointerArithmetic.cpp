#include <iostream>
#include "Input.h"

using namespace std;

int main() {
    
    // The variable a comes from the Input.h file
    
    // The pointer p points to the address of a
    short* p = &a;
    
    // The pointer c points to the same place as p
    char* c = (char*)p;
    
    // Increment the value of c
    c++;
    
    // Print the short pointed to by c
    cout << *(short*)c << endl;
    
    
    return 0;
}