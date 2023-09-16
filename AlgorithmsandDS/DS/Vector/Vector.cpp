#include "Vector.h"

#include <stdexcept>

// Ctors

template <typename X>
MYDS::Vector<X>::Vector() : m_size(0), m_capacity(1), m_elements(nullptr) { m_elements = new X[m_capacity]; }
template <typename X>
MYDS::Vector<X>::Vector(int size) : m_size(size)
{
    m_capacity = m_size;
    m_elements = new X[m_capacity];
}
template <typename X>
MYDS::Vector<X>::Vector(const std::initializer_list<X> &list) : m_size(list.size()), m_capacity(list.size()), m_elements(new X[list.size()])
{
    std::copy(list.begin(), list.end(), m_elements);
}
template <typename X>
MYDS::Vector<X>::Vector(const Vector<X> &other) : m_size(other.m_size), m_capacity(other.m_capacity)
{
    if (m_elements != other.m_elements)
    {
        m_elements = new X[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            m_elements[i] = other.m_elements[i];
        }
    }
}
template <typename X>
MYDS::Vector<X>::~Vector()
{
    delete[] m_elements;
}

// Operators

template <typename X>
MYDS::Vector<X> &MYDS::Vector<X>::operator=(const Vector<X> &rhs)
{
    if (m_elements == rhs.m_elements)
    {
        return *this;
    }
    delete[] m_elements;
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_elements = new X[m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_elements[i] = rhs.m_elements[i];
    }
}

template <typename X>
X &MYDS::Vector<X>::operator[](size_t position)
{
    if (position > m_size)
    {
        throw std::out_of_range("Index out of Range");
    }
    return m_elements[position];
}

template <typename X>
bool MYDS::Vector<X>::operator==(const Vector<X> &rhs)
{
    if (m_size != rhs.m_size)
    {
        return false;
    }
    for (int i = 0; i < m_size; ++i)
    {
        if (m_elements[i] != rhs.m_elements[i])
        {
            return false;
        }
    }
    return true;
}
template <typename X>
MYDS::Vector<X> MYDS::Vector<X>::operator+(const Vector<X> &rhs)
{
    Vector<X> result(m_size + rhs.m_size);
    for (int i = 0; i < result.m_size; ++i)
    {
        result[i] = i < m_size ? m_elements[i] : rhs.m_elements[i - m_size];
    }
    return result;
}

// Public Methods

template <typename X>
void MYDS::Vector<X>::pushback(const X &element)
{
    if (m_capacity > m_size)
    {
        m_elements[m_size++] = element;
    }
    else
    {
        m_capacity *= 2;
        X *tmp = new X[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_elements[i];
        }
        delete[] m_elements;
        m_elements = tmp;
        tmp = nullptr;
        m_elements[m_size++] = element;
    }
}

template <typename X>
void MYDS::Vector<X>::pop_back()
{
    X *tmp = new X[m_capacity];
    for (int i = 0; i < m_size - 1; ++i)
    {
        tmp[i] = m_elements[i];
    }
    delete[] m_elements;
    m_elements = tmp;
    tmp = nullptr;
}

template <typename X>
size_t MYDS::Vector<X>::size() { return m_size; }

template <typename X>
bool MYDS::Vector<X>::erase(const X &element)
{
    bool success = 0;
    int index = 0;
    for (int i = 0; i < m_size; ++i)
    {
        if (m_elements[i] == element)
        {
            success = true;
            index = i;
            break;
        }
    }
    if (success)
    {
        X *tmp = new X[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            if (i < index)
            {
                tmp[i] = m_elements[i];
            }
            if (i > index)
            {
                tmp[i - 1] = m_elements[i];
            }
        }
        delete[] m_elements;
        m_elements = tmp;
        tmp = nullptr;
        --m_size;
    }
    return success;
}

template <typename X>
bool MYDS::Vector<X>::insert(size_t position, const X &element)
{
    bool success = 0;
    if (position > size)
    {
        throw std::out_of_range("Index out of Range");
    }
    if (m_size == m_capacity)
    {
        m_capacity *= 2;
    }

    X *tmp = new X[m_capacity];
    for (int i = 0; i <= m_size; ++i)
    {
        if (i < position)
        {
            tmp[i] = m_elements[i];
        }
        if (i == position)
        {
            tmp[i] = element;
        }
        if (i > position)
        {
            tmp[i] = m_elements[i - 1];
        }
    }
    ++m_size;
    delete[] m_elements;
    m_elements = tmp;
    tmp = nullptr;
    return !success;
}

template <typename X>
size_t MYDS::Vector<X>::find(const X &element)
{
    for (size_t index = 0; index < m_size; ++index)
    {
        if (m_elements[index] == element)
        {
            return index;
        }
    }
    return m_size;
}

int main()
{
    MYDS::Vector<int> vec = {1, 2, 4, 5};
    std::cout << vec[0] << std::endl;
    vec.pushback(3);
    try
    {
        std::cout << vec[vec.size() + 5];
    }
    catch (std::exception e)
    {
        if (typeid(e) == typeid(std::logic_error))
        {
            std::cout << "5454" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    MYDS::Vector vec2 = {1, 2, 5};
    vec2 = vec + vec2;
    std::cout << vec2.size() << std::endl;
}

// Sorting Methods
/*
template <typename X>
void MYDS::Vector<X>::BubbleSort()
{
    bool swapped = 1;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < m_size - 1; ++i)
        {
            if (m_elements[i] > m_elements[i + 1])
            {
                std::swap(m_elements[i], m_elements[i + 1]);
                swapped = true;
            }
        }
    }
}
*/
template <typename X>
void MYDS::Vector<X>::InsertionSort()
{
    for (int i = 1; i < m_size; ++i)
    {
        int j = i;
        while (m_elements[j] > m_elements[j - 1] && j - 1 >= 0)
        {
            std::swap(m_elements[j], m_elements[j - 1]);
            --j;
        }
    }
}

template <typename X>
void MYDS::Vector<X>::MergeSort()
{
}