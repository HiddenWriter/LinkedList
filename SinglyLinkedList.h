#pragma once

#include "BaseLinkedList.h"

template <typename T>
class SinglyLinkedList
{
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    T Push(T _x);

	T Add(T _x);

    T Remove();

	T Pop();

    void Print();

	const int GetSize() const noexcept;

private:

	Node<T>* head;
	Node<T>* tail;
	int n;

};
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() 
	: n(0)
{
	head = tail = nullptr;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() 
{
	delete[] head;
	delete[] tail;
}

template <typename T>
T SinglyLinkedList<T>::Add(T _x)
{
	Node<T>* u = new Node<T>(_x);
	if (n == 0)
	{
		head = u;
	}
	else
	{
		tail->next = u;
	}
	tail = u;
	n++;
	return _x;
}

template <typename T>
T SinglyLinkedList<T>::Push(T _x) 
{
	Node<T>* u = new Node<T>(_x);
	std::cout << "\n\t - pushed - \n" << u->item << "\n"; 
	u->next = head;
	head = u;
	if (n==0)
	{
		tail = u;
	}
	n++;
	return _x;
}

template <typename T>
T SinglyLinkedList<T>::Pop()
{
	if (n == 0)
	{
		return {};
	}
	else 
	{
		T x = head->item;
		Node<T>* u = head;
		head = head->next;
		delete u;
		if ( --n == 0)
		{
			tail = nullptr;
		}
		return x;
	}
}
template <typename T>
T SinglyLinkedList<T>::Remove() 
{
	if (n == 0) return {};
	else
	{
		T x = head->item;
		Node<T>* u = head;
		head = head->next;
		delete u;
		if (--n == 0)
		{
			tail = nullptr;
		}
		return x;
	}
}

template <typename T>
void SinglyLinkedList<T>::Print() 
{
	Node<T>* cur = head;
	while(cur != nullptr)
	{
		std::cout << cur->item;
		cur = cur->next;
	}
	return;
}

template <typename T>
const int SinglyLinkedList<T>::GetSize() const noexcept
{
	return n;
}

