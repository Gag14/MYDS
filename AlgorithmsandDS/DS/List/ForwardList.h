#ifndef __ForwardList__
#define __ForwardList__

#include <iostream>
#include <initializer_list>
namespace
{
    template <class X>
    class ForwardList
    {
    public:
        // Ctor Dtors

        ForwardList();
        ForwardList(const std::initializer_list<X> &list);
        ForwardList(const ForwardList &other);
        ~ForwardList();

        // Methods
        
        bool insert(int position, const X& position);
        bool erase(conxt X& element);
        bool find(const X& element);
        void pushback(const X& element);
        void pushfront(const X& element);
        size_t size();

        private:
            struct Node 
            {
                X val;
                Node* next;
            };
            Node* head;
            Node* tail;
            size_t size;
    };
}
#endif