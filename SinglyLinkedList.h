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
        Node<T>* temp = new Node<T>;
        temp->item = _item;
        temp->next = nullptr;
        this->Data = temp;
        this->length++;
        return 1;
    }
    if (GetNode(this->Data, _item, isFound)) {
        return 0;
    }
    else {
        Node<T>* temp = new Node<T>;
        temp->item = _item;
        temp->next = this->Data;
        this->Data = temp;
        this->length++;
        return 1;
    }
}

template <typename T>
int SinglyLinkedList<T>::Delete(T _item) {
	bool isDeleted = false;
	if(this->Data->item == _item) {
        Node<T>* newData = new Node<T>;
        newData = this->Data->next;
		this->Data = nullptr;
		delete[] this->Data;

		this->Data = new Node<T>;
		this->Data = newData;
        this->length--;
        isDeleted = true;        
    }
    else {
		if (DeleteNode(this->Data->next, this->Data, _item, isDeleted)) {
			this->length--;
		}
    }
	return isDeleted;
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
		Node<T>* temp = new Node<T>;
		temp = this->Data;
		while (temp->next != nullptr) {
			std::cout << temp->item;
			temp = temp->next;
		}
		std::cout << temp->item;
		return 1;
	}
}

                                         
template <typename T>
int DeleteNode(Node<T>* _cur, Node<T>* _pre, T _item, bool& _isDeleted) {
	if (_cur->next == nullptr && !_isDeleted) {
		if (_cur->item == _item) {
			_cur = nullptr;
			_pre->next = nullptr;
			delete[] _cur;
			_isDeleted = true;
			return _isDeleted;
		}
		else {
			return _isDeleted;
		}
	}
	else {
		if (_cur->item == _item) {
			Node<T>* temp = new Node<T>;
			temp = _cur->next;
			_pre->next = temp;
			_cur = nullptr;
			delete[] _cur;
			_isDeleted = true;
			return _isDeleted;
		}
		else {
			DeleteNode(_cur->next, _pre->next, _item, _isDeleted);
			return _isDeleted;
		}
	}
}

template <typename T>
int GetNode(Node<T>* _data, T& _item, bool& _found) {
    if(!_found && _data->next == nullptr) {
		if (_data->item == _item) {
			_item = _data->item;
			_found = true;
			return _found;
		}
        return _found;
    }
    else {
        if(_data->item == _item) {
            _item = _data->item;
            _found = true;
            return _found;
        }
        else {
            GetNode(_data->next, _item, _found);
            return _found;
        }
    }
}

