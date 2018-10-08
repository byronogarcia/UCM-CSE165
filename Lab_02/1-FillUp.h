#ifndef FillUp_h
#define FillUp_h


// A simple function that fills in an array with numbers
// corresponding to the indices
void fillUp(int someList[], int size){
    for (int i = 0; i < size; i++) {
        someList[i] = i;
    }
}

// A function to print out the array, one element per line
void print(int someList[], int size){
    for (int i = 0; i < size; i++) {
        std::cout << someList[i] << std::endl;
    }
}

// A function to print the value of a specific array position
void printPos(int someList[], int pos){
    std::cout << someList[pos] << std::endl;
}

#endif /* FillUp_h */