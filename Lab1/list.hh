#pragma once
#include <iostream>
#include <algorithm>
using namespace std;


template < typename T>
class List
{
private:

	struct Node 
	{
		T data;
		Node* next_node;
	};

	Node* head;
	Node* last;

public:

	class Iterator 
	{
		Node* node;

	public:
		using difference_type = std::size_t;
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using iterator_category = std::input_iterator_tag;
		Iterator(Node* new_node) : node(new_node) {}
		Iterator& operator = (const Iterator& it) 
		{
			node = it.node;
			return *this;
		}
		Iterator& operator ++ () 
		{
			if(node!=nullptr)
				node = node->next_node;
			return *this;
		}

		Iterator& operator ++ (int) 
		{
			Iterator iterator = *this;
			if (node != nullptr)
				node = node->next_node;
			return iterator;
		}

		bool operator != (const Iterator& it) 
		{
			return node != it.node;
		}

		T& operator *() 
		{
			if (node != nullptr)
				return node->data;
			else
				exit(1);
		}

		const T& operator *()const 
		{
			if (node != nullptr)
				return node->data;
			else
				exit(1);
		}
	};

	List() { head = nullptr; last = nullptr; }
	~List();
	List(const List& it);
	List& operator =(const List& it);
	void pushBack(const T& newElement);
	void pushFront(const T& newElement);
	void insert(const T& newElement, int index);
	void priority_insert(const T& newElement, int priority);
	void remove(const T& element);
	T popFront();

	Iterator begin() 
	{
		return Iterator(head);
	}
	Iterator end() 
	{
		return Iterator(nullptr);
	}
	const Iterator cbegin() const 
	{
		return Iterator(head);
	}
	const Iterator cend() const 
	{
		return Iterator(nullptr);
	}

	T& operator [](int index);
	const T& operator [](int index)const;
	void show() {std::for_each(this->begin(), this->end(), [](T i) { cout << i << endl;});}  //dla sprawdzenia poprawnosci implementacji
};




template < typename T>
void List<T>::pushBack(const T& newElement)
{
	Node* node;
	node = new Node;
	node->data = newElement;
	node->next_node = nullptr;
	if (head == nullptr)
	{
		head = node;
		last = node;
	}
	else
	{
		last->next_node = node;
		last = node;
	}
}


template < typename T>
void List<T>::pushFront(const T& newElement)
{
	Node* node;
	node = new Node;
	node->data = newElement;
	if (head == nullptr)
	{
		node->next_node = nullptr;
		head = node;
		last = node;
	}
	else
	{
		node->next_node = head;
		head = node;
	}
}


template < typename T>
void List<T>::insert(const T& newElement, int index)
{
	if (index < 0)
		cout << "b³êdny nr indexu";
	else if (index == 0)
		this->pushFront(newElement);
	else
	{
		int i = index;
		Node* wsk = head;
		while (index)
		{
			if (wsk != nullptr)
			{
				wsk = wsk->next_node;
				index--;
			}
			else
			{
				cout << "bledny nr indexu";
				break;
			}

		}
		if (wsk == nullptr)
			this->pushBack(newElement);
		else
		{
			Node* new_node;
			new_node = new Node;
			new_node->data = newElement;
			new_node->next_node = wsk;
			Node* wsk_before = head;
			while (i - 1)
			{
				wsk_before = wsk_before->next_node;
				i--;
			}
			wsk_before->next_node = new_node;
		}
	}
}



template < typename T>
void List<T>::remove(const T& newElement)
{
	Node* wsk = head;
	Node* wsk_before = head;
	int i = 1;
	if (head != nullptr)
	{
		while (head != nullptr && i)
		{
			if (head->data == newElement)
			{
				wsk = wsk->next_node;
				delete(head);
				head = wsk;
			}
			else
			{
				wsk_before = wsk;
				wsk = wsk->next_node;
				i = 0;
			}
		}
		while (wsk != nullptr)
		{
			if (wsk->data == newElement)
			{
				wsk_before->next_node = wsk->next_node;
				delete(wsk);
				wsk = wsk_before->next_node;
			}
			else
			{
				wsk = wsk->next_node;
				wsk_before = wsk_before->next_node;
			}
		}
		if (wsk_before != last)
		{
			wsk = head;
			if (head == nullptr)
				last = head;
			else {
				while (wsk->next_node != nullptr)
					wsk = wsk->next_node;
				last = wsk;
			}
		}
	}
}


template < typename T>
T& List<T>::operator [](int index)
{
	if (index < 0)
		exit(1);

	Node* wsk = head;
	while (wsk != nullptr && index)
	{
		wsk = wsk->next_node;
		index--;
	}
	if (wsk != nullptr)
		return wsk->data;
	else
		exit(1);

}

template < typename T>
const T& List<T>::operator [](int index)const
{
	if (index < 0)
		exit(1);

	Node* wsk = head;
	while (wsk != nullptr && index)
	{
		wsk = wsk->next_node;
		index--;
	}
	if (wsk != nullptr)
		return wsk->data;
	else
		exit(1);

}



template < typename T>
List<T>::~List()
{
	Node* wsk;
	wsk = head;
	while (head != nullptr)
	{
		wsk = wsk->next_node;
		delete(head);
		head = wsk;
	}
}


template < typename T>
List<T>& List<T>::operator=(const List& it)
{
	Node* wsk = it.head;
	Node* remove = this->head;
	while (this->head != nullptr)
	{
		remove = remove->next_node;
		delete(this->head);
		this->head = remove;
	}

	while (wsk != nullptr)
	{
		this->pushBack(wsk->data);
		wsk = wsk->next_node;
	}

	return *this;
}

template < typename T>
List<T>::List(const List& it)
{
	Node* wsk = it.head;
	this->head = nullptr;
	this->last = nullptr;

	while (wsk != nullptr)
	{
		this->pushBack(wsk->data);
		wsk = wsk->next_node;
	}
}

template < typename T>
T List<T>::popFront()
{
	if (head != nullptr)
	{
		Node* wsk = head;
		wsk = wsk->next_node;
		T to_return = head->data;
		delete(head);
		head = wsk;
		return to_return;
	}
	else
		exit(1);
}


template < typename T>
void List<T>::priority_insert(const T& newElement, int priority)
{
	Node* node = new Node;
	node->data = newElement;

	if (head == nullptr)
	{
		node->next_node = nullptr;
		head = node;
		last = node;
	}
	else
	{
		Node* wsk = head;
		Node* wsk_before = head;
		if (head->data.priority >= priority)
		{
			wsk = wsk->next_node;
			while (wsk != nullptr && wsk->data.priority >= priority)
			{
				wsk = wsk->next_node;
				wsk_before = wsk_before->next_node;
			}
			node->next_node = wsk;
			wsk_before->next_node = node;
		}
		else
		{
			this->pushFront(newElement);
		}

		if (wsk == nullptr)
			last = node;

	}
}
