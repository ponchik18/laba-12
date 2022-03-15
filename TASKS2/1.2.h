#pragma once
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<locale>
#include<windows.h>
#include<string>
#include<conio.h>
#include <fstream>
#include<exception>
template<typename T>
class List;
#define UP 72
#define DOWN 80
#define ENTRY 13
#define ESC 27
#define CLEAN system("cls"); // отчистка консоли
#define ClEANCONSOLE cin.clear(); cin.ignore(32767, '\n');
#define PAUSE system("pause");
using namespace std;

template<typename T>
T getValue(T& b)
{
	while (true) // цикл продолжаетс€ до тех пор, пока пользователь не введет корректное значение
	{
		cin >> b;

		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удал€ем значени€ предыдущего ввода из входного буфера
			cout << endl << "ќшибка, попробуйте ещЄ раз: ";
		}
		else // если всЄ хорошо, то возвращаем a
			return b;
	}
}
class STUDENT {
public:
	char* FirstName; // »ћя
	char* LastName; // ‘јћ»Ћ»я
	char* Surname; // ќ“„≈—“¬ќ
	int GroupeNumber; // Ќќћ≈– √–”ѕѕџ
	int Marks[5]; // ”—ѕ≈¬ј≈ћќ—“№

	STUDENT(const char* fn = "None", const char* ln = "None", const char* sn = "None", int g = 0, int* m = 0) {
		FirstName = new char[strlen(fn) + 1];
		strcpy(FirstName, fn);
		LastName = new char[strlen(ln) + 1];
		strcpy(LastName, ln);
		Surname = new char[strlen(sn) + 1];
		strcpy(Surname, sn);
		GroupeNumber = g;
		if (m != 0) {
			for (register short unsigned i = 0; i < 5; i++) {
				Marks[i] = m[i];
			}
		}
		else
			for (register short unsigned i = 0; i < 5; i++) {
				Marks[i] = 0;
			}
	}

	~STUDENT() {
		delete[] LastName;
		delete[] FirstName;
		delete[] Surname;
	}

	STUDENT(STUDENT& st) {
		FirstName = new char[strlen(st.FirstName) + 1];
		strcpy(FirstName, st.FirstName);
		LastName = new char[strlen(st.LastName) + 1];
		strcpy(LastName, st.LastName);
		Surname = new char[strlen(st.Surname) + 1];
		strcpy(Surname, st.Surname);
		GroupeNumber = st.GroupeNumber;
		for (register short unsigned i = 0; i < 5; i++) {
			Marks[i] = st.Marks[i];
		}
	}
	STUDENT operator= (const STUDENT& st) {
		FirstName = new char[strlen(st.FirstName) + 1];
		strcpy(FirstName, st.FirstName);
		LastName = new char[strlen(st.LastName) + 1];
		strcpy(LastName, st.LastName);
		Surname = new char[strlen(st.LastName) + 1];
		strcpy(Surname, st.Surname);
		GroupeNumber = st.GroupeNumber;
		for (register short unsigned i = 0; i < 5; i++) {
			Marks[i] = st.Marks[i];
		}
		return *this;
	}
	void PrintInFile(FILE* out) {
		int c;
		///1
		c = (size_t)strlen(FirstName) + 1;
		fwrite(&c, sizeof(int), 1, out);
		fwrite(FirstName, sizeof(char), c, out);
		/////2
		c = (size_t)strlen(LastName) + 1;
		fwrite(&c, sizeof(int), 1, out);
		fwrite(LastName, sizeof(char), c, out);
		/////3
		c = (size_t)strlen(Surname) + 1;
		fwrite(&c, sizeof(int), 1, out);
		fwrite(Surname, sizeof(char), c, out);
		//////4
		fwrite(&GroupeNumber, sizeof(int), 1, out);
		//////5
		for (int i = 0; i < size(Marks); i++) {
			fwrite(&Marks[i], sizeof(int), 1, out);
		}
	}
	void ReadFromFile(FILE* in) {
		int c;
		//////1
		fread(&c, sizeof(int), 1, in);
		FirstName = new char[c];
		fread(FirstName, sizeof(char), c, in);
		//////2
		fread(&c, sizeof(int), 1, in);
		LastName = new char[c];
		fread(LastName, sizeof(char), c, in);
		//////3
		fread(&c, sizeof(int), 1, in);
		Surname = new char[c];
		fread(Surname, sizeof(char), c, in);
		///////4
		fread(&GroupeNumber, sizeof(int), 1, in);
		///////5
		for (int i = 0; i < size(Marks); i++) {
			fread(&Marks[i], sizeof(int), 1, in);
		}

	}
	void Info() {
		cout.width(20);
		cout << LastName << " " << FirstName[0] << ". " << Surname[0] << ".";
		cout.width(20);
		cout << GroupeNumber;
		cout.width(20);
		cout << Marks[0] << ", " << Marks[1] << ", " << Marks[2] << ", " << Marks[3] << ", " << Marks[4] << ". " << endl;
	}
}; // —труктура студент
extern HANDLE hStdOut;
//bool Alpahabet(STUDENT d1,STUDENT d2) {
//	if (strcmp(d1.LastName, d2.LastName) != 1)
//		return true;
//	return false;
//}
///////////////////////////////Prototype

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
	bool RemomeAt(int index); // remove element from index position
	List& operator=(const List& ps);
	void InsertAlpabet(STUDENT d);

	void PrintList();
	bool SearchBySurname(char* str);
	bool SearchByLastName(char* str);
	bool SearchByFirstName(char* str);
	bool SearchByGroup(int& n);
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
	bool StudentType(T d);
};

