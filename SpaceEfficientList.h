#pragma once

#include "Array.h"
#include "ArrayDeque.h"

template <typename T>
class SpaceEfficientList
{
private:
    int n;
    int b;
    class BDeque : public ArrayDeque<T>
    {
        using ArrayDeque<T>::mNumOfElem;
        using ArrayDeque<T>::mElem2Remove;
        using ArrayDeque<T>::mArr;
    public:
        BDeque(int _b)
        {
            mNumOfElem = 0;
            mElem2Remove = 0;
            Array<T> z ( _b + 1 );
            mArr = z;
        }
        ~BDeque() {}
        
        void Add(int _i, T _x)
        {
            ArrayDeque<T>::Add(_i, _x);
        }

        bool Add(T _x)
        {
            ArrayDeque<T>::Add(ArrayDeque<T>::GetSize(), _x);
            return true;
        }
        void Resize()
        {
            std::cout << "\n\t SEList Resize \n";
            return;
        }
    };

    class Node
    {
    public:
        SpaceEfficientList<T>::BDeque d;
        Node* prev, *next;
        Node() : d (4) {}
        Node(int _b) : d (_b) {}
        ~Node() {}
    };

    Node dummy;

    class Location
    {
    public:
        Node* u;
        int j;
        Location() {}
        Location(Node* _u, int _j)
        {
            u = _u;
            j = _j;
        }
    };

    Node* AddBefore(Node* _w);
    
    void GetLocation(int _i, Location& _ell);

    void Add(T _x);

    void Spread(Node* _u);

    void Remove(Node* _w);

    void Gather(Node* _u);

public:

    SpaceEfficientList();
    SpaceEfficientList(int _b);
    ~SpaceEfficientList();

    T Get(int _i);

    T Set(int _i, T _x);

    const int GetSize() const noexcept;

    T Add(int _i, T _x);

    T Remove(int _i);

    void Print();

};

template <typename T>
SpaceEfficientList<T>::SpaceEfficientList()
    : b(3), n(0)
{
    dummy.next = dummy.prev = &dummy;
}

template <typename T>
SpaceEfficientList<T>::SpaceEfficientList(int _b)
    : b(_b), n(0)
{
    dummy.next = &dummy;
    dummy.prev = &dummy;
}

template <typename T>
SpaceEfficientList<T>::~SpaceEfficientList() 
{}

template <typename T>
void SpaceEfficientList<T>::GetLocation(int _i, Location& _ell)
{
    if (_i < n / 2)
    {
        Node* u = dummy.next;
        while ( _i >= u->d.GetSize())
        {
            _i -= u->d.GetSize();
            u = u->next;
        }
        _ell.u = u;
        _ell.j = _i;
    }
    else 
    {
        Node* u = &dummy;
        int idx ( n );
        while (_i < idx)
        {
            u = u->prev;
            idx -= u->d.GetSize();
        }
        _ell.u = u;
        _ell.j = _i - idx;
    }

    return;
}

template <typename T>
T SpaceEfficientList<T>::Get(int _i)
{
    Location l;
    GetLocation(_i, l);
    return l.u->d.Get(l.j);
}

template <typename T>
T SpaceEfficientList<T>::Set(int _i, T _x)
{
    Location l;
    GetLocation(_i, l);
    T y = l.u->d.Get(l.j);
    l.u->d.Set(l.j, _x);
    return y;
}

template <typename T>
void SpaceEfficientList<T>::Add(T _x)
{
    Node* last = dummy.prev;
    if (last == &dummy || last->d.GetSize() == b + 1)
    {
        last = AddBefore(&dummy);
    }
    last->d.Add(_x);
    n++;
}

template <typename T>
const int SpaceEfficientList<T>::GetSize() const noexcept
{
    return n;
}

template <typename T>
T SpaceEfficientList<T>::Add(int _i, T _x)
{
    if (_i == n)
    {
        Add(_x);
        return _x;
    }
    Location l; GetLocation(_i, l);
    Node* u = l.u;
    int r ( 0 );

    while (r < b && u != &dummy && u->d.GetSize() == b + 1)
    {
        u = u->next;
        r++;
    }

    if ( r == b)
    {
        Spread(l.u);
        u = l.u;
    }
    if ( u == &dummy)
    {
        u = AddBefore(u);
    }

    while (u != l.u)
    {
        u->d.Add
        (
            0, u->prev->d.Remove(u->prev->d.GetSize() - 1)
        );
        u = u->prev;
    }
    u->d.Add(l.j, _x);
    n++;
    return _x;
}


template <typename T>
void SpaceEfficientList<T>::Spread(Node* _u)
{
    Node* w = _u;
    for (int j = 0; j < b; j++)
    {
        w  = w->next;
    }

    w = AddBefore(w);
    while (w != _u)
    {
        while (w->d.GetSize() < b)
        {
            w->d.Add(0, w->prev->d.Remove(w->prev->d.GetSize() - 1));
        }
        w = w->prev;
    }
}

template <typename T>
void SpaceEfficientList<T>::Print()
{
    Location l; GetLocation(0, l);
    Node* u = l.u;
    int r (0);
    while (u != &dummy)
    {
        u->d.Print();
        u = u->next;
        r++;
    }
}

template <typename T>
T SpaceEfficientList<T>::Remove(int _i)
{
    Location l; GetLocation(_i, l);
    T y = l.u->d.Get(l.j);
    Node* u = l.u;
    int r (0);
    while ( r < b && u != &dummy && u->d.GetSize() == b - 1)
    {
        u = u->next;
        r++;
    }
    if (r == b)
    {
        Gather(l.u);
    }
    u = l.u;
    u->d.Remove(l.j);

    while (u->d.GetSize() < b - 1 && u->next != &dummy)
    {
        u->d.Add(u->next->d.Remove(0));
        u = u->next;
    }

    if (u->d.GetSize() == 0)
    {
        Remove(u);
    }
    n--;
    return y;
}

template <typename T>
void SpaceEfficientList<T>::Gather(Node* _u)
{
    Node* w = _u;
    for (int j = 0; j < b - 1; j++)
    {
        while (w->d.GetSize() < b)
        {
            w->d.Add(w->next->d.Remove(0));
        }
        w = w->next;
    }
    Remove(w);
}

template <typename T>
auto SpaceEfficientList<T>::AddBefore(Node* _w) -> Node*
{
    Node* u = new Node(b);
    u->prev = _w->prev;
    u->next = _w;
    u->next->prev = u;
    u->prev->next = u;
    return u;
}

template <typename T>
void SpaceEfficientList<T>::Remove(Node* _w)
{
    _w->prev->next = _w->next;
    _w->next->prev = _w->prev;
    delete _w;
}