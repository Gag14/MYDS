#include <iostream>
#include "Vector.h" // Include your Vector class header
void print(MYDS::Vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
}
int main()
{
    // Test default constructor
    MYDS::Vector<int> v1;
    if (v1.size() == 0)
    {
        std::cout << "Default constructor test passed.\n";
    }
    else
    {
        std::cerr << "Error: Default constructor test failed.\n";
    }

    // Test size constructor
    MYDS::Vector<int> v2(5);
    if (v2.size() == 5)
    {
        std::cout << "Size constructor test passed.\n";
    }
    else
    {
        std::cerr << "Error: Size constructor test failed.\n";
    }

    // Test initializer list constructor
    MYDS::Vector<int> v3 = {1, 2, 3, 4, 5};
    if (v3.size() == 5)
    {
        std::cout << "Initializer list constructor test passed.\n";
    }
    else
    {
        std::cerr << "Error: Initializer list constructor test failed.\n";
    }

    // Test copy constructor
    MYDS::Vector<int> v4(v3);
    if (v4.size() == 5 && v4 == v3)
    {
        std::cout << "Copy constructor test passed.\n";
    }
    else
    {
        std::cerr << "Error: Copy constructor test failed.\n";
    }

    // Test pushback
    v1.pushback(42);
    try {
    print(v1); }
    catch(std::out_of_range& e) 
    {
        std::cout << e.what() << '\n';
    }
    std::cout << v1.size() << " : size" << v1[0] << " : v1[0]\n";
    if (v1.size() == 1 && v1[0] == 42)
    {
        std::cout << "Pushback test passed.\n";
    }
    else
    {
        std::cerr << "Error: Pushback test failed.\n";
    }

    // Test pop_back
    v3.pop_back();
    v4.pop_back();
    if (v3.size() == 4 && v3 == v4 && v3[v3.size() - 1] == 4)
    {
        std::cout << "Pop_back test passed.\n";
    }
    else
    {
        std::cerr << "Error: Pop_back test failed.\n"; //<< v3.size() << '\n' <<
    }

    // Test erase
    v2[2] = 7;
    std::cout << "Here is the vector before erasing\n";
    print(v2);
    if (v2.erase(3) && v2.size() == 4 && v2[3] == 7)
    {
        std::cout << "Erase test passed.\n";
    }
    else
    {
        std::cerr << "Error: Erase test failed.\n";
    }
    std::cout << "Here is the vector after erasing\n";
    print(v2);

    // Test insert
    if (v2.insert(2, 99) && v2.size() == 5 && v2[2] == 99)
    {
        std::cout << "Insert test passed.\n";
    }
    else
    {
        std::cerr << "Error: Insert test failed.\n";
    }

    // Test find
    size_t index = v3.find(3);
    if (index == 2)
    {
        std::cout << "Find test passed.\n";
    }
    else
    {
        std::cerr << "Error: Find test failed.\n";
    }

    return 0;
}
