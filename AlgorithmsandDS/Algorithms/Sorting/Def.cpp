#include "MYAL.h"

#include <iostream>
#include <vector>

namespace MYAL {
    template <typename X>
    std::vector<X> BubbleSort(std::vector<X> vec) {
        std::vector<X> sortedvec = vec;
        bool swapped = false;
        while (!swapped) {
            swapped = true;
            for (size_t i = 0; i < sortedvec.size() - 1; ++i) {
                if (sortedvec[i] > sortedvec[i + 1]) {
                    swap(sortedvec[i], sortedvec[i + 1]); // Call within the same namespace
                    swapped = false;
                }
            }
        }
        return sortedvec;
    }

    template <typename X>
    void swap(X& val1, X& val2) {
        X tmp = val1;
        val1 = val2;
        val2 = tmp;
    }

    template <typename X>
    void print(const std::vector<X>& vec) {
        for (const X& i : vec) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }

    template <typename X>
    void InsertionSort(std::vector<X>& vec)
    {
        for(int i = 1; i < vec.size(); ++i) 
        {
            int j = i;
            while(vec[j] < vec[j- 1] && j - 1 >= 0) 
            {
                std::swap(vec[j], vec[j - 1]);
                --j;
            }
        }
    }
}


