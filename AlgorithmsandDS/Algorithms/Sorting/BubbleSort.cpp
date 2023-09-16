#include <iostream>
#include <vector>



namespace MYAL
{
    template <typename X>
    std::vector<X> BubbleSort(std::vector<X>& vec);
    template <typename X>
    void print(const std::vector<X> vec);
    template <typename X>
    void swap(X& val1, X& val2);
}
namespace MYAL {
template <typename X>
std::vector<X> BubbleSort(std::vector<X> vec) 
{
    std::vector<X> sortedvec = vec;
    bool swapped = 0;
    while(!swapped) {
        for(int i = 0; i < sortedvec.size() - 1; ++i) 
        {
            if(sortedvec[i] > sortedvec[i + 1]) 
            {
                MYAL::swap(sortedvec[i], sortedvec[i + 1]); swapped = 1;
            }
        }
        !swapped;
    }
    return sortedvec;
}

template <typename X>
void swap(X& val1, X& val2) 
{
    X tmp = val1;
    val1 = val2;
    val2 = tmp;
}

template <typename X>
void print(const std::vector<X> vec) 
{
    for(const X& i : vec) { std::cout << i << ", "; }
    std::cout << std::endl;
}
}

int main() 
{
    std::cout << "Testing the Bubble Sort..." << std::endl;
    std::vector<int> vec = {8, 9, 5, 5, 5, 3, -14, 9, 7, -98, 0};
    std::cout << "The given array is: " << std::endl;
    MYAL::print(vec);
    std::vector<int> sortedvec = MYAL::BubbleSort(vec);
    std::cout << "Bubble sort function returned the array below: " << std::endl;
    MYAL::print(sortedvec);
return 0;
}

