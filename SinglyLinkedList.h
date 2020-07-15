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
	
	this->Data = new Node<T>;
	
	this->length = 0;
    return;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Data = nullptr;
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
	bool isFound = false;
	DeleteNode(this->Data, _item, isFound);
	return isFound;
}

template <typename T>
int SinglyLinkedList<T>::GetItem(T& _item) {
    bool isFound = false;
    GetNode(this->Data, _item, isFound);
    return isFound;
}

template <typename T>
int SinglyLinkedList<T>::PrintAllItem() {
	if (this->length == 0) {
		std::cout << "\n\t No Item. \n";
		return 0;
	}
	else {
		return PrintNode(this->Data);
	}
}

                                            // ** Global Function ** //

template <typename T>
int InsertNode(Node<T>* _data, T _item) {
    if(_data->next == nullptr) {
		Node<T>* temp = new Node<T>;
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
int GetNode(Node<T>* _data, T& _item, bool& _found) {
    if(!_found && _data->next == nullptr) {
		if (_data->item == _item) {
			_item = _data->item;
			_found = true;
		}
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
            return 1;
        }
    }
}

template <typename T>
int PrintNode(Node<T>* _data) {
    if(_data->next == nullptr) {
		std::cout << _data->item;
        return 1;
    }
    else {
        std::cout << _data->item;
        PrintNode(_data->next);
        return 1;
    }
}

template <typename T>
int DeleteNode(Node<T>* _data, T _item, bool& _isFound) {
	if (!_isFound && _data->next == nullptr) {
		if (_data->item == _item) {
			Node<T>* temp = new Node<T>;
			temp->item = _item;
			temp->next = nullptr;
			_isFound = true;
			return 1;
		}
		else { return 0; }
	}
	else {
		if (_data->item == _item) {
			Node<T>* temp = new Node<T>;
			temp->item = _item;
			temp->next = _data->next;
			_data = nullptr;
			delete[] _data;
			_isFound = true;
			return 1;
		}
		else {
			DeleteNode(_data->next, _item, _isFound);
			return 1;
		}
	}
}