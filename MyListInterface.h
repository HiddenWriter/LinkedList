#pragma once

#include "BaseLinkedList.h"
#include "DoublyLinkedList.h"

template <typename T>
class MyListInterface : public BaseLinkedList<T>
{
private:
    DoublyLinkedList<T> List;
public:
    
    MyListInterface()   {}
    ~MyListInterface()  {}

    T Add(int _i, T _x);

    T Remove(int _i);

    T Get(int _i);

    T Set(int _i, T _x);

    void Print() override;

    const int GetSize() const noexcept override;

};

template <typename T>
T MyListInterface<T>::Add(int _i, T _x)
{
    return List.Add(_i, _x);
}


template <typename T>
T MyListInterface<T>::Remove(int _i)
{
    return List.Remove(_i);
}


template <typename T>
T MyListInterface<T>::Get(int _i)
{
    return List.Get(_i);
}

template <typename T>
T MyListInterface<T>::Set(int _i, T _x)
{
    return List.Set(_i, _x);
}

template <typename T>
void MyListInterface<T>::Print()
{
    List.Print();
    return;
}

template <typename T>
const int MyListInterface<T>::GetSize() const noexcept
{
    return List.GetSize();
}