#pragma once

#include "BaseLinkedList.h"
#include "SinglyLinkedList.h"

template <typename T>
class MyQueue : public BaseLinkedList<T>
{
private:
    SinglyLinkedList<T> queue;
public:
    MyQueue()   {}
    ~MyQueue()  {}

    T Add(T _x) override;

    T Remove() override;

    void Print() override;

    const int GetSize() const noexcept override;

};

template <typename T>
T MyQueue<T>::Add(T _x)
{
    std::cout << "\n\t MyQueue ( Add ) \n";
    return queue.Add(_x);
} 

template <typename T>
T MyQueue<T>::Remove()
{
    std::cout << "\n\t MyQueue ( Remove ) \n";
    return queue.Remove();
}

template <typename T>
void MyQueue<T>::Print()
{
    queue.Print();
}

template <typename T>
const int MyQueue<T>::GetSize() const noexcept
{
    return queue.GetSize();
}