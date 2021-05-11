#pragma once

#include "BaseLinkedList.h"
#include "DoublyLinkedList.h"

template <typename T>
class MyDoublyStack : public BaseLinkedList<T>
{
private:
    DoublyLinkedList<T> stack;
public:
    MyDoublyStack()     {}
    ~MyDoublyStack()    {}

    T Push(T _x) override;

    T Pop() override;

    void Print() override;

    const int GetSize() const noexcept override;

};

template <typename T>
T MyDoublyStack<T>::Push(T _x)
{
    return stack.Add(stack.GetSize(), _x);
}

template <typename T>
T MyDoublyStack<T>::Pop()
{
    return stack.Remove(stack.GetSize() - 1);
}

template <typename T>
void MyDoublyStack<T>::Print()
{
    stack.Print();
    return;
}

template <typename T>
const int MyDoublyStack<T>::GetSize() const noexcept
{
    return stack.GetSize();
}