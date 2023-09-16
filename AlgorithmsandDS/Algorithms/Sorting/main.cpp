#include <iostream>
#include <vector>

#include "MYAL.h"
#include "Def.cpp"

int main() {
    std::vector<int> vec = {8, 9, 5, 5, 5, 3, -14, 9, 7, -98, 0};
    std::cout << "The given array is: " << std::endl;
    MYAL::print(vec);
    std::cout << "Testing the Bubble Sort..." << std::endl;
    std::vector<int> sortedvec = MYAL::BubbleSort(vec);
    MYAL::print(sortedvec);
    std::cout << "Testing the Insertion Sort..." << std::endl;
    MYAL::InsertionSort(vec);
    MYAL::print(vec);
    return 0;
}

