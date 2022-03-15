#pragma once
#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include<exception>


/////////////////////////////////Prototype

template<typename T>
class List //class for linked list
{
private:
	//bool IntExamination();
	template<typename T>
	class Node { //nested class, Node is class for creation field, that store data and pointer for next element
	public:
		Node* ptrNext; //pointer for next node
		T data; //information
		Node(T d = T(), Node* pN = nullptr) : data(d), ptrNext(pN) {}
	};
	Node<T>* Head; // pointer for the first node
	int Size;
	bool FindElement(T& element, Node<T>*& current);
	bool IntExamination();
public:
	List();
	~List();
	List(const List& ps);//copy construcort
	bool PopFront(); //delete Head Node
	void PushBack(T data); //add elements in list
	bool isEmpty() {
		if (Head == nullptr)
			return true;
		return false;
	}
	void Clear(); // delete all elements
	inline int getSize() const { return this->Size; }
	void PushFront(T data); //Push element at the begining of the List
	bool PopBack(); //delete elemet at the end of List 
	T& operator[](const int i);
	void Insert(T data, int index); //insert element in the index position in the List
	bool RemomeAt(int index); // remove element from index position
	void print();
	List& operator=(const List& ps);
	int FindMax();
	int FindMin();
	bool DeleteRepeter(T d);
	bool DeleteElements(T d);

	void InsertAlphabet(STUDENT d);
};

/////////////////////////////////////////////////Implemention



template<typename T>
void List<T>::InsertAlphabet(STUDENT d)
{
	if (Head == nullptr) {
		//PushFront(d);
	}
	
	else {
		Node<T> current = head;
		while (current.ptrNext!=nullptr)
		{
			if(strcmp(d.))
		}
	}
}
template<typename T>
inline int List<T>::FindMax()
{
	if (!IntExamination()) {
		return 0;
	}
	Node<T>* current = Head;
	T max = Head->data;
	while (current->ptrNext != nullptr)
	{
		if (max < current->data)
			max = current->data;
		current = current->ptrNext;
	}
	if (max < current->data)
		max = current->data;
	return max;
}

template<typename T>
inline int List<T>::FindMin()
{
	if (!IntExamination()) {
		return 0;
	}

	Node<T>* current = Head;
	T min = Head->data;
	while (current->ptrNext != nullptr)
	{
		if (min > current->data)
			min = current->data;
		current = current->ptrNext;
	}
	if (min > current->data)
		min = current->data;
	return min;
}
template<typename T>
inline bool List<T>::DeleteRepeter(T d)
{
	if (!IntExamination()) {
		return false;
	}
	Node<T>* current = Head;
	int index = 0;
	if (!FindElement(d, current)) {
		std::cout << std::endl << "' " << d << " ' не найдено данного элемента в листе";
		return false;
	}
	else {
		current = current->ptrNext;

		while (FindElement(d, current)) {
			Node<T>* deleteNode = current->ptrNext;
			current->ptrNext = deleteNode->ptrNext;
			delete deleteNode;
			this->Size--;
		}
		return true;
	}

}

template<typename T>
inline bool List<T>::DeleteElements(T d)
{
	if (!IntExamination()) {
		return false;
	}
	Node<T>* current = Head;
	if (!FindElement(d, current)) {
		std::cout << std::endl << "' " << d << " ' не найдено данного элемента в листе";
		return false;
	}
	current = Head;
	while (FindElement(d, current)) {
		if (current == Head && current->data == d) {
			PopFront();
			current = Head;
		}
		else {
			Node<T>* deleteNode = current->ptrNext;
			current->ptrNext = deleteNode->ptrNext;
			delete deleteNode;
			this->Size--;
		}
	}
	return true;
}

template<typename T>
inline bool List<T>::IntExamination()
{
	if ((typeid(T) != typeid(int)) || isEmpty()) {
		std::cout << "Invalid operation!" << std::endl;
		return false;
	}

	return true;
}

template<typename T>
inline bool List<T>::FindElement(T& element, Node<T>*& current)
{
	/*while (indexElement < this->Size - 1) {
		if (current->data == element) {
			return true;
		}
		indexElement++;
		current = current->ptrNext;
	}
	return false;*/
	if (current == nullptr) {
		return false;
	}
	if (current == this->Head && element == this->Head->data) {
		return true;
	}
	else {
		while (current->ptrNext != nullptr) {
			if (current->ptrNext->data == element) {
				return true;
			}
			current = current->ptrNext;
		}
	}
	return false;
}

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
inline bool List<T>::PopFront()
{
	if (isEmpty()) {
		return false;
	}
	Node<T>* current = Head;
	Head = current->ptrNext;
	delete current;
	this->Size--;
	return true;
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
inline bool List<T>::PopBack()
{
	if (List<T>::RemomeAt(this->Size - 1)) {
		return true;
	}
	return false;
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
inline bool List<T>::RemomeAt(int index)
{
	if (isEmpty()) {
		return false;
	}
	try {
		if (index < 0 || index > this->Size)
			throw std::out_of_range("invalid index");
	}
	catch (std::out_of_range& error) {
		//std::cout << error.what() << std::endl;
		return false;
	}
	if (index == 0) {
		List<T>::PopFront();
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
	return true;
}
template<typename T>
inline void List<T>::print()
{
	Node<T>* current = Head;
	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->ptrNext;

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


/////////////friend functions///////////////



#endif 