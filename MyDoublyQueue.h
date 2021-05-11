#pragma once

#include "BaseLinkedList.h"
#include "DoublyLinkedList.h"

template <typename T>
class MyDoublyQueue : public BaseLinkedList<T>
{
private:
    DoublyLinkedList<T> queue;
public:
    MyDoublyQueue()   {}
    ~MyDoublyQueue()  {}

    T Add(T _x) override;

    T Remove() override;

    void Print() override;

    const int GetSize() const noexcept override;

};

template <typename T>
T MyDoublyQueue<T>::Add(T _x)
{
    return queue.Add(queue.GetSize(),_x);
} 

template <typename T>
T MyDoublyQueue<T>::Remove()
{
    return queue.Remove(0);
}

template <typename T>
void MyDoublyQueue<T>::Print()
{
    queue.Print();
}

template <typename T>
const int MyDoublyQueue<T>::GetSize() const noexcept
{
    return queue.GetSize();
}