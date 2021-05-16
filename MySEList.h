#pragma once

#include "BaseLinkedList.h"
#include "SpaceEfficientList.h"

template <typename T>
class MySEList : public BaseLinkedList<T>
{
private:
    SpaceEfficientList<T> stack;
public:
    MySEList()
{}
    MySEList(int _i)
{}
    ~MySEList()  {};

    T Push(T _x) override;

    T Pop() override;

    void Print() override;

    const int GetSize() const noexcept override;

};

template <typename T>
T MySEList<T>::Push(T _x)
{
    return stack.Add(stack.GetSize(), _x);
}

template <typename T>
T MySEList<T>::Pop()
{
    return stack.Remove(stack.GetSize() - 1);
}

template <typename T>
void MySEList<T>::Print()
{
    stack.Print();
}

template <typename T>
const int MySEList<T>::GetSize() const noexcept
{
    return stack.GetSize();
}