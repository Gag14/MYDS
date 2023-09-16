#ifndef __HashTable__
#define __HashTable__
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <utility>

namespace MYDS
{
    template <class X>
    class HashTable
    {
    public:
        // Ctor Dtor
        HashTable();
        HashTable(const HashTable &other);
        ~HashTable();

        // Operators
        const HashTable &operator=(const HashTable &rhs);
        const X &operator[](int key);
        const X &operator[](const std::string &key);

        // Main Public Methods
        void add(int key, const X &value);
        void add(const std::string &key, const X &value);
        const X &get(int key);
        const X &get(const std::string &key);
        bool remove(int key);
        bool remove(const std::string &key);
        void put(int key, consy X &value);
        void put(const std::string &key, const X &value);

    private:
        // Private methiods

        int hash(int key);
        int hash(std::string key);
        void rehash();
        float getLoadFactor();
        void updateLoadFactor();
        int getSize();

        // Data Members

        int m_size;
        std::vector<>
    };
}

#endif