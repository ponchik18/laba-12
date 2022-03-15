#include"Stack.h"
extern HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
static int ActiveMenu = 4;

static void GotoY(short y, short x = 25) {
	SetConsoleCursorPosition(hStdOut, { x,y });
}

extern void ConsoleCursorVisible(bool show, short size) {
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.bVisible = show;
	CursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &CursorInfo);
}

static void ConsoleTextColor(int& n) {
	if (n++ == ActiveMenu) {
		SetConsoleTextAttribute(hStdOut, 80);
	}
	else {
		SetConsoleTextAttribute(hStdOut, 15);
	}
}

bool Stack::IsEmpy() const
{
	if (this->Top == nullptr)
		return true;
	else
		return false;
	return false;
}

void Stack::Push(const char& PushItem)
{
	if (IsEmpy()) {
		Node* NewElement = new Node(PushItem, nullptr);
		this->Top = NewElement;
	}
	else {
		Node* NewElement = new Node(PushItem, Top);
		Top = NewElement;
	}
	this->Size++;
}


char& Stack::Pop()
{
	char data = Top->info;
	Node* current = Top;
	Top = current->Next;
	delete current;
	this->Size--;
	return data;
}


char& Stack::TopElement()
{

	return this->Top->info;
}


Stack& Stack::operator=(const Stack& cpy)
{
	this->CopyStack(cpy);
	return *this;
}


void Stack::initializeStack()
{
	while (Top != nullptr)
	{
		Pop();
	}
}


void Stack::print() const
{
	if (Top == nullptr) {
		std::cout << "Стек пуст, невозможен вывод!" << endl;
	}
	Node* current = this->Top;
	while (current != nullptr) {
		std::cout << current->info;
		current = current->Next;

	}

}

void Stack::setEtalon(char c)
{
	if (c == '\n')
		c = '\r';
	this->EtalonSymbol = c;
}

void Stack::CoutString()
{
	char c;
	int len = 1;
	
	/*char* str = new char[0];*/
	while ((c = _getch()) != this->EtalonSymbol)
	{
		cout << c;
		this->Push(c);
	}
}


void Stack::CopyStack(const Stack& Copy)
{
	initializeStack();
	if (Copy.Top == nullptr) {
		Top = nullptr;
	}
	else {
		Node* newNode, * currentCopy, * last;
		Top = new Node(Copy.Top->info, nullptr);
		currentCopy = Copy.Top;
		last = Top;
		currentCopy = currentCopy->Next;
		while (currentCopy != nullptr) {
			newNode = new Node(currentCopy->info, nullptr);
			last->Next = newNode;
			currentCopy = currentCopy->Next;
			last = last->Next;
		}

	}
	this->Size = Copy.Size;


}

Stack::Stack(const Stack& cpy) {
	CopyStack(cpy);
}

Stack::~Stack()
{
	this->initializeStack();
}

extern void pointer(Stack & symbols) {
	char ch;
	ch = _getch();

	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case ESC:
		exit(0);
	case DOWN:
		if (ActiveMenu < 11)
			ActiveMenu++;
		break;
	case UP:
		if (ActiveMenu > 4)
			ActiveMenu--;
		break;
	case ENTRY:
		switch (ActiveMenu) {
		case 4:
			CLEAN
				std::cout << "Можете вводить строку: ";
				symbols.CoutString();
			std::cout << endl;
			std::cout << "Ввод завершён!"<<std::endl;
				PAUSE
				break;
		case 5:
			CLEAN
				symbols.print();
				std::cout << endl;
				std::cout << "Вывод завершён!"<<std::endl;
			PAUSE
				break;
		case 6:
			CLEAN

				std::cout << "Введите эталонный символ: ";
				ch = cin.get();
				symbols.setEtalon(ch);
			PAUSE
				break;
		case 7:
			CLEAN
				symbols.initializeStack();
				std::cout<<"Стек символов отчищен!"<<endl;
			PAUSE
				break;
		case 8:
			CLEAN
				std::cout << "Количество символов в стеке равно: " << symbols.GetSize() << std::endl;
			PAUSE
				break;
		case 9:
			CLEAN
				if (symbols.IsEmpy()) {
					std::cout << "Стек пуст!" << std::endl;
				}
				else
					std::cout << "В стеке есть елементы!" << std::endl;
			PAUSE
				break;

		}

		break;
	default:
		break;
	}
}
extern void menu() {
	int n = 4; // для перехода по строкам меню
	//////////
	CLEAN
		cout << "+-----------------------------------------------------------------------------------------+" << endl << "|";
	cout.width(50);
	cout << "Меню";
	cout.setf(ios::right);
	cout.width(40);
	cout << "|" << endl;
	cout << "+-----------------------------------------------------------------------------------------+" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "1. Ввод до эталонного символа(По умолчанию равен '/n');" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "2. Вывод строки;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "3. Изменить эталонный символ;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "4. Отчистить строку(эталонный символ не меняется);" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "5. Количество символов в стеке строк" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "6. Пустой ли стек?" << endl;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
}
