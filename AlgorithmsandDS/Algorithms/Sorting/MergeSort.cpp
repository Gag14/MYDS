#include <iostream>
#include <vector>

namespace MYAL 
{  
    template <typename X>
    void print(const std::vector<X>& vec) {
        for (const X& i : vec) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }


    template <typename X>
    void merge(std::vector<X>& vec, int first, int mid, int last) 
    {
        std::vector<X> result(last + 1);
        int index = first;
        int start1 = first;
        int end1 = mid;
        int start2 = mid + 1;
        int end2 = last;
        while(start1 <= end1 && start2 <= end2) 
        {
            result[index++] = vec[start1] < vec[start2] ? vec[start1++] : vec[start2++];
        }
        while(start1 <= end1) 
        {
            result[index++] = vec[start1++];
        }
        while(start2 <= end2) 
        {
            result[index++] = vec[start2++];
        }
        for(int i = first; i <= last; ++i) 
        {
            vec[i] = result[i];
        }
    } 
    template <typename X>
    void MergeSort(std::vector<X>& vec, int first, int last) 
    {
        if(first < last) {
        int mid = first + (last - first) / 2;
        std::cout << mid << std::endl;
        MergeSort(vec, first, mid);
        MergeSort(vec, mid + 1, last);
        merge(vec, first, mid, last);
        }
    }
}
int main() 
{
    int i= 0, num = 0;
    std::vector<int> vec, vec1, vec2;
//    std::cout << "Enter 4 elements of 1st sorted array: " << std::endl;
//    while(i++ < 4) { std::cin >> num; vec1.push_back(num); }
    i = 0;
//    std::cout << "Enter 5 elements of 2nd sorted array: " << std::endl;
//    while(i++ < 5) { std::cin >> num; vec1.push_back(num); }
//    MYAL::merge(vec1, 0, 3, 8);
//    std::cout << "Result of Merge is..." << std::endl;
//    MYAL::print(vec1);
    std::cout << "Enter 8 elements for Merge Sort" << std::endl;
    i = 0;
    while(i++ < 8) { std::cin >> num; vec2.push_back(num); }
    std::cout << "Result of Merge Sort is..." << std::endl;
    MYAL::MergeSort(vec2, 22, 7);
    MYAL::print(vec2);

return 0;
}
