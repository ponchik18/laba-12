#pragma once
#include<iostream>
template<typename Type>
class Stack {
private:
	template<typename Type>
	class Node {
	public:
		Type info;//info in element stack
		Node* Next;//poiner for next element in stack
		Node(Type data = Type(), Node* n = nullptr) : info(data), Next(n) {}
	};
	Node<Type>* Top;//pointer for topElement
	int Size;//size of stack
public:
	Stack() : Size(0), Top(nullptr) {} //default constructor
	Stack(const Stack& cpy);//copy constructor
	~Stack();//desrtuctor

	/////////////METHOD/////////

	bool IsEmpy()const;// return true, if it is empty stack
	int GetSize() const { return this->Size; };//
	void Push(const Type& PushItem);
	Type& Pop();//return and remove topElemet
	Type& TopElement();//only return TopeElemet
	Stack& operator=(const Stack& cpy);//overloading operator "="
	void initializeStack();// removed all element if it is possible and make stack empty
	void print() const;
private:

	void CopyStack(const Stack& Copy);//copy stack

};

template<typename Type>
inline bool Stack<Type>::IsEmpy() const
{
	if (this->Top == nullptr)
		return true;
	else
		return false;
	return false;
}

template<typename Type>
inline void Stack<Type>::Push(const Type& PushItem)
{
	if (IsEmpy()) {
		Node<Type>* NewElement = new Node<Type>(PushItem, nullptr);
		this->Top = NewElement;
	}
	else {
		Node<Type>* NewElement = new Node<Type>(PushItem, Top);
		Top = NewElement;
	}
	this->Size++;
}

template<typename Type>
inline Type& Stack<Type>::Pop()
{
	Type data = Top->info;
	Node<Type>* current = Top;
	Top = current->Next;
	delete current;
	this->Size--;
	return data;
}

template<typename Type>
inline Type& Stack<Type>::TopElement()
{

	return this->Top->info;
}

template<typename Type>
inline Stack<Type>& Stack<Type>::operator=(const Stack& cpy)
{
	this->CopyStack(cpy);
	return *this;
}

template<typename Type>
inline void Stack<Type>::initializeStack()
{
	while (Top != nullptr)
	{
		Pop();
	}
}

template<typename Type>
inline void Stack<Type>::print() const
{
	if (Top == nullptr) {
		return;
	}
	Node<Type>* current = this->Top;
	while (current->Next != nullptr) {
		std::cout << current->info << " ";
		current = current->Next;

	}
	std::cout << current->info << " ";
}

template<typename Type>
inline void Stack<Type>::CopyStack(const Stack& Copy)
{
	initializeStack();
	if (Copy.Top == nullptr) {
		Top = nullptr;
	}
	else {
		Node<Type>* newNode, * currentCopy, * last;
		Top = new Node<Type>(Copy.Top->info, nullptr);
		currentCopy = Copy.Top;
		last = Top;
		currentCopy = currentCopy->Next;
		while (currentCopy != nullptr) {
			newNode = new Node<Type>(currentCopy->info, nullptr);
			last->Next = newNode;
			currentCopy = currentCopy->Next;
			last = last->Next;
		}

	}
	this->Size = Copy.Size;


}

template<typename Type>
Stack<Type>::Stack(const Stack& cpy) {
	CopyStack(cpy);
}

template<typename Type>
inline Stack<Type>::~Stack()
{
	this->initializeStack();
}
