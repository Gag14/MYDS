#ifndef __Vector__
#define __Vector__

#include "../Iterator.h"

#include <iostream>
#include <initializer_list>
namespace MYDS
{
    template <class X>
    class Vector
    {
    public:
        // Ctors & Dtor

        Vector();
        Vector(int size);
        Vector(const std::initializer_list<X> &list);
        Vector(const Vector &other);
        ~Vector();

        // Operators

        Vector &operator=(const Vector &rhs);
        Vector operator+(const Vector &rhs);
        bool operator==(const Vector &rhs);
        X &operator[](size_t position);

        // Public methods

        void pushback(const X &element);
        void pop_back();
        size_t size();
        bool erase(const X &element);
        bool insert(size_t position, const X &element);
        size_t find(const X &key);

        // Mothods with Iterator

        Iterator<X> erase(Iterator<X> iter);
        Iterator<X> insert(Iterator<X> &position, const X &element);
        Iterator<X> &begin();
        Iterator<X> &end();

        // Sorting methods

        void BubbleSort();
        void SelectionSort();
        void InsertionSort();
        void MergeSort();
        void QuickSort();

        // Class Iterator
/*
        template <class X>              
        class Iterator : public MYDS::Iterator<X>
        {
        public:
            Iterator operator=(const Iterator<X> rhs) = 0;
            X &operator*();
            X *operator->();
            Iterator &operator++();
            Iterator operator++(int);
            Iterator &operator--();
            Iterator operator--(int);
            Iterator operator+(difference_type n);
            Iterator operator-(difference_type n);
            difference_type operator-(const Iterator<X> &other);
            bool operator==(const Iterator<X> &other);
            bool operator!=(const Iterator<X> &other);
            bool operator>(const Iterator<X> &other);
            bool operator<(const Iterator<X> &other);
            bool operator>=(const Iterator<X> &other);
            bool operator<=(const Iterator<X> &other);

        private:
            X *data;
        };
        // End of Class Iterator
*/
    private:
        size_t m_size;
        size_t m_capacity;
        X *m_elements;
    };
}

#endif // End of Vector.h
