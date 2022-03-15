#pragma once
#include<iostream>
#include<string>
#include<exception>
template<class T>
class Queue {
private:
	template<class T>
	class Node {
	public:
		T info;
		Node* next;
		Node(T i = T(), Node* n = nullptr) : info(i), next(n) {}
	};
	Node<T>* queueFront;//pointer for  the first element
	Node<T>* queueRear;//pointer for the last element 
	int Size;//size of Queue
	void copyQueue(const Queue& copy);//private method to copy Queue

public:
	Queue& operator=(const Queue& copy);//overloading =
	bool isEmpty() const;//Determine when queue is empty
	void initialize();// initialize queue to empty state
	int GetSize()const { return Size; }
	T front() const;// return The First element without removing
	T back() const;// return The Last element without removing
	void Add(const T& copyInfo);//add element at the end of Queue
	void Delete();//delete First elemrent of Queue
	Queue();//default constructor
	Queue(const Queue& Copy);//copy constructor
	~Queue();//destructor
};

template<class T>
inline void Queue<T>::copyQueue(const Queue& copy)
{
	if (copy.isEmpty()) {
		initialize();
		return;
	}
	if (!isEmpty()) {
		initialize();
	}

	Node<T>* current = copy.queueFront;
	while (current->next != nullptr) {
		Add(current->info);
		current = current->next;
	}
	Add(current->info);

}

template<class T>
inline bool Queue<T>::isEmpty() const
{
	if (queueFront == nullptr)
		return true;
	return false;
}

template<class T>
inline void Queue<T>::initialize()
{
	while (queueFront != nullptr) {
		Node<T>* current = queueFront;
		queueFront = queueFront->next;
		delete current;
		Size--;
	}
	queueRear = nullptr;
}

template<class T>
inline T Queue<T>::front() const
{
	return queueFront->info;
}

template<class T>
inline T Queue<T>::back() const
{

	return this->queueRear->info;
}

template<class T>
inline void Queue<T>::Add(const T& copyInfo)
{
	Node<T>* NewNode;
	if (queueFront == nullptr) {
		NewNode = new Node<T>(copyInfo);
		queueFront = NewNode;
		queueRear = NewNode;
	}
	else {
		NewNode = new Node<T>(copyInfo);
		queueRear->next = NewNode;
		Size++;
		queueRear = NewNode;
	}
}

template<class T>
inline void Queue<T>::Delete()
{
	if (!isEmpty()) {
		Node<T>* deleteNode = nullptr;
		deleteNode = queueFront;
		queueFront = queueFront->next;
		delete deleteNode;
		if (queueFront == nullptr) {
			queueRear = nullptr;
		}
	}
	else {
		std::cout << "Object have already deleted!" << std::endl;
	}

}

template<class T>
inline Queue<T>::Queue()
{
	Size = 0;
	queueFront = nullptr;
	queueRear = nullptr;
}

template<class T>
inline Queue<T>::Queue(const Queue& Copy)
{
	copyQueue(Copy);
}

template<class T>
inline Queue<T>::~Queue()
{
	if (!isEmpty()) {
		initialize();
	}
}

template<class T>
inline Queue<T>& Queue<T>::operator=(const Queue& copy)
{
	copyQueue(copy);
	return *this;
}
