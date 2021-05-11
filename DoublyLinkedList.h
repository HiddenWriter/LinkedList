#pragma once
#include "BaseLinkedList.h"

template <typename T>
class DNode 
{
public:
    DNode() 
    {
        next = prev = nullptr;
    }
    DNode(T _x)
    {
        data = _x;
        next = prev = nullptr;
    }
    ~DNode() {}

    T data;
    DNode<T>* next, *prev;
};

template <typename T>
class DoublyLinkedList
{
private:
    DNode<T> dummy;
    int n;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    T Get(int _i);

    T Set(int _i, T _x);

    T Add(int _i, T _x);

    T Remove(int _i);

    const int GetSize() const noexcept;

    void Print();
private:

    DNode<T>* GetNode(int _i);

    DNode<T>* AddBefore(DNode<T>* _w, T _x);

    void Remove(DNode<T>* _w);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : n(0)
{
    dummy.next = &dummy;
    dummy.prev = &dummy;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{}
template <typename T>
DNode<T>* DoublyLinkedList<T>::GetNode(int _i)
{
    DNode<T>* p;
    if (_i < n / 2)
    {
        p = dummy.next;
        for(int j = 0; j < _i; j++)
        {
            p = p->next;
        }
    }
    else 
    {
        p = &dummy;
        for (int j = n; j > _i; j--)
        {
            p = p->prev;
        }
    }
    return (p);
}

template <typename T>
T DoublyLinkedList<T>::Get(int _i)
{
    return GetNode(_i)->data;
}

template <typename T>
T DoublyLinkedList<T>::Set(int _i, T _x)
{
    DNode<T>* p = GetNode(_i);
    T y = p->data;
    p->data = _x;
    return y;
}

template <typename T>
DNode<T>* DoublyLinkedList<T>::AddBefore(DNode<T>* _w, T _x)
{
    DNode<T>* u = new DNode<T>[1];
    u->data = _x;
    
    u->prev = _w->prev;
    u->next = _w;
    u->next->prev = u;
    u->prev->next = u;
    n++;

    return u;
}

template <typename T>
T DoublyLinkedList<T>::Add(int _i, T _x)
{
    return AddBefore(GetNode(_i), _x)->data;
}

template <typename T>
void DoublyLinkedList<T>::Remove(DNode<T>* _w)
{
    _w->prev->next = _w->next;
    _w->next->prev = _w->prev;
    delete[] _w;
    n--;
    return;
}

template <typename T>
T DoublyLinkedList<T>::Remove(int _i)
{
    DNode<T>* w = GetNode(_i);
    T y = w->data;
    Remove(w);
    return y;
}

template <typename T>
const int DoublyLinkedList<T>::GetSize() const noexcept
{
    return n;
}

template <typename T>
void DoublyLinkedList<T>::Print()
{
    for(int i = 0; i < n; i++)
    {
        std::cout << Get(i);
    }
    return;
}