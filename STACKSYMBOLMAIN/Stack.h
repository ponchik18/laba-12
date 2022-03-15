#pragma once//начать писать ввод строки
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<locale>
#include<windows.h>
#include<string>
#include<conio.h>
#include <fstream>
#include<exception>
#define UP 72
#define DOWN 80
#define ENTRY 13
#define ESC 27
#define CLEAN system("cls"); // отчистка консоли
#define ClEANCONSOLE cin.clear(); cin.ignore(32767, '\n');
#define PAUSE system("pause");
using namespace std;
extern HANDLE hStdOut;
#include<conio.h>
class Stack {
private:

	class Node {
	public:
		char info;//info in element stack
		Node* Next;//poiner for next element in stack
		Node(char data = ' ', Node* n = nullptr) : info(data), Next(n) {}
	};
	Node* Top;//pointer for topElement
	char EtalonSymbol;
	int Size;//size of stack
public:
	Stack(char sym = '\r') : Size(0), Top(nullptr), EtalonSymbol(sym) {} //default constructor
	Stack(const Stack& cpy);//copy constructor
	~Stack();//desrtuctor

	/////////////METHOD/////////

	bool IsEmpy()const;// return true, if it is empty stack
	int GetSize() const { return this->Size; };//
	void Push(const char& PushItem);
	char& Pop();//return and remove topElemet
	char& TopElement();//only return TopeElemet
	Stack& operator=(const Stack& cpy);//overloading operator "="
	void initializeStack();// removed all element if it is possible and make stack empty
	void print() const;
	void setEtalon(char c);
	void CoutString();
private:

	void CopyStack(const Stack& Copy);//copy stack

};

extern void ConsoleCursorVisible(bool show, short size);
extern void menu();
extern void pointer(Stack& symbols);