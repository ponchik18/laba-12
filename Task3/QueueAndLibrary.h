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
	void Add( T& copyInfo);//add element at the end of Queue
	void Delete();//delete First elemrent of Queue
	Queue();//default constructor
	Queue(const Queue& Copy);//copy constructor
	~Queue();//destructor
	void ReadFromFile(char* str);
	void PrintInFile(char* str);
	void PrintQueue();
};
template<class T>
inline void Queue<T>::PrintInFile(char* str)
{
	FILE* out = fopen(str, "wb");

	if (out == NULL) {
		cout << "ФАЙЛ НЕ МОЖЕТ БЫТЬ ОТКРЫТ!!!" << endl;
		exit(0);
	}
	int CountStudent = Size;
	fwrite(&CountStudent, sizeof(int), 1, out);
	STUDENT undergraduate;
	Node<T>* current = queueFront;
	while(current!=nullptr) {
		undergraduate = current->info;
		undergraduate.PrintInFile(out);
		current = current->next;
	}
	cout << "Запись успешно завершена!" << endl;
	fclose(out);
}
template<class T>
inline void Queue<T>::PrintQueue()
{
	Node<T>* current = queueFront;
	while (current != nullptr) {
		current->info.Info();
		current = current->next;
	}
}
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
inline void Queue<T>::Add( T& copyInfo)
{
	Node<T>* NewNode;
	if (queueFront == nullptr) {
		NewNode = new Node<T>(copyInfo);
		queueFront = NewNode;
		queueRear = NewNode;
		Size++;
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
		Size--;
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
inline void Queue<T>::ReadFromFile(char* str)
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
		Add(undergraduate);
	}
	cout << "Чтение успешно завершено!" << endl;
	fclose(in);
}

template<class T>
inline Queue<T>& Queue<T>::operator=(const Queue& copy)
{
	copyQueue(copy);
	return *this;
}


extern void PrintInfoAboutStudent(Queue<STUDENT>& quequStudent);
extern void CinInfoAboutStudent(Queue<STUDENT>& quequStudent);
extern void menu();
extern void ConsoleCursorVisible(bool show, short size);
extern void pointer(Queue<STUDENT>& quequStudent);
extern void WriteInfoInFile(Queue<STUDENT>& quequStudent);
extern void ReadInfoFromFile(Queue<STUDENT>& quequStudent);
