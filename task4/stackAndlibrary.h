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
class Queue;
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
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		cin >> b;

		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << endl << "Ошибка, попробуйте ещё раз: ";
		}
		else // если всё хорошо, то возвращаем a
			return b;
	}
}
class STUDENT {
public:
	char* FirstName; // ИМЯ
	char* LastName; // ФАМИЛИЯ
	char* Surname; // ОТЧЕСТВО
	int GroupeNumber; // НОМЕР ГРУППЫ
	int Marks[5]; // УСПЕВАЕМОСТЬ

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
		Surname = new char[strlen(st.LastName) + 1];
		strcpy(Surname, st.LastName);
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
}; // Структура студент
extern HANDLE hStdOut;
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
	void Push(Type& PushItem);
	Type& Pop();//return and remove topElemet
	Type& TopElement();//only return TopeElemet
	Stack& operator=(const Stack& cpy);//overloading operator "="
	void initializeStack();// removed all element if it is possible and make stack empty
	void print() const;
	void PrintStack();
	void ReadFromFile(char* str);
	void PrintInFile(char* str);
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
inline void Stack<Type>::Push(Type& PushItem)
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
inline void Stack<Type>::PrintStack()
{
	Node<Type>* current = Top;
	while (current != nullptr) {
		current->info.Info();
		current = current->Next;
	}
}

template<typename Type>
inline void Stack<Type>::ReadFromFile(char* str)
{
	FILE* in = fopen(str, "rb");
	if (in == NULL) {
		cout << "ДАННЫЙ ФАЙЛ НЕ НАЙДЕН!!!" << endl;
		return;
	}
	STUDENT undergraduate;
	int CountStudent = 0;
	fread(&CountStudent, sizeof(int), 1, in);
	for (int i = 0; i < CountStudent; i++) {
		undergraduate.ReadFromFile(in);
		Push(undergraduate);
	}
	cout << "Чтение успешно завершено!" << endl;
	fclose(in);
}

template<typename Type>
inline void Stack<Type>::PrintInFile(char* str)
{
	FILE* out = fopen(str, "wb");

	if (out == NULL) {
		cout << "ФАЙЛ НЕ МОЖЕТ БЫТЬ ОТКРЫТ!!!" << endl;
		exit(0);
	}
	int CountStudent = Size;
	fwrite(&CountStudent, sizeof(int), 1, out);
	STUDENT undergraduate;
	Node<Type>* current = Top;
	while (current != nullptr) {
		undergraduate = current->info;
		undergraduate.PrintInFile(out);
		current = current->Next;
	}
	cout << "Запись успешно завершена!" << endl;
	fclose(out);
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


extern void PrintInfoAboutStudent(Stack<STUDENT>& stackStudent);
extern void CinInfoAboutStudent(Stack<STUDENT>& stackStudent);
extern void menu();
extern void ConsoleCursorVisible(bool show, short size);
extern void pointer(Stack<STUDENT>& stackStudent);
extern void WriteInfoInFile(Stack<STUDENT>& stackStudent);
extern void ReadInfoFromFile(Stack<STUDENT>& stackStudent);