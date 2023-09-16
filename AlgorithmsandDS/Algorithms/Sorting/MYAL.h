#ifndef __MYAL__
#define __MYAL__


#include <iostream>
#include <vector>

namespace MYAL {
    template <typename X>
    std::vector<X> BubbleSort(std::vector<X> vec);

    template <typename X>
    void print(const std::vector<X>& vec);

    template <typename X>
    void swap(X& val1, X& val2);

    template <typename X>
    void InsertionSort(std::vector<X>& vec);
}

#endif  // end of MYAL namespace
