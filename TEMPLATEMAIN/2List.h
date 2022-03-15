#pragma once
#ifndef _2LIST_H_
#define _2LIST_H_
#include<iostream>
template<typename Type>
class doublylist {
private:
	int Size;
	template<typename Type>
	struct Node {
		Type info; //information of list
		Node* next; //pointer for next element
		Node* back; //pointer for back element
		Node(Type d = Type(), Node* next = nullptr, Node* back = nullptr) :info(d), next(next), back(back) {}
	};
	Node<Type>* first;//first element of the list
	Node<Type>* last;//last element of the list
	void copyList(const doublylist& otherList);
public:
	const doublylist& operator =(const doublylist& ps);//overload the assigment operator =
	bool IsEmtyList() const;//check empty list
	void destroy();// delete all nodes
	void popFront();//delete first element
	void Print() const; //Functoio to output all nodes
	void reversePrint() const;//print in reversed order
	int lenght() const { return this->Size; } //Count of nodes in list
	Type front() const;// return the first element in the list
	Type back() const;//return the last element in the list
	bool search(const Type& searchItem) const;//search element from the list
	void insert(const Type& insertItem, int pos = Size);//insert element at the "pos" position
	void deleteNode(int pos = Size);//delete element from "pos" position
	doublylist();//default constructor
	doublylist(const doublylist& otherList);//copy constructor
	~doublylist();//destructor

};
template<typename Type>
inline void doublylist<Type>::deleteNode(int pos)
{
	try
	{
		if (pos >= this->Size || pos < 0)
			throw std::out_of_range("Invalid index");
	}
	catch (const std::out_of_range& bs)
	{
		std::cout << bs.what() << std::endl;
		return;
	}
	Node<Type>* current;//pointer for travel the list
	Node<Type>* beforeCurrent;//pointer before current
	Node<Type>* DeleteNode;//delete Node;
	if (pos == 0) {
		popFront();
	}
	else if (pos == this->Size - 1) {
		DeleteNode = last;
		last = last->back;
		last->next = nullptr;
		this->Size--;
		delete DeleteNode;
	}
	else {

		if (pos > (float)Size / 2) {
			current = last;
			for (int i = Size - 1; i != pos; i--) {
				current = current->back;
			}
		}
		else {
			current = first;
			for (int i = 0; i != pos; i++) {
				current = current->next;
			}
		}
		DeleteNode = current;
		beforeCurrent = current->back;
		current->next->back = current->back;
		beforeCurrent->next = current->next;
		delete DeleteNode;

		this->Size--;
	}

}
template<typename Type>
inline Type doublylist<Type>::front() const
{
	if (first != nullptr)
		return first->info;
}

template<typename Type>
inline void doublylist<Type>::insert(const Type& insertItem, int pos)
{
	try
	{
		if (pos > this->Size || pos < 0)
			throw std::out_of_range("Invalid index");
	}
	catch (const std::out_of_range& bs)
	{
		std::cout << bs.what() << std::endl;
		return;
	}

	Node<Type>* current;//pointer for travel the list
	Node<Type>* beforeCurrent;//pointer before current
	Node<Type>* NewNode = new Node<Type>(insertItem);//insert Node;

	if (first == nullptr) {
		first = NewNode;
		last = NewNode;
		this->Size++;
	}
	else {
		if (pos == 0) {
			first->back = NewNode;
			NewNode->next = first;
			first = NewNode;
			Size++;
		}
		else if (pos == this->Size) {
			last->next = NewNode;
			NewNode->back = last;
			last = NewNode;
			this->Size++;
		}
		else {
			current = last;
			if (pos > (float)Size / 2) {
				for (int i = Size - 1; i != pos; i--) {
					current = current->back;
				}
			}
			else {
				current = first;
				for (int i = 0; i != pos; i++) {
					current = current->next;
				}
			}
			beforeCurrent = current->back;
			beforeCurrent->next = NewNode;
			NewNode->back = beforeCurrent;
			current->back = NewNode;
			NewNode->next = current;
			this->Size++;
		}
	}

}

template<typename Type>
inline Type doublylist<Type>::back() const
{
	if (last != nullptr)
		return last;
}

template<typename Type>
inline bool doublylist<Type>::search(const Type& searchItem) const
{
	bool found = false;
	Node<Type>* current = first;
	while (current != nullptr && !found) {
		if (current->info == searchItem)
			found = true;
		else
			current = current->next;
	}
	if (found)
		found = (current->info == searchItem);

	return found;
}
template<typename Type>
inline doublylist<Type>::doublylist()
{
	this->first = nullptr;
	this->last = nullptr;
	this->Size = 0;
}

template<typename Type>
inline doublylist<Type>::doublylist(const doublylist& otherList)
{

}

template<typename Type>
inline doublylist<Type>::~doublylist()
{
	doublylist::destroy();
}

template<typename Type>
inline bool doublylist<Type>::IsEmtyList() const
{
	return (this->first == nullptr);
}

template<typename Type>
inline void doublylist<Type>::destroy()
{
	while (first != nullptr) {
		popFront();
	}
	this->last = nullptr;
	this->Size = 0;

}

template<typename Type>
inline void doublylist<Type>::popFront()
{
	Node<Type>* tmp = first;
	first = first->next;
	delete tmp;
	this->Size--;
}
template<typename Type>
void doublylist<Type>::Print() const {
	Node<Type>* current;
	current = first;
	while (current != nullptr) {
		std::cout << current->info << " ";
		current = current->next;
	}
}
template<typename Type>
inline void doublylist<Type>::reversePrint() const
{
	Node<Type>* current = last;
	while (current != nullptr) {
		std::cout << current->info << " ";
		current = current->back;
	}
}

#endif  //_2LIST_H_

