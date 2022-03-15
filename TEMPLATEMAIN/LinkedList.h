#pragma once
#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include<iostream>
#include<string>
#include<exception>

/////////////////////////////////Prototype

template<typename T>
class List //class for linked list
{
public:
	List();
	~List();
	List(const List& ps);//copy construcort
	void PopFront(); //delete Head Node
	void PushBack(T data); //add elements in list
	void Clear(); // delete all elements
	inline int getSize() const { return this->Size; }
	void PushFront(T data); //Push element at the begining of the List
	void PopBack(); //delete elemet at the end of List 
	T& operator[](const int i);
	void Insert(T data, int index); //insert element in the index position in the List
	void RemomeAt(int index); // remove element from index position
	List& operator=(const List& ps);

private:
	template <typename T>
	class Node { //nested class, Node is class for creation field, that store data and pointer for next element
	public:
		Node* ptrNext; //pointer for next node
		T data; //information
		Node(T d = T(), Node* pN = nullptr) : data(d), ptrNext(pN) {}
	};
	Node<T>* Head; // pointer for the first node
	int Size;

};

/////////////////////////////////////////////////Implemention

template<typename T>
List<T>::List()
{
	Size = 0;
	Head = nullptr;
}
template<typename T>
List<T>::~List()
{
	while (this->Head != nullptr) {
		List<T>::PopFront();
	}
	this->Size = 0;
}

template<typename T>
inline List<T>::List(const List& ps)
{

	if (this->Size != 0) {
		List<T>::Clear();
	}
	this->Size = ps.Size;

	Head = new Node<T>(ps.Head->data);

	Node<T>* current = ps.Head->ptrNext;
	Node<T>* NewElement = Head;
	while (current->ptrNext != nullptr) {
		NewElement->ptrNext = new Node<T>(current->data);
		current = current->ptrNext;
		NewElement = NewElement->ptrNext;
	}
	NewElement->ptrNext = new Node<T>(current->data);

}

template<typename T>
inline void List<T>::PopFront()
{
	Node<T>* current = Head;
	Head = current->ptrNext;
	delete current;
	this->Size--;
}

template<typename T>
void List<T>::PushBack(T data)
{
	if (Head == nullptr) {
		Head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->Head;
		while (current->ptrNext != nullptr) { //move while ptrNext!=nulptr
			current = current->ptrNext;
		}
		current->ptrNext = new Node<T>(data);
	}
	this->Size++;
}
template<typename T>
inline void List<T>::Clear()
{
	List<T>::~List();
}
template<typename T>
inline void List<T>::PushFront(T data)
{
	Head = new Node<T>(data, Head);
	this->Size++;
}
template<typename T>
inline void List<T>::PopBack()
{
	List<T>::RemomeAt(this->Size - 1);
}
template<typename T>
inline T& List<T>::operator[](const int index)
{
	try
	{
		if (index > this->Size)
			throw std::out_of_range("Invalid index");
	}
	catch (const std::out_of_range& bs)
	{
		std::cout << bs.what() << std::endl;

		T error = T();
		return error;
	}
	Node<T>* current = this->Head;
	for (int i = 0; i < index; i++) {
		current = current->ptrNext;
	}
	return current->data;
}
template<typename T>
inline void List<T>::Insert(T data, int index)
{
	try {
		if (index < 0 || index >= this->Size + 1)
			throw std::out_of_range("invalid index");
	}
	catch (std::out_of_range& error) {
		std::cout << error.what() << std::endl;
		return;
	}
	if (index == 0) {
		List<T>::PushFront(data);
		return;
	}
	else {
		Node<T>* current = Head;
		for (int i = 0; i < index - 1; i++) {
			current = current->ptrNext;
		}

		Node<T>* InsertElememt = new Node<T>(data, current->ptrNext);
		current->ptrNext = InsertElememt;
	}
	this->Size++;
}
template<typename T>
inline void List<T>::RemomeAt(int index)
{
	try {
		if (index < 0 || index > this->Size)
			throw std::out_of_range("invalid index");
	}
	catch (std::out_of_range& error) {
		std::cout << error.what() << std::endl;
		return;
	}
	if (index == 0) {
		List<T>::PopFront();
		return;
	}
	else {
		Node<T>* current = Head;
		for (int i = 0; i < index - 1; i++) {
			current = current->ptrNext;
		}

		Node<T>* DeleteNode = current->ptrNext;
		current->ptrNext = DeleteNode->ptrNext;
		delete DeleteNode;
		this->Size--;
	}
}
template<typename T>
inline List<T>& List<T>::operator=(const List& ps)
{
	if (this->Size != 0) {
		List<T>::Clear();
	}
	this->Size = ps.Size;

	Head = new Node<T>(ps.Head->data);

	Node<T>* current = ps.Head->ptrNext;
	Node<T>* NewElement = Head;
	while (current->ptrNext != nullptr) {
		NewElement->ptrNext = new Node<T>(current->data);
		current = current->ptrNext;
		NewElement = NewElement->ptrNext;
	}
	NewElement->ptrNext = new Node<T>(current->data);

	return *this;
}
#endif 