/////////////////////////////////////////////////Implemention
template<typename T>
inline bool List<T>::SearchByFirstName(char* str)
{
	bool flag = false;
	Node<T>* current = this->Head;
	while (current != nullptr) {
		if (strcmp(current->data.FirstName, str) == 0) {
			current->data.Info();
			flag = true;
		}
		current = current->ptrNext;
	}
	return flag;
}
template<typename T>
inline bool List<T>::SearchByGroup(int& n)
{
	bool flag = false;
	Node<T>* current = this->Head;
	while (current != nullptr) {
		if (current->data.GroupeNumber == n) {
			current->data.Info();
			flag = true;
		}
		current = current->ptrNext;
	}
	return flag;
}
template<typename T>
inline bool List<T>::SearchByLastName(char* str)
{
	bool flag = false;
	Node<T>* current = this->Head;
	while (current != nullptr) {
		if (strcmp(current->data.LastName, str) == 0) {
			current->data.Info();
			flag = true;
		}
		current = current->ptrNext;
	}
	return flag;
	return false;
}
template<typename T>
inline void List<T>::InsertAlpabet(STUDENT d)
{
	if (!StudentType(d)) {
		return;
	}
	Node<T>* current = Head;
	if (Head == nullptr) {
		PushFront(d);
	}
	else if (strcmp(Head->data.LastName, d.LastName) > 0) {
		PushFront(d);
	}
	else {
		while (current->ptrNext != nullptr) {
			if (strcmp(current->ptrNext->data.LastName, d.LastName) <= 0) {
				current = current->ptrNext;
			}
			else break;
		}
		if (current->ptrNext == nullptr) {
			PushBack(d);
		}
		else {
			Node<T>* NewNode = new Node<T>(d, current->ptrNext);
			current->ptrNext = NewNode;
			this->Size++;
		}
	}
}

template<typename T>
inline void List<T>::PrintList()
{

	Node<T>* current = this->Head;
	while (current != nullptr) {
		current->data.Info();
		current = current->ptrNext;
	}


}

template<typename T>
inline bool List<T>::SearchBySurname(char* str)
{
	bool flag = false;
	Node<T>* current = this->Head;
	while (current != nullptr) {
		if (strcmp(current->data.Surname, str) == 0) {
			current->data.Info();
			flag = true;
		}
		current = current->ptrNext;
	}
	return flag;
}

template<typename T>
inline bool List<T>::StudentType(T d)
{
	if (typeid(T) != typeid(STUDENT))
		return false;
	return true;
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
		Node<T>* current = this->Head;
		for (int i = 0; i < index; i++) {
			current = current->ptrNext;
		}
		return current->data;
	}
	catch (const std::out_of_range& bs)
	{
		std::cout << bs.what() << std::endl;

	}

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
		this->Size++;
	}
}
template<typename T>
inline bool List<T>::RemomeAt(int index)
{
	try {
		if (index < 0 || index > this->Size)
			throw std::out_of_range("invalid index");
	}
	catch (std::out_of_range& error) {
		std::cout << error.what() << std::endl;
		return false;
	}
	if (index == 0) {
		List<T>::PopFront();
		return true;
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

extern void DeleteInfoAboutStedent(List<STUDENT>& listStudent);
extern void PrintInfoAboutStudent(List<STUDENT>& listStudent);
extern void CinInfoAboutStudent(List<STUDENT>& listStudent);
extern void menu();
extern void ConsoleCursorVisible(bool show, short size);
extern void pointer(List<STUDENT>& listStudent);
extern void WriteInfoInFile(List<STUDENT>& listStudent);
extern void ReadInfoFromFile(List<STUDENT>& listStudent);
extern void DeleteInfoAboutOneStudent(List<STUDENT>& listStudent);
extern void SarchElementByFiled(List<STUDENT>& listStudent);
