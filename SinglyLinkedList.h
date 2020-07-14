#pragma once

template <typename T>
class Node {
public:
    Node() {
        this->next = nullptr;
        return;
    }
    Node(T _item) {
        this->item = _item;
        this->next = nullptr;
        return;
    }

    T item;
    Node<T>* next;

};

template <typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    int Add(T _item);

    int Delete(T _item);

    int GetItem(T& _item);

    int PrintAllItem();

private:

    Node<T>* Data;
    int length;
    int currentPointer;
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    this->Data = nullptr;
    this->Data->next = nullptr;
    this->length = 0;
    this->currentPointer = 0;
    return;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Data = nullptr;
    Data->next = nullptr;
    delete[] Data;
}

template <typename T>
int SinglyLinkedList<T>::Add(T _item) {
    bool isFound = false;
    if(this->length == 0) {
        this->Data->item = _item;
        this->length++;
        return 1;
    }
    if (GetNode(this->Data, _item, isFound)) {
        return 0;
    }
    else {
    return InsertNode(this->Data, _item);
    }

}

template <typename T>
int SinglyLinkedList<T>::Delete(T _item) {
    return 1;
}

template <typename T>
int SinglyLinkedList<T>::GetItem(T& _item) {
    bool isFound = false;
    GetNode(this->Data, _item, isFound);
    return isFound;
}

template <typename T>
int SinglyLinkedList<T>::PrintAllItem() {
    return PrintNode(this->Data, this->length, this->currentPointer);
}

                                            // ** Global Function ** //

template <typename T>
int InsertNode(Node<T>* _data, T _item) {
    if(_data->next == nullptr) {
        Node<T>* temp;
        temp->next = nullptr;
        temp->item = _item;
        _data->next = temp;
        return 1;
    }
    else {
        InsertNode(_data, _item);
        return 1;
    }
}

template <typename T>
int GetNode(Node<T>* _data, T& _item, bool _found) {
    if(!_found && _data->next == nullptr) {
        return 0;
    }
    else {
        if(_data->item == _item) {
            _item = _data->item;
            _found = true;
            return 1;
        }
        else {
            GetNode(_data->next, _item, _found);
        }
    }
}

template <typename T>
int PrintNode(Node<T>* _data, int _length, int _curptr) {
    if(_length + 1 == _curptr) {
        return 1;
    }
    else {
        std::cout << _data->item;
        int curptr = _curptr + 1;
        PrintNode(_data, _length, curptr);
    }
    return 1;
}