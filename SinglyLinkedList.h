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

	int Modify(T _item);


private:

    Node<T>* Data;
    int length;
    int currentPointer;
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	
	this->Data = new Node<T>;
	this->Data = nullptr;
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
    if(this->Data == nullptr) {
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
		bool isAdded = false;
		InsertNode(this->Data, this->Data->next, _item, isAdded);
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

		newData = nullptr;
		delete[] newData;

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
	if (this->Data == nullptr) {
		return 0;
	}
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
int SinglyLinkedList<T>::Modify(T _item) {
	if (this->Data->item == _item) {
		this->Data->item = _item;
		return true;
	}
	else {
		bool isModified = false;
		ModifyNode(this->Data, _item, isModified);
		return isModified;
	}
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


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
			temp = _cur;
			_pre->next = temp->next;
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

template <typename T>
int ModifyNode(Node<T>* _data, T _item, bool& _isModified) {
	if (_data->next == nullptr && !_isModified) {
		if (_data->item == _item) {
			_data->item = _item;
			_isModified = true;
			return _isModified;
		}
		else {
			return _isModified;
		}
	}
	else {
		if (_data->item == _item) {
			_data->item = _item;
			_isModified = true;
			return _isModified;
		}
		else {
			ModifyNode(_data->next, _item, _isModified);
			return _isModified;
		}
	}
}

template <typename T>
int InsertNode(Node<T>* _pre, Node<T>* _cur, T _item, bool& _isAdded) {
	if (_pre->next == nullptr) {
		Node<T>* temp = new Node<T>;
		temp->item = _item;
		temp->next = nullptr;
		_pre->next = temp;
		_isAdded = true;
		return _isAdded;
	}
	
	else if (_cur->item > _item) {
		Node<T>* temp = new Node<T>;
		temp->item = _item;
		_pre->next = temp;
		temp->next = _cur;
		_isAdded = true;
		return _isAdded;
	}
	else {
		InsertNode(_pre->next, _cur->next, _item, _isAdded);
		return _isAdded;
	}
}