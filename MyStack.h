#pragma once

#include "BaseLinkedList.h"
#include "SinglyLinkedList.h"

template <typename T>
class MyStack : public BaseLinkedList<T>
{
private:
    SinglyLinkedList<T> stack;
public:
    MyStack()   {};
    ~MyStack()  {};

    T Push(T _x) override;

    T Pop() override;

    void Print() override;

    const int GetSize() const noexcept override;

};

template <typename T>
T MyStack<T>::Push(T _x)
{
    return stack.Push(_x);
}

template <typename T>
T MyStack<T>::Pop()
{
    return stack.Pop();
}

template <typename T>
void MyStack<T>::Print()
{
    stack.Print();
}

template <typename T>
const int MyStack<T>::GetSize() const noexcept
{
    return stack.GetSize();
}