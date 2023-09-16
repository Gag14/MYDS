#ifndef __Iterator_Interface__
#define __Iterator_Interface__

#include <iostream>
#include <iterator>

namespace MYDS
{
    template <class X>
    class Iterator
    {
    public:
        using difference_type = std::ptrdiff_t; // Use ptrdiff_t as difference_type

        // Ctor Dtor

        Iterator();
        Iterator(const Iterator<X> &other);
        virtual ~Iterator();

        // Operators
        virtual Iterator operator=(const Iterator<X> rhs) = 0;
        virtual X &operator*() = 0;
        virtual X *operator->() = 0;
        virtual Iterator &operator++() = 0;
        virtual Iterator operator++(int) = 0;
        virtual Iterator &operator--() = 0;
        virtual Iterator operator--(int) = 0;
        virtual Iterator operator+(difference_type n) = 0;
        virtual Iterator operator-(difference_type n) = 0;
        virtual difference_type operator-(const Iterator<X> &other) = 0;
        virtual bool operator==(const Iterator<X> &other) = 0;
        virtual bool operator!=(const Iterator<X> &other) = 0;
        virtual bool operator>(const Iterator<X> &other) = 0;
        virtual bool operator<(const Iterator<X> &other) = 0;
        virtual bool operator>=(const Iterator<X> &other) = 0;
        virtual bool operator<=(const Iterator<X> &other) = 0;
    };
}
#endif // End of Iterator Interface