#include <iostream>
#include "/home/gag/AlgorithmsAndDS/DS/Vector/Vector.h"

int main() 
{
    MYDS::Vector<int> vec = {1, 2, 4, 5};
    std::cout << vec[0] << std::endl;
    vec.pushback(3);
    std::cout << vec[vec.size() - 1];
}
