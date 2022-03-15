#include"Stack.h"

int main() {
	setlocale(0, "RUS");

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY); //цвет текста основного
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	SetConsoleTitle(L"StackSymbol");

	ConsoleCursorVisible(false, 100); //убираем курсор в консоли
	Stack str;
	while (true)
	{
		CLEAN
			menu();
		pointer(str);
	}
	return 0;
}