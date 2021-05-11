
#pragma once
#include <iostream>
template <typename T>
    class Node
    {
    public:
        Node()
        {
            this->next = nullptr;
            return;
        }
        Node(T _item)
        {
            this->item = _item;
            this->next = nullptr;
            return;
        }
        ~Node()
        {}
        T item;
        Node<T>* next;

    };
template <typename T>
class BaseLinkedList
{
public:
    BaseLinkedList() {}
    ~BaseLinkedList() {}
    
    virtual T Add(T _x)
    {
        std::cout << "\tVirtual\n";
        return {};
    }

    virtual T Push(T _x)
    {
        std::cout << "\tVirtual\n";
        return {};
    }

    virtual T Pop()
    {
        std::cout << "\tVirtual\n";
        return {};
    }

    virtual T Remove() 
    {
        std::cout << "\tVirtual\n";
        return {};
    }

    const int virtual GetSize() const noexcept = 0;
    
    virtual void Print() = 0;
};